// pins apo ais8hthres

const int trigPinF = 10; //front sensor trigger
const int echoPinF = 11; //front sensor reciever
const int trigPinR = 8;  //right sensor trigger
const int echoPinR = 7;  //right sensor reciever
const int trigPinL = 13; //left sensor trigger
const int echoPinL = 12; //left sensor reciever


//pins apo motors
const int mtrRbackward = 2;  //Right motor backward
const int mtrRforward = 3;  //Right motor forward
const int mtrRPWM = 6;      //speed pwm Right motor
const int mtrLbackward = 4;  //left motor backward
const int mtrLforward = 5;  //left motor  forward
const int mtrLPWM = 9 ;    //speed pwm left motor

// defines variables
long duration;
int distance;
bool CH = false;

void setup() {
  pinMode(mtrRbackward, OUTPUT);
  pinMode(mtrRforward, OUTPUT);
  pinMode(mtrRPWM, OUTPUT);
  pinMode(mtrLbackward, OUTPUT);
  pinMode(mtrLforward, OUTPUT);
  pinMode(mtrLPWM, OUTPUT);

  pinMode(trigPinF, OUTPUT);                // Sets the trigPin as an Output
  pinMode(echoPinF, INPUT);                 // Sets the echoPin as an Input
  pinMode(trigPinR, OUTPUT);                // Sets the trigPin as an Output
  pinMode(echoPinR, INPUT);                 // Sets the echoPin as an Input
  pinMode(trigPinL, OUTPUT);                 // Sets the trigPin as an Output
  pinMode(echoPinL, INPUT);                 // Sets the echoPin as an Input

  Serial.begin(9600);                       // Starts the serial communication
}







// Create motor functions

void motorsRforward() {

  digitalWrite (mtrRbackward, LOW);
  digitalWrite (mtrRforward, HIGH);
  analogWrite(mtrRPWM, 80);

}

void motorsLforward() {

  digitalWrite (mtrLbackward, LOW);
  digitalWrite (mtrLforward, HIGH);
  analogWrite(mtrLPWM, 80);
}


void motorsRbackward() {

  digitalWrite (mtrRbackward, HIGH);
  digitalWrite (mtrRforward, LOW);
  analogWrite(mtrRPWM, 80);

}


void motorsLbackward() {

  digitalWrite (mtrLbackward, HIGH);
  digitalWrite (mtrLforward, LOW);
  analogWrite(mtrLPWM, 80);

}

void motorsRstop() {

  digitalWrite (mtrRbackward, HIGH);
  digitalWrite (mtrRforward, HIGH);

}


void motorsLstop() {

  digitalWrite (mtrLbackward, HIGH);
  digitalWrite (mtrLforward, HIGH);

}







// Setup movement functions


void right (int duration) {

  motorsRbackward();

  motorsLforward();

  delay (duration);

}


void left (int duration) {

  motorsRforward();

  motorsLbackward();

  delay (duration);

}




void breakRobot()  {

  motorsRstop();

  motorsLstop();

  // delay (duration);

}







// Setup Ultrasonic Sensor distance measuring


//Brosta ais8hthras

int distanceFS() {

  int duration, distanceF;
  digitalWrite(trigPinF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinF, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPinF, LOW);

  duration = pulseIn(echoPinF, HIGH);
  if (duration > 400) {
    distanceF = duration * 0.034 / 2;

    return distanceF;
  }
}


//de3ios ais8hthras

int distanceRS() {

  int duration, distanceR;
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinR, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPinR, LOW);

  duration = pulseIn(echoPinR, HIGH);
  if (duration > 400) {
    distanceR = duration * 0.034 / 2;
    // Serial.print("Duration...   ");
    //Serial.println(duration);

    return distanceR;
  }
}


//aristeros ais8hthras()

int distanceLS() {

  int duration, distanceL;

  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPinL, LOW);

  duration = pulseIn(echoPinL, HIGH);
  if (duration > 400) {
    distanceL = duration * 0.034 / 2;

    return distanceL;
  }
}

int MOdistanceL() {                     //average of 10 reads
  int MOdistanceLS = 0;                 // error exclusion
  for (int i = 0; i < 5; i++) {
    int z = distanceLS();
    if (z > 800) {
      i = i - 1;
    }
    else
    { MOdistanceLS = MOdistanceLS + z;
    }
  }
  MOdistanceLS = MOdistanceLS / 5;
  return MOdistanceLS;
}



int MOdistanceR() {                   //10times average from right
  int MOdistanceRS = 0;
  for (int i = 0; i < 5; i++) {
    int z = distanceRS();
    if (z > 800) {
      i = i - 1;
    }
    else
    { MOdistanceRS = MOdistanceRS + z;
    }
  }
  MOdistanceRS = MOdistanceRS / 5;
  return MOdistanceRS;
}

int MOdistanceF() {                   //10 times average from front
  int MOdistanceFS = 0;
  for (int i = 0; i < 5; i++) {
    int z = distanceFS();
    if (z > 800) {
      i = i - 1;
    }
    else
    { MOdistanceFS = MOdistanceFS + z;
    }
  }
  MOdistanceFS = MOdistanceFS / 5;
  return MOdistanceFS;
}

void loop() {
  int x = 15;                          //distance from object
  int z = MOdistanceR();               //
  int y = MOdistanceF();
  int a = x - 2;
  int b = x + 2;
  //Serial.println(z);
  if (y > x) {                         // if the distance from the front is greater than x

    if (z > a and  z < b) {            // if distance from the from and right +-2
      motorsRforward();                // then move forward
      motorsLforward();
      delay(200);
      breakRobot();

    }
    else if (z >= b) {                 // if distance is greater
      if (CH == true) {
        //Serial.print(CH);
        right(200);
        motorsRforward();
        motorsLforward();
        delay(200);

      }
      else {
        right(200);                    // turn right
        motorsRforward();              // moveforward
        motorsLforward();
        delay(100);
        left(205);
        breakRobot();
      }
    }
    else if (z <= a ) {                //if distance is smaller
      left(200);                       // turn left
      motorsRforward();                // forward
      motorsLforward();
      delay(200);

      breakRobot();
      CH = false;

    }
  }
  else {                               // if the distance from the front is greater  than x
    breakRobot();                      //stop
    if (y <= x ) {                     //till you see the obstacle
      CH = true;
      left(1250);
      breakRobot();
      y = MOdistanceF();
      z = MOdistanceR();
    }
  }
}

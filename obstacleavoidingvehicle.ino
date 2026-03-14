// pins apo ais8hthres

const int trigPinF = 10; //brosta ais8hthras
const int echoPinF = 11; //brosta ais8hthras
const int trigPinR = 8;  //de3ios ais8hthras
const int echoPinR = 7;  //de3ios ais8hthras
const int trigPinL = 13; //aristeros ais8hthras
const int echoPinL = 12; //aristeros ais8hthras


//pins apo motors
const int mtrRbackward = 2;  //de3ios kinhthras kinhsh brosta
const int mtrRforward = 3;  //de3ios kinhthras kinhsh pisw
const int mtrRPWM = 6;      //taxuthta pwm de3iou kinhthtra
const int mtrLbackward = 4;  //aristeros kinhthras kinhsh brosta
const int mtrLforward = 5;  //aristreos kinhthras kinhsh pisw
const int mtrLPWM = 9 ;    //taxuthta pwm aristerou kinhthra

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

int MOdistanceL() {                     //metraei 10 fores thn apostash apo ta aristera kai vgazei ton meso oro
  int MOdistanceLS = 0;                 // to ekana gia na mhn lamvanoume ypopsh periptoseis pou o aisthhthras metraei laths
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



int MOdistanceR() {                   //metraei 10 fores thn apostash apo ta deksia
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

int MOdistanceF() {                   //metraei 10 fores thn apostash apo ta mprosta
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
  int x = 15;                          //h apostash pou tha krataei apo ton toixo
  int z = MOdistanceR();               //vazo to apotelesma ton synarthseon mesa se metavlhtes gia na mporo na ta xreisimopoihso sto if
  int y = MOdistanceF();
  int a = x - 2;
  int b = x + 2;
  //Serial.println(z);
  if (y > x) {                         // an h apostash apo mprosta einai megalhterh apo to x tote

    if (z > a and  z < b) {            // an h apostash apo deksia einai ish me x(2 pano 2 kato)
      motorsRforward();                // tote proxora mrposta
      motorsLforward();
      delay(200);
      breakRobot();

    }
    else if (z >= b) {                 // allios an h apostash einai megalyterh
      if (CH == true) {
        //Serial.print(CH);
        right(200);
        motorsRforward();
        motorsLforward();
        delay(200);

      }
      else {
        right(200);                    // stripse ligo deksia
        motorsRforward();              // tote proxora mrposta
        motorsLforward();
        delay(100);
        left(205);
        breakRobot();
      }
    }
    else if (z <= a ) {                //allios an h apostash einai mikroterh
      left(200);                       // stripse ligo aristera
      motorsRforward();                // tote proxora mrposta
      motorsLforward();
      delay(200);

      breakRobot();
      CH = false;

    }
  }
  else {                               // an h apostash apo mprosta den einai megalhterh tou x
    breakRobot();                      //stamata
    if (y <= x ) {                     //mexri na dei to empodio pou exei mprosta apo ton deksia aisthhthra strive aristera
      CH = true;
      left(1250);
      breakRobot();
      y = MOdistanceF();
      z = MOdistanceR();
    }
  }
}

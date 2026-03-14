const int IN1 = 10; //left motor backward
const int IN2 = 11; //left motor forward

const int IN3 = 5;  //right motor backward
const int IN4 = 6;  //right motor forward

const int FS = A0;              //Front sensor
const int RS = A1;              //right sensor
const int LS = A2;              //left sensor

const int trigPin = 2;          //casting frequency
const int echoPin = 3;          //reciever

const int  btnSF = 9;         // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

const int led = 7;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button


void setup()
{
  pinMode(led,OUTPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(FS,  INPUT);
  pinMode(LS,  INPUT);
  pinMode(RS,  INPUT);

  pinMode(trigPin, OUTPUT);                
  pinMode(echoPin, INPUT); 

 //slowLeft(3000);

// Serial.begin(9600);
  
}



void fireEx (){
  digitalWrite(led,HIGH);
  delay(3000);
  digitalWrite(led,LOW);  
}

// Create motor functions

void motorRforward(){
  //right motor
  analogWrite(IN3, LOW);        //backward
  analogWrite(IN4, 100);        //forward  
  
}

void motorLforward(){
  //left motor
  analogWrite(IN1, LOW);         //backward
  analogWrite(IN2, 100);        //forward
}

void motorRbackward(){
   //right motor
  analogWrite(IN3, 100);         //backward
  analogWrite(IN4, LOW);        //forward  
}

void motorLbackward() {
  //left motor
  analogWrite(IN1, 100);         //backward
  analogWrite(IN2, LOW);        //forward
}

void motorRstop() {

   //right motor
  analogWrite(IN3, LOW);         //backward
  analogWrite(IN4, LOW);        //forward

}

void motorLstop() {

  //left motor
  analogWrite(IN1, LOW);         //backward
  analogWrite(IN2, LOW);        //forward

}

// Setup movement functions

void forward(int duration){
  motorRforward();
  motorLforward();
  delay(duration);
}

void right (int duration) {

  motorRbackward();
  motorLforward();
  delay (duration);

}
void left (int duration) {

  motorRforward();
  motorLbackward();
  delay (duration);

}

void slowLeft(int duration){
   //left motor
  analogWrite(IN1, 80);         //backward
  analogWrite(IN2, LOW);        //forward

  //right motor
  analogWrite(IN3,LOW);         //backward
  analogWrite(IN4,80);          //forward 

  delay (duration);
  
}

void breakRobot()  {

  motorRstop();
  motorLstop();
// delay (duration);

}

// Setup Ultrasonic Sensor distance measuring


//Brosta ais8hthra


int distanceFS() {

  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  if (duration > 400) {
    distance = duration * 0.034 / 2;

    return distance;
  }
}

  int MOdistanceF() {                   //counts 5 times the distance from the front
  int MOdistanceFS = 0;
  for (int i = 0; i < 5; i++) {
    int z = distanceFS();
    if (z > 400 or z <=0) {
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
  
int FSvalue = analogRead(FS);
int LSvalue = analogRead(LS);
int RSvalue = analogRead(RS);

int x = 15;                       //distance from obstacle
int y = MOdistanceF();            //distance mod


  


 if (FSvalue < 900 and y>x )
 {              
    forward(100);
    delay(100);
    breakRobot();
    
    
    
  }


else if (RSvalue < 900){
  left(100);
  delay(100);
  breakRobot();
  }

else if (LSvalue < 900){
  right(100);
  delay(100);
  breakRobot();
 }

 else {
 breakRobot() ;     
  
 }

}

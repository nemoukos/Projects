#include <Wire.h>                   //eisagoume vivliothikes gia ta hlektronika e3arthmata
#include "Adafruit_MCP9808.h"       //ais8hthras thermokrasias
#include <ShiftRegister74HC595.h>   //aparithmiths


// this constant won't change:
int outputA =6;           //exodos apo A thermostath
int outputB =7;           //exodos apo B thermostath
int ledPOWER = 9;         //led reumatos
int ledON = 8;            //led leitourgeias
int buttonPin=10;         //koubi allaghs
bool bPress = false;

// Variables will change:

int buttonPushCounter=0;      //metrhths apo koubi
int buttonState=0;
int lastButtonState=0;
int counter=0;                //metrhths apo thermostath
int aState;
int aLastState;


// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (4, 2, 3, 4);       //dhmiourgeia ari8mwn gia apeikonish 

int value,digit1,digit2,digit3,digit4; 
uint8_t  number0[] = {B11000000}; //0
uint8_t  number1[] = {B11111001}; //1 
uint8_t  number2[] = {B10100100}; //2
uint8_t  number3[] = {B10110000}; //3 
uint8_t  number4[] = {B10011001}; //4
uint8_t  number5[] = {B10010010}; //5
uint8_t  number6[] = {B10000010}; //6
uint8_t  number7[] = {B11111000}; //7
uint8_t  number8[] = {B10000000}; //8
uint8_t  number9[] = {B10010000}; //9
                     



void setup()

{

  Serial.begin(9600);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
  pinMode( buttonPin , INPUT_PULLUP );
  analogWrite(ledPOWER,100);
  
  aLastState = digitalRead(outputA);
  
  if (!tempsensor.begin()) {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
 
  // Create the MCP9808 temperature sensor object
  Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();
}





void loop(){
  buttonState = digitalRead(buttonPin);

   // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is HIGH then the button went from off to on:
      bPress = true;
      buttonPushCounter++;
      if( buttonPushCounter > 9) buttonPushCounter =0 ;
     
    
    } else {
      
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  

 aState = digitalRead(outputA);

if (aState != aLastState){
  if (digitalRead(outputB) != aState){
     counter ++;  
     
    
    } else {
       counter --;
       

    }
}

aLastState = aState;
 
 int temp = tempsensor.readTempC() - 3 ;//diavazei thn thermokrasia
 

 if(counter > 0){
 if(buttonPushCounter == 0 or buttonPushCounter == 2 or buttonPushCounter == 4 or buttonPushCounter== 6 or buttonPushCounter or buttonPushCounter == 8){
 if(counter==1){ 
    uint8_t numberToPrint[]= {number0[digit4],number1[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==2){ 
    uint8_t numberToPrint[]= {number0[digit4],number2[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==3){ 
    uint8_t numberToPrint[]= {number0[digit4],number3[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==4){ 
    uint8_t numberToPrint[]= {number0[digit4],number4[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==5){ 
    uint8_t numberToPrint[]= {number0[digit4],number5[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==6){ 
    uint8_t numberToPrint[]= {number0[digit4],number6[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==7){ 
    uint8_t numberToPrint[]= {number0[digit4],number7[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==8){ 
    uint8_t numberToPrint[]= {number0[digit4],number8[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==9){ 
    uint8_t numberToPrint[]= {number0[digit4],number9[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==10){ 
    uint8_t numberToPrint[]= {number1[digit4],number0[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==11){ 
    uint8_t numberToPrint[]= {number1[digit4],number1[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==12){ 
    uint8_t numberToPrint[]= {number1[digit4],number2[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==13){ 
    uint8_t numberToPrint[]= {number1[digit4],number3[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==14){ 
    uint8_t numberToPrint[]= {number1[digit4],number4[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==15){ 
    uint8_t numberToPrint[]= {number1[digit4],number5[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==16){ 
    uint8_t numberToPrint[]= {number1[digit4],number6[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==17){ 
    uint8_t numberToPrint[]= {number1[digit4],number7[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==18){ 
    uint8_t numberToPrint[]= {number1[digit4],number8[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==19){ 
    uint8_t numberToPrint[]= {number1[digit4],number9[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==20){ 
    uint8_t numberToPrint[]= {number2[digit4],number0[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==21){ 
    uint8_t numberToPrint[]= {number2[digit4],number1[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==22){ 
    uint8_t numberToPrint[]= {number2[digit4],number2[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==23){ 
    uint8_t numberToPrint[]= {number2[digit4],number3[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==24){ 
    uint8_t numberToPrint[]= {number2[digit4],number4[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==25){ 
    uint8_t numberToPrint[]= {number2[digit4],number5[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==26){ 
    uint8_t numberToPrint[]= {number2[digit4],number6[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==27){ 
    uint8_t numberToPrint[]= {number2[digit4],number7[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==28){ 
    uint8_t numberToPrint[]= {number2[digit4],number8[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==29){ 
    uint8_t numberToPrint[]= {number2[digit4],number9[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==30){ 
    uint8_t numberToPrint[]= {number3[digit4],number0[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==31){ 
    uint8_t numberToPrint[]= {number3[digit4],number1[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==32){ 
    uint8_t numberToPrint[]= {number3[digit4],number2[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==33){ 
    uint8_t numberToPrint[]= {number3[digit4],number3[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==34){ 
    uint8_t numberToPrint[]= {number3[digit4],number4[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==35){ 
    uint8_t numberToPrint[]= {number3[digit4],number5[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==36){ 
    uint8_t numberToPrint[]= {number3[digit4],number6[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==37){ 
    uint8_t numberToPrint[]= {number3[digit4],number7[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==38){ 
    uint8_t numberToPrint[]= {number3[digit4],number8[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==39){ 
    uint8_t numberToPrint[]= {number3[digit4],number9[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(counter==40){ 
    uint8_t numberToPrint[]= {number4[digit4],number0[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 }
 if (counter >= temp){
  analogWrite(ledON,200);
}
 else if(counter < temp){
  analogWrite(ledON,0);
}
}

if (temp > 9){
if (buttonPushCounter == 1 or buttonPushCounter == 3 or buttonPushCounter ==5 or buttonPushCounter == 7 or buttonPushCounter ==9){
 if(temp==0){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==1){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number1[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==2){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number2[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==3){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number3[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==4){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number4[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==5){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number5[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==6){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number6[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==7){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number7[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==8){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number8[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==9){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number0[digit2],number9[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==10){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }
 if(temp==11){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number1[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==12){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number2[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==13){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number3[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==14){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number4[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==15){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number5[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==16){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number6[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==17){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number7[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==18){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number8[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==19){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number1[digit2],number9[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==20){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==21){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number1[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==22){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number2[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==23){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number3[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==24){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number4[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==25){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number5[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==26){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number6[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==27){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number7[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==28){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number8[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==29){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number2[digit2],number9[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==30){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==31){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number1[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==32){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number2[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==33){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number3[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==34){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number4[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==35){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number5[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==36){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number6[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==37){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number7[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==38){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number8[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==39){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number3[digit2],number9[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==40){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number4[digit2],number0[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==41){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number4[digit2],number1[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==42){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number4[digit2],number2[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==43){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number4[digit2],number3[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==44){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number4[digit2],number4[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==45){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number4[digit2],number5[digit1]};
    sr.setAll(numberToPrint); 
 }

 if(temp==46){ 
    uint8_t numberToPrint[]= {number0[digit4],number0[digit3],number4[digit2],number6[digit1]};
    sr.setAll(numberToPrint); 
 }
}
if (counter >= temp){
  analogWrite(ledON,200);
}
 else if(counter < temp){
  analogWrite(ledON,0);
}
 }
    
 
}

 

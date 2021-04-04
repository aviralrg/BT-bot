  /*
  BT-Bot

  Bluetooth Controlled Robot.
  Moves based on commands received from the Blutooth terminal connected to HC-O5 Blutooth Module 

  This Design was developed using Arduino UNO, HC-05 Bluetooth module, H-bridge (L293D) for motor control

  Pins connections can be found on README of https://github.com/aviralrg/BT-bot:
  

  modified 4 April 2021
  by Aviral Gupta

  This example code is in the public domain.
*/
  #define LP PD5 // Positive terminal of the Left motor
  #define LN PD4 // Negetive terminal of the Left motor
  #define RP PD6 // Positive terminal of the Right motor
  #define RN PD7 // Negative terminal of the Right motor


#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 

enum {
  FORWARD = 56,//ASCII value for '8'
  LEFT = 52,//ASCII value for '4'
  RIGHT = 54,//ASCII value for '6'
  STOP = 53,//ASCII value for '5'
  REVERSE = 50//ASCII value for '2'
};

void forward();
void motion_stop();
void left();
void right();
void reverse();

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LN, OUTPUT);
  pinMode(RN, OUTPUT);
  motion_stop();        
//  Serial.begin(9600);
  MyBlue.begin(9600); 
}

// the loop function runs over and over again forever
void loop() {
  byte a = STOP;
  
 //from bluetooth to Terminal. 
 while (MyBlue.available() == 0);
  a = MyBlue.read();
//  Serial.println(a);
  switch (a)
  {
    case FORWARD:
      forward();
      break;

    case LEFT:
      left();
      break;

    case RIGHT:
      right();
      break;

    case REVERSE:
    
      reverse();
      break;
    case STOP:
      motion_stop();
      break;
      
    default:
      motion_stop();
      break;
  }
}
void forward() {
  //right forward
  analogWrite(RP, 255 - 64);
  digitalWrite(RN, HIGH);
  //left forward
  analogWrite(LP, 255 - 64);
  digitalWrite(LN, HIGH);
}
void motion_stop() {
  //right stop
  analogWrite(RP, 255);
  digitalWrite(RN, HIGH);
  //left stop
  analogWrite(LP, 255);
  digitalWrite(LN, HIGH);
}
void left() {
  //right forward
  analogWrite(RP, 255 - 64);
  digitalWrite(RN, HIGH);
  //left stop
  analogWrite(LP, 255);
  digitalWrite(LN, HIGH);
}
void right() {
  //right stop
  analogWrite(RP, 255);
  digitalWrite(RN, HIGH);
  //left forward
  analogWrite(LP, 255 - 64);
  digitalWrite(LN, HIGH);
}
void reverse() {
  //right backward
  analogWrite(RP, 64);
  digitalWrite(RN, LOW);
  //left backward
  analogWrite(LP, 64);
  digitalWrite(LN, LOW);
}

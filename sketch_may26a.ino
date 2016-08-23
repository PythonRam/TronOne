#define EnA 7
#define EnB 8
#define txPin 9
#define rxPin 10
#define CheckPin 13
#define MotorA1 A0
#define MotorA2 A1
#define MotorB1 A4
#define MotorB2 A5

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins

SoftwareSerial mySerial(rxPin, txPin);
char ch;
char dir;
 void setup() {
  pinMode(MotorA1,OUTPUT);
  pinMode(MotorA2,OUTPUT);
  
  pinMode(MotorB1,OUTPUT);
  pinMode(MotorB2,OUTPUT);
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  pinMode(CheckPin,OUTPUT);
  
  Serial.begin(9600);   
  Serial.println("Goodnight moon!");
 
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

void loop() 
{

  if(mySerial.available())
  { 
      
  dir=mySerial.read();
  
   
  switch(dir)
  {
    case '1': forward(); digitalWrite(CheckPin,HIGH);delay(100); break;
    case '2': left(); digitalWrite(CheckPin,HIGH); delay(100); break;
    case '3': back(); digitalWrite(CheckPin,HIGH); delay(100); break;
    case '4': right();digitalWrite(CheckPin,HIGH); delay(100); break;
    case '5': noMove();digitalWrite(CheckPin,HIGH); delay(100);break;
    digitalWrite(CheckPin,LOW);  
  }
  
 }

}
void forward()
{
digitalWrite(EnA,HIGH);
digitalWrite(EnB,HIGH);
digitalWrite(MotorA2,HIGH);
digitalWrite(MotorB1,HIGH);
digitalWrite(MotorA1,LOW);
digitalWrite(MotorB2,LOW);
}
void right()
{
digitalWrite(EnA,HIGH);
digitalWrite(EnB,HIGH);
digitalWrite(MotorA2,LOW);
digitalWrite(MotorB1,HIGH);
digitalWrite(MotorA1,HIGH);
digitalWrite(MotorB2,LOW);
}
void left()
{
digitalWrite(EnA,HIGH);
digitalWrite(EnB,HIGH);
digitalWrite(MotorB1,LOW);
digitalWrite(MotorA2,HIGH);
digitalWrite(MotorB2,HIGH);
digitalWrite(MotorA1,LOW);
}
void back()
{
digitalWrite(EnA,HIGH);
digitalWrite(EnB,HIGH);
digitalWrite(MotorA2,LOW);
digitalWrite(MotorB1,LOW);
digitalWrite(MotorA1,HIGH);
digitalWrite(MotorB2,HIGH);
}
void noMove()
{
  digitalWrite(EnA,LOW);
  digitalWrite(EnB,LOW);

 
  }


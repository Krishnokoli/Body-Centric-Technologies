#include <Wire.h>
#include "Adafruit_MPR121.h"

// Adafruit_MPR121
#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();
// Keeps track of the last pins touched
uint16_t currtouched = 0;
uint16_t lasttouched = 0;
int tp = 12; //change this if you aren't using them all, start at pin 0

int ledPin1 = 12;

int t = 40;
int rnd =5;
int pat1t =75;

int sensor1Pin = A0;
int sensor1Val;

int PinTouched;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

// Adafruit_MPR121
uint16_t currtouched = 0;
uint16_t lasttouched = 0;
int tp = 12; //change this if you aren't using them all, start at pin 0
if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");

 for(int i=3; i<=12; i++) {
   pinMode(i,OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

  //Light Sensor
  sensor1Val = analogRead(sensor1Pin);

  Serial.println(sensor1Val);

  //Adafruit_MPR121
  checkAllPins(12);



  if (sensor1Val < 18)
  {
    if (PinTouched == 11)
    {
    for(int i=0; i<=1; i++) {
    pat4();}
    }
    if (PinTouched == 8)
    {
    for(int i=0; i<=1; i++) {
    pat5();}
    }
  }
}


void checkAllPins(int totalPins)
{
  // Get the currently touched pads
  currtouched = cap.touched();
  for (uint8_t i=0; i<totalPins; i++) 
  {
    // it if *is* touched and *wasnt* touched before, send a message
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) )
    {
      PinTouched = i;
      
    }

  
  }
lasttouched = currtouched;
  
}

void pat4(){   
      for(int i=2; i<=12; i++) {
      digitalWrite(i,HIGH);
      delay(70);
    }
        for(int i=12; i>=2; i--) {
      digitalWrite(i,HIGH);
      delay(70);
      digitalWrite(i,LOW);
    }
}

void pat5(){
     for(int i=3; i<=12; i++) {
      digitalWrite(i,HIGH);
      }
    delay(100);
    for(int i=3; i<=12; i++) {
      digitalWrite(i,LOW);
      }
    delay(100);  
}

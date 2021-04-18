//Viral Science  www.viralsciencecreativity.com  www.youtube.com/c/viralscience
//LED 8x8 Matrix Display DEMO

#include <LedControl.h>
int DIN = 12;
int CS =  11;
int CLK = 10;

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       
 lc.setIntensity(0,15);      //Adjust the brightness maximum is 15
 lc.clearDisplay(0);

 //Switch
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  //LED
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  //Motor
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(20, OUTPUT);
}

void loop(){ 
  //read the pushbutton value into a variable
  int sensorVal1 = digitalRead(3);
  int sensorVal2 = digitalRead(4);
  int sensorVal3 = digitalRead(5);
  int sensorVal4 = digitalRead(6);
  int sensorVal5 = digitalRead(7);
  
  //print out the value of the pushbutton
  Serial.println(sensorVal1);
  Serial.println(sensorVal2);
  Serial.println(sensorVal3);
  Serial.println(sensorVal4);
  Serial.println(sensorVal5);

  //LED Chakra
    byte muladhara[8]=   
    {  
      B01111110,
      B10000001,
      B10011001,
      B10011001,
      B10111101,
      B10111101,
      B10000001,
      B01111110
      };
  
    byte svadisthana[8]= 
    {
      B00111100,
      B01000010,
      B10011001,
      B10111101,
      B10111101,
      B10011001,
      B01000010,
      B00111100
      };
      
    byte manipura[8]=   
    {
      B01111110,
      B11000011,
      B11111111,
      B10111101,
      B10011001,
      B10011001,
      B11000011,
      B01111110
      };

    byte anahata[8]= 
    {
      B00111100,
      B01011010,
      B10011001,
      B11100111,
      B11100111,
      B10011001,
      B01011010,
      B00111100
      };
      
    byte visuddha[8]=   
    {
      B11111111,
      B10000001,
      B11011011,
      B01011010,
      B01100110,
      B00100100,
      B00111100,
      B00011000
      };
    
    //Alternate Pattern
    byte d1[8]= {0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55};
    byte d2[8]= {0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA};

////alternate pattern
//    printByte(d1);
//    delay(100);
//
//    printByte(d2);
//    delay(100);

   
//Print LED

// Muladhara
  if (sensorVal1 == HIGH) {
    digitalWrite(13, LOW);
  }
  else {
    printByte(muladhara);
    digitalWrite(13, HIGH);
  }

// Svadisthana
  if (sensorVal2 == HIGH) {
    digitalWrite(20, LOW);
  }
  else {
    printByte(svadisthana);
    digitalWrite(20, HIGH);
  }

// Manipura
  if (sensorVal3 == HIGH) {
    digitalWrite(16, LOW);
  }
  else {
    printByte(manipura);
    digitalWrite(16, HIGH);   
  }

// Anahata
  if (sensorVal4 == HIGH) {
    digitalWrite(18, LOW);
  }
  else {
    printByte(anahata);
    digitalWrite(18, HIGH);
  }  

  if (sensorVal5 == HIGH) {
    digitalWrite(14, LOW);
  }
  else {
    printByte(visuddha);
    digitalWrite(14, HIGH);
  } 
}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

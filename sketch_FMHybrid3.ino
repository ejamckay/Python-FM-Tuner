

#include <math.h>
# include <float.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial sserial(1,2);
// RADIO TEA5767sk 
// This is a sketch to manage the TEA5767 chip - and FM on chip
// With ths sketch you can set frequency reaf PLL/freq, seek frequency/
String  s ;
boolean stringComplete = false;  // whether the string is complete
float myString; 
int frequencyB;
int frequencyH;
int frequencyL;
int counter =0;
int freqCounter = 0;
float  freqArray[101];
float frequency;
float freq=87.7;
float float_temp[6];
static char outstr[15];
// Programmed by Eddie Arnold : Email - ejalogic12@aol.com

//**********************************************************
 //**********************************************************



void setup() {
  
  // initialize serial:
  sserial.begin(9600);
 Serial.begin(9600);
 while(! Serial)
 {
  ;
}
do {
            freq = freq + 0.2;
                  
            freqArray[freqCounter] =freq ;
freq;  
            freqCounter = freqCounter + 1;

        } while (freqCounter < 101);
 
}
 
void loop()
{

if(sserial.available() > 0)
{

  
 byte incomingByte = sserial.read();

  if(incomingByte != -1){
  
  



 

 

 frequency=freqArray[char(incomingByte)];

setFrequency();


  }
  
   
}
}

void setFrequency()  {
  
    
  
      frequencyB=4*(frequency*1000000+225000)/32768; //calculating PLL word
     
      frequencyH=frequencyB>>8;
     
      frequencyL=frequencyB&0XFF;
     
      delay(100);
     
      Wire.beginTransmission(0x60);   //writing TEA5767
     
      Wire.write(frequencyH);
      Wire.write(frequencyL);
      Wire.write(0xB0);
      Wire.write(0x10);
      Wire.write(0x00);
      Wire.endTransmission();
     Wire.begin(); 
      delay(100);
} 

#define seven_datapin 2
#define seven_clk 4
#define seven_latch 3
#include "uRTCLib.h"
uRTCLib rtc(0x68);
byte seven_seg_data;
int year ;
int month ;
int day ;
int hour ;
int minute ; 
int sec ; 
int temp;
#define segA 5
#define segB 6
#define segC 7
#define segD 8
#define segE 9
#define segF 10
#define segG 11
#define blink 13


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    delay(3000); 
    URTCLIB_WIRE.begin();
    // rtc.set(0, 59, 23, 5, 30, 10, 23);
    pinMode(seven_datapin,OUTPUT);
    pinMode(seven_clk,OUTPUT);
    pinMode(seven_latch,OUTPUT);
    pinMode(segA, OUTPUT);
    pinMode(segB, OUTPUT);
    pinMode(segC, OUTPUT);
    pinMode(segD, OUTPUT);
    pinMode(segE, OUTPUT);
    pinMode(segF, OUTPUT);
    pinMode(segG, OUTPUT);
    pinMode(blink, OUTPUT);

}

void loop(){
  
  rtc.refresh();
  year = rtc.year();
  month = rtc.month();
  day = rtc.day();
  hour = rtc.hour();
  minute = rtc.minute();
  sec = rtc.second();
  temp = 25; 
  if(hour == 13){
    hour = 1;
  }  
  else if(hour == 14){
    hour = 2;
  }
  else if(hour == 15){
    hour = 3;
  }
  else if(hour == 16){
    hour = 4;
  }
  else if(hour == 17){
    hour = 5;
  }else if(hour == 18){
    hour = 6;
  }
  else if(hour == 19){
    hour = 7;
  }
  else if(hour == 20){
    hour = 8;
  }
  else if(hour == 21){
    hour = 9;
  }
  else if(hour == 22){
    hour = 10;
  }
  else if(hour == 23){
    hour = 11;
  }
  else if(hour == 0){
    hour = 12;
  }
  bool blinkState = sec  % 2 == 0;
  setblink(blinkState);

  
   digitalWrite(seven_latch, LOW);
   lightNumber(hour/10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b10000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(hour%10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b01000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(minute/10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00100000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(minute%10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00010000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(sec/10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00001000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(sec%10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000100);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   //Date 

   digitalWrite(seven_latch, LOW);
   lightNumber(day/10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b10000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(day%10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b01000000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(month/10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00100000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(month%10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00010000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(2);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00001000);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(0);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000100);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(year/10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000010);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

   digitalWrite(seven_latch, LOW);  
   lightNumber(year%10);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000001);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);
   delay(2);

   digitalWrite(seven_latch, LOW);  
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   shiftOut(seven_datapin,seven_clk,LSBFIRST,0b00000000);
   digitalWrite(seven_latch, HIGH);

 }

void lightNumber(int numberTodisplay){
  switch(numberTodisplay){
case 0:
   digitalWrite(segA,LOW);
   digitalWrite(segB,LOW);
   digitalWrite(segC,LOW);
   digitalWrite(segD,LOW);
   digitalWrite(segE,LOW);
   digitalWrite(segF,LOW);
   digitalWrite(segG,HIGH);
     break;   
  case 1:
   digitalWrite(segA,HIGH);
   digitalWrite(segB,LOW);
   digitalWrite(segC,LOW);
   digitalWrite(segD,HIGH);
   digitalWrite(segE,HIGH);
   digitalWrite(segF,HIGH);
   digitalWrite(segG,HIGH);
    break; 
  case 2:
   digitalWrite(segA,LOW);
   digitalWrite(segB,LOW);
   digitalWrite(segC,HIGH);
   digitalWrite(segD,LOW);
   digitalWrite(segE,LOW);
   digitalWrite(segF,HIGH);
   digitalWrite(segG,LOW);
    break;
  case 3:
   digitalWrite(segA,LOW);
   digitalWrite(segB,LOW);
   digitalWrite(segC,LOW);
   digitalWrite(segD,LOW);
   digitalWrite(segE,HIGH);
   digitalWrite(segF,HIGH);
   digitalWrite(segG,LOW);
    break;
 case 4:
   digitalWrite(segA,HIGH);
   digitalWrite(segB,LOW);
   digitalWrite(segC,LOW);
   digitalWrite(segD,HIGH);
   digitalWrite(segE,HIGH);
   digitalWrite(segF,LOW);
   digitalWrite(segG,LOW);
    break;
 case 5:
   digitalWrite(segA,LOW);
   digitalWrite(segB,HIGH);
   digitalWrite(segC,LOW);
   digitalWrite(segD,LOW);
   digitalWrite(segE,HIGH);
   digitalWrite(segF,LOW);
   digitalWrite(segG,LOW);
    break;
 case 6:
   digitalWrite(segA,LOW);
   digitalWrite(segB,HIGH);
   digitalWrite(segC,LOW);
   digitalWrite(segD,LOW);
   digitalWrite(segE,LOW);
   digitalWrite(segF,LOW);
   digitalWrite(segG,LOW);
   break;
 case 7:
   digitalWrite(segA,LOW);
   digitalWrite(segB,LOW);
   digitalWrite(segC,LOW);
   digitalWrite(segD,HIGH);
   digitalWrite(segE,HIGH);
   digitalWrite(segF,HIGH);
   digitalWrite(segG,HIGH);
  break;
 case 8:
   digitalWrite(segA,LOW);
   digitalWrite(segB,LOW);
   digitalWrite(segC,LOW);
   digitalWrite(segD,LOW);
   digitalWrite(segE,LOW);
   digitalWrite(segF,LOW);
   digitalWrite(segG,LOW);
    break;
 case 9:
   digitalWrite(segA,LOW);
   digitalWrite(segB,LOW);
   digitalWrite(segC,LOW);
   digitalWrite(segD,LOW);
   digitalWrite(segE,HIGH);
   digitalWrite(segF,LOW);
   digitalWrite(segG,LOW);
   break; 
  
  }}
  void setblink(bool value) {
  digitalWrite(blink, value ? LOW : HIGH);
}

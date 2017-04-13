// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
RTC_DS1307 RTC;


int led = 9;
int PT = 8;
int sensorPin = 0; //analog pin 0

void setup () {
    Serial.begin(9600);
    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    Wire.begin();
    RTC.begin();
    pinMode(led, OUTPUT);  
    pinMode(PT, OUTPUT);
     
}
void loop () {  
 
  DateTime now = RTC.now();
    lcd.setCursor(0, 0);
    //lcd.print(now.year(), DEC);
    //lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
    lcd.print(' ');
    lcd.setCursor(7, 0);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
    
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(PT, HIGH);
    int val = analogRead(sensorPin);
    lcd.setCursor(0, 1);
    lcd.print("OBS=  ");
    lcd.print("   ");
    lcd.setCursor(6,1);
    lcd.print(val);
    
    //just to slow down the output - remove if trying to catch an object passing by
    delay(100);
    
}

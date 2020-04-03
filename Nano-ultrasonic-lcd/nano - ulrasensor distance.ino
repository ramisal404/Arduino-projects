

#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);


const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   lcd.init();
       // Print a message to the LCD.
    lcd.backlight();
}

void loop() {


   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   lcd.setCursor(0,0); 
   lcd.print("Distance: ");
   lcd.print(cm);
   lcd.print(" cm");
   lcd.print("  ");
   lcd.setCursor(0,1);
   lcd.print("       ");
   lcd.print(inches);
   lcd.print(" inches");
   lcd.print("  ");
  delay(100);
   
   
   //Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
   //Serial.print("cm");
  // Serial.println();
  // delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
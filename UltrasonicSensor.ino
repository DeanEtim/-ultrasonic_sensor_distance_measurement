/*
  A sketch to demonstrate how the Ultrasonic sensor
  can be used to measure distance
  Created By: Engr. Dean Etim
  Date: 7th December, 2024.
*/
// Include all the necessary Libraries
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonic sensor Pins
int trig = 6;
int echo = 3;

// led pins
const int redLed = 7;
const int blueLed = 8;

// variables for holding duration and distance
long duration;
float distance_cm;

void setup() {
  // Initialization
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  //pin mode for the led pins
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  //pin mode for the sensor pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Welcome message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance Meter");
  delay(2000);
}

void loop() {
  // Send out the ultrasonic signal
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Receive the incoming signal
  duration = pulseIn(echo, HIGH);

  // Calculate and display the distance
  distance_cm = (duration / 58.82);
  Serial.print("Distance (in cm) = ");
  Serial.println(distance_cm);

  // Display on the LCD
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("distance: ");
  lcd.print(distance_cm);
  lcd.print("distance: ");

  // Condtional Statements
  if (distance_cm <= 10.0) {
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    delay(200);
  } 
  
  else if (distance_cm >= 20.0) {
    digitalWrite(blueLed, HIGH);
    digitalWrite(redLed, LOW);
    delay(200);
  } 
  
  else {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
  }
}

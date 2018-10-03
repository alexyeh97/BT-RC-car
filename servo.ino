// Program to test the servo
//
// Prints the position of the servo
//  and sweeps from 0 to 180 degrees
//  and sweeps back from 180 to 0 degrees
//
//  Arduino to servo connections
//  Arduino 5V to VCC (red wire) of servo
//  Arduino digital PWM pin 9 to SIG (orange or white wire) of servo
//  Connect GND from the Arduino to GND (black wire) of the servo



// Import Arudino's Servo library
#include <Servo.h>

#define BAUDRATE 9600

#define servo_pin 5

Servo servo;

void setup() {

  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);

  // Attach servo pin to Servo object  
  servo.attach(servo_pin);
}

void loop() { 

  // Sweep from 0 to 180 degrees
  for(int i = 0; i <= 180; i++) {
    Serial.print("position=");
    servo.write(i);
    Serial.println(i);
    delay(5);
  }
  delay(500);

  // Sweep from 180 to 0 degrees
  for(int i=180; i >= 0; i--) {
    Serial.print("position=");
    servo.write(i);
    Serial.println(i);
    delay(5); 
  }
  delay(500);
}

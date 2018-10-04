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
// Arduino A0 connected to Y of thumbstickA



// Import Arudino's Servo library
#include <Servo.h>

#define BAUDRATE 9600

#define servo_pin 5

#define thumbstick_pin A0 
int thumbstick_neutral=337;
int thumbstick_min=0;
int thumbstick_max=675;
int thumbstick_pos;
int servo_pos;


Servo servo;

void setup() {

  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);

  // Attach servo pin to Servo object  
  servo.attach(servo_pin);
}

void loop() { 
  //read thumbstick position, map thumbstick position to servo position
  //write position to servo
  //print both to serial
  thumbstick_pos = analogRead(thumbstick_pin);
  servo_pos = thumbstick_pos/3.75;
  servo.write(servo_pos);

  Serial.print("(thumbstick,servo)=(");
  Serial.print(thumbstick_pos);
  Serial.print(",");
  Serial.print(servo_pos);
  Serial.println(")");

  delay(10);
}

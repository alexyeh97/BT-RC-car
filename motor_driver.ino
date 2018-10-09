#include <Servo.h>
#define BAUDRATE 9600

// Motor Driver variables
#define enable 6
#define phase 5
#define FORWARD HIGH
#define BACKWARD LOW

//Challenge: Motor Drive with thumbstick
//Challenge2: + servo with steering thumbstick
//Arduino A2 connected to X of throttle
//establish neutral zone to be 336 +/- 10
#define throttle_pin A2
#define servo_pin 9
#define steering_pin A0 
int steering_neutral=337;
int steering_min=0;
int steering_max=675;
int steering_pos;
int servo_pos=90;

int throttle_neutral = 337;
int throttle_min = 0;
int throttle_max = 700;
int throttle_pos;
int throttle_forward = 367;
int throttle_reverse = 307;
int motor;

Servo servo;

void setup() {
  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);

  // Set phase (digital) pin as an output
  pinMode(phase, OUTPUT);

  // Set initial condition for motor driver
  digitalWrite(phase, FORWARD);
  analogWrite(enable, 0);

  // Attach servo pin to Servo object  
  servo.attach(servo_pin);
}

void loop() {
  throttle_pos = analogRead(throttle_pin);

  if (throttle_pos >= throttle_forward) {
    digitalWrite(phase, FORWARD);
    motor = map(throttle_pos, throttle_forward, throttle_max, 0, 255);
    analogWrite(enable, motor);
  }

  else if (throttle_pos <= throttle_reverse) {
    digitalWrite(phase, BACKWARD);
    motor = map(throttle_pos, throttle_reverse, throttle_min, 0, 255);
    analogWrite(enable, motor);
  }

else {
  //if (throttle_pos <= throttle_forward && throttle_pos >= throttle_reverse) {
    motor = 0;
    analogWrite(enable,motor);
  }

 steering_pos = analogRead(steering_pin);
 servo_pos = steering_pos/3.75;
 servo.write(servo_pos);

  Serial.print("(throttle_pos)=");
  Serial.print(throttle_pos); 
  Serial.print("   motor=");
  Serial.println(motor);

  delay(10);
   }

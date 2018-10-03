// Program to test the motor driver circuitry
//
// Prints the phase (direction) and enable (speed) of the motor driver
//  Ramps up to max speed, then slows down, in one direction
//  Ramps up to max speed, then slows down, in opposite direction


#define BAUDRATE 9600

// Motor Driver variables
#define enable 9
#define phase 6
#define FORWARD HIGH
#define BACKWARD LOW
#define THROTTLE_MIN 0
#define THROTTLE_MAX 255

void setup() {
  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);

  // Set phase (digital) pin as an output
  pinMode(phase,OUTPUT);

  // Set initial condition for motor driver
  digitalWrite(phase,FORWARD);
  analogWrite(enable,0);
}

void loop() {
  // Sweep motor at phase = FORWARD,
  //  and motor speed at enable steps 0 to 255
  //  speed up 
  digitalWrite(phase,FORWARD);
  for(int i = THROTTLE_MIN; i <= THROTTLE_MAX; i++) {
    analogWrite(enable,i);      
    Serial.print("(phase,enable)=(");
    Serial.print(FORWARD);
    Serial.print(",");
    Serial.print(i);
    Serial.println(")");
    delay(5);
  }
  delay(500);

  // Sweep motor at phase = FORWARD,
  //  and motor speed at enable steps 255 to 0
  //  slow down
  for(int i = THROTTLE_MAX; i >= THROTTLE_MIN; i--) {
    analogWrite(enable,i);        
    Serial.print("(phase,enable)=(");
    Serial.print(FORWARD);
    Serial.print(",");
    Serial.print(i);
    Serial.println(")");
    delay(5);
  }
  delay(500);



  // Sweep motor at phase = BACKWARD,
  //  and motor speed at enable steps 0 to 255
  //  speed up 
  digitalWrite(phase,BACKWARD);
  for(int i = THROTTLE_MIN; i <= THROTTLE_MAX; i++) {
    analogWrite(enable,i);       
    Serial.print("(phase,enable)=(");
    Serial.print(BACKWARD);
    Serial.print(",");
    Serial.print(i);
    Serial.println(")");
    delay(5);
  }
  delay(500);

  // Sweep motor at phase = BACKWARD,
  //  and motor speed at enable steps 255 to 0
  //  slow down
  for(int i = THROTTLE_MAX; i >= THROTTLE_MIN; i--) {
    analogWrite(enable,i);  
    Serial.print("(phase,enable)=(");
    Serial.print(BACKWARD);
    Serial.print(",");
    Serial.print(i);
    Serial.println(")");
    delay(5);
  }
  delay(500);
}

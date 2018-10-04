// Program to test the thumbstick
//
// Prints the X and Y analog readings
//  and the state of the SW (push-button)
//  of the thumbstick to the Serial Monitor
//
//  Arduino to thumbstick connections
//  Arduino 3.3V or 5V to VCC of thumbstick
//  Arduino analog pin A0 to X pin of thumbstick
//  Arduino analog pin A1 to Y pin of thumbstick
//  Arduino digital pin 2 to SW pin of thumbstick
//  Connect GND from the Arduino to GND on the thumbstick
#define BAUDRATE 9600
 
#define thumbstickA_x A0
#define thumbstickA_y A1
#define thumbstickB_x A2
#define thumbstickB_y A3
#define thumbstick_sw 2
int raw_analog_reading;
int switch_state;
 
void setup() {
  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);
}
// Continuously print the X reading of thumbstickA
// and the Y reading of thumbstickB
void loop() { 
  Serial.print("(thumbstickA_Y, thumbstickB_X)=");
  Serial.print("(");
  // Read + print thumbstickA Y
  raw_analog_reading = analogRead(thumbstickA_y);
  Serial.print(raw_analog_reading);
  Serial.print(",");
  // Read + print thumbstickB X
  raw_analog_reading = analogRead(thumbstickB_x);
  Serial.print(raw_analog_reading);
  Serial.println(")");
  delay(10);
}


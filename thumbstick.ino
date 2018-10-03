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

#define thumbstick_x A0
#define thumbstick_y A1
#define thumbstick_sw 2

int raw_analog_reading;
int switch_state;
 
void setup() {

  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);

  // Configure with internal pull-up resistor
  //  so we do not need a physical pull-down resistor
  pinMode(thumbstick_sw, INPUT_PULLUP);
}

// Continuously print the X and Y analog readings 
//  and the state of the push-button of the thumbstick
void loop() { 
  Serial.print("(X,Y,isPressed)=");

  Serial.print("(");

  // Read + print thumbstick X
  raw_analog_reading = analogRead(thumbstick_x);
  Serial.print(raw_analog_reading);

  Serial.print(",");

  // Read + print thumbstick Y
  raw_analog_reading = analogRead(thumbstick_y);
  Serial.print(raw_analog_reading);

  Serial.print(",");

  // Read + print thumbstick switch state
  //  Note: We invert the reading because of the internal pullup resistor
  switch_state = !digitalRead(thumbstick_sw);
  Serial.print(switch_state);

  Serial.println(")");

  delay(10);
}

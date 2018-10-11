//Reads sensor data and transmits them to receiver
// Library to make a Software UART
//HM-10 module A (master)
//Name: REMOTE
//MAC Addr.: 341513E6475C
//
//HM-10 module B (slave)
//Name: VEHICLE
//MAC Addr.: D43639DEAFAD
#include <SoftwareSerial.h>

#define TX 2
#define RX 3
#define throttle_pin A2
#define steering_pin A0

 
SoftwareSerial BTSerial(RX, TX); // (RX, TX)

#define BAUDRATE 9600

// Struct to hold the data we want to transmit
struct Packet {
  int throttle_pos;
  int steering_pos;
  int checksum;
} pkt; // Instantiate a Packet struct
 
void setup() {
  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);

  // HM-10 virtual UART
  BTSerial.begin(BAUDRATE);  
}
 
void loop() {  
  // Transmit data via bluetooth
  bluetooth_transmit();  

  // Necessary forced delay, if we transmit too fast (no delay)
  //  the error rate increases
  delay(5);
}

// Function responsible for reading senors and 
// transmitting data over bluetooth and checksum
void bluetooth_transmit() {
  // Update data to be transmitted
  pkt.throttle_pos = analogRead(throttle_pin);
  pkt.steering_pos = analogRead(steering_pin);
  pkt.checksum = pkt.steering_pos ^ pkt.throttle_pos;
  // Write packet data to the bluetooth - and transmit
  BTSerial.write((byte *) & pkt,sizeof(Packet));

  // Print packet (debug)
  print_packet();
}

// Function to print packet data (debug)
void print_packet() {  
  Serial.print("TX: (throttle_pos,steering_pos)=(");
  Serial.print(pkt.throttle_pos); Serial.print(",");
  Serial.print(pkt.steering_pos);
  Serial.println(")");
}

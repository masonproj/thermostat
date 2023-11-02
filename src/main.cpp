#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const int RECV_PIN = 23;  // Define the digital pin to which the IR receiver is connected

IRrecv irrecv(RECV_PIN);  // Create an instance of the IRrecv library

decode_results results;  // Create a variable to store the received IR data

void setup()
{
  Serial.begin(115200);   // Initialize the serial communication
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop()
{
  if (irrecv.decode(&results))
  {
    // Print the received IR code to the Serial Monitor
    Serial.print("Received IR Code: 0x");
    Serial.println(results.value, HEX);

    irrecv.resume();  // Continue to receive IR data
  }
}
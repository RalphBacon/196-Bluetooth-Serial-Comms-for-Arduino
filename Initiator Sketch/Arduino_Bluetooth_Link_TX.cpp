// Do not remove the include below
#include "Arduino_Bluetooth_Link_TX.h"
#include <SoftwareSerial.h>

// We're just receiving on GPIO Pin 2
SoftwareSerial sws(2, 3);


void setup()
{
	Serial.begin(9600);
	sws.begin(38400);
	Serial.println("TX Setup Completed.");
}


void loop()
{
	// Simple counter
	static unsigned long counter=0;

	// Send the value via BT
	Serial.print("Sending: ");
	Serial.println(++counter);
	if (counter % 10 == 0) {
		sws.print("Divisible by 10 --> ");
	}
	sws.println(counter);

	// Let's not flood the output
	delay(500);
}

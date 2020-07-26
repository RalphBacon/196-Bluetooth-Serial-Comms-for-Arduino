// Do not remove the include below
#include "Arduino_Bluetooth_Link_RX.h"
#include <SoftwareSerial.h>

// We're just receiving on GPIO Pin 2
SoftwareSerial sws(2, 3);

// Input 'string' goes here
char buffer[100] = { '\0' };
unsigned int bufCnt = 0;

//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	sws.begin(38400);
	Serial.println("Setup completed.");
}

void loop()
{
	if (sws.available())
	{
		// Read the byte of data
		unsigned char btdata = sws.read();

		// End of string?
		if (btdata == 13)
		{
			// Add 'end of string' marker & print it out
			buffer[bufCnt] = '\0';
			Serial.println(buffer);

			// Reset buffer index to start of string
			bufCnt = 0;
		} else
		{
			// If not a line feed (part of the ENTER key)
			if (btdata != 10)
			{
				// Add to string & increment string length counter
				buffer[bufCnt] = (char) btdata;
				bufCnt++;
			}
		}
	}
}

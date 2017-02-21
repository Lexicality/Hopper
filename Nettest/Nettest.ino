/*
 Name:		Nettest.ino
 Created:	2/18/2017 10:21:09 PM
 Author:	Lex
*/

#include <Ethernet.h>

// Copied from the bottom of the board
byte mac[] = { 0x00, 0x1A, 0xB6, 0x02, 0xCB, 0x52 };

EthernetClient client;

void setup() {
	Serial.begin(9600);
	Serial.println("=============================");

	if (Ethernet.begin(mac) == 0) {
		Serial.println("Init Ethernet failed");
		while (true);
	}

	Serial.print("Ethernet address: ");
	Serial.println(Ethernet.localIP());


	Serial.println("Connecting...");
	if (client.connect("172.31.24.207", 8081) == 1) {
		Serial.println("Connected");
		client.println("Hello World!");
	} else {
		Serial.println("Not Connected");
	}

	Serial.println("We survived the bootup sequence!");
}

bool oops = false;

void loop() {
	if (client.available()) {
		char c = client.read();
		Serial.print(c);
	}

	if (!client.connected() && !oops) {
		oops = true;
		Serial.println("DED");
	}
}

/*
// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(D1_LED, OUTPUT);
	pinMode(D2_LED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	client.monitor();
}

*/
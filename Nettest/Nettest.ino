/*
 Name:		Nettest.ino
 Created:	2/18/2017 10:21:09 PM
 Author:	Lex
*/

int i;

// the setup function runs once when you press reset or power the board
void setup() {
	i = 0;
	pinMode(D1_LED, OUTPUT);
	pinMode(D2_LED, OUTPUT);
	pinMode(D3_LED, OUTPUT);
	pinMode(D4_LED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	int led = D1_LED;
	switch (i) {
	case 0:
		led = D1_LED;
		break;
	case 1:
		led = D2_LED;
		break;
	case 2:
		led = D3_LED;
		break;
	case 3:
		led = D4_LED;
		break;
	}
	digitalWrite(led, HIGH);
	delay(500);
	digitalWrite(led, LOW);
	i = (i+1) % 4;
}

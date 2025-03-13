#include <SelectorRelays8.h>

// Define relay pins
const int RELAY0 = 2;
const int RELAY1 = 3;
const int RELAY2 = 4;
const int RELAY3 = 5;
const int RELAY4 = 6;
const int RELAY5 = 7;
const int RELAY6 = 8;
const int RELAY7 = 9;

// Create a SelectorRelays8 object
SelectorRelays8 relays(RELAY0, RELAY1, RELAY2, RELAY3, RELAY4, RELAY5, RELAY6, RELAY7);

void setup() {
    relays.begin();  // Initialize relays
}

void loop() {
    // Turn each relay on and off with a delay
    for (int i = 0; i < 8; i++) {
        relays.turnOn(i);
        delay(500);
        relays.turnOff(i);
        delay(500);
    }
}
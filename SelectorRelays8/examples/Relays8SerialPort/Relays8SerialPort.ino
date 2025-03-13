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
    Serial.begin(9600);
    relays.begin();  // Initialize relays
    Serial.println("Enter commands to control relays (e.g., ON 0, OFF 1, TOGGLE 3)");
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim(); // Remove any trailing newline

        // Process the command
        if (command.startsWith("ON ")) {
            int relay = command.substring(3).toInt();
            relays.turnOn(relay);
            Serial.print("Turned on relay ");
            Serial.println(relay);
        }
        else if (command.startsWith("OFF ")) {
            int relay = command.substring(4).toInt();
            relays.turnOff(relay);
            Serial.print("Turned off relay ");
            Serial.println(relay);
        }
        else if (command.startsWith("TOGGLE ")) {
            int relay = command.substring(7).toInt();
            relays.toggle(relay);
            Serial.print("Toggled relay ");
            Serial.println(relay);
        }
        else if (command == "ALL ON") {
            relays.allOn();
            Serial.println("All relays turned on");
        }
        else if (command == "ALL OFF") {
            relays.allOff();
            Serial.println("All relays turned off");
        }
        else {
            Serial.println("Invalid command. Use ON <relay>, OFF <relay>, TOGGLE <relay>, ALL ON, ALL OFF.");
        }
    }
}
#ifndef SELECTOR_RELAY_8_H
#define SELECTOR_RELAY_8_H

#include <Arduino.h>

class SelectorRelays8 {
public:
    // Constructor to initialize all 8 relay pins
    SelectorRelays8(uint8_t DATA0, uint8_t DATA1, uint8_t DATA2, uint8_t DATA3, 
                    uint8_t DATA4, uint8_t DATA5, uint8_t DATA6, uint8_t DATA7);

    // Initialize the relays
    void begin();

    // Control individual relays
    void turnOn(uint8_t relay);
    void turnOff(uint8_t relay);
    void toggle(uint8_t relay);
    
    // Control all relays
    void allOn();
    void allOff();

private:
    uint8_t _relayPins[8];  // Array to hold the relay pin numbers
};

#endif
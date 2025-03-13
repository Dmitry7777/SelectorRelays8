#include "SelectorRelays8.h"

// Constructor: initialize relay pin numbers
SelectorRelays8::SelectorRelays8(uint8_t DATA0, uint8_t DATA1, uint8_t DATA2, uint8_t DATA3, 
                                 uint8_t DATA4, uint8_t DATA5, uint8_t DATA6, uint8_t DATA7) {
    _relayPins[0] = DATA0;
    _relayPins[1] = DATA1;
    _relayPins[2] = DATA2;
    _relayPins[3] = DATA3;
    _relayPins[4] = DATA4;
    _relayPins[5] = DATA5;
    _relayPins[6] = DATA6;
    _relayPins[7] = DATA7;
}

// Initialize relay pins as outputs
void SelectorRelays8::begin() {
    for (int i = 0; i < 8; i++) {
        pinMode(_relayPins[i], OUTPUT);
        digitalWrite(_relayPins[i], LOW);  // Start with all relays off
    }
}

// Turn on a specific relay (0-7)
void SelectorRelays8::turnOn(uint8_t relay) {
    if (relay < 8) {
        digitalWrite(_relayPins[relay], HIGH);
    }
}

// Turn off a specific relay (0-7)
void SelectorRelays8::turnOff(uint8_t relay) {
    if (relay < 8) {
        digitalWrite(_relayPins[relay], LOW);
    }
}

// Toggle a specific relay (0-7)
void SelectorRelays8::toggle(uint8_t relay) {
    if (relay < 8) {
        digitalWrite(_relayPins[relay], !digitalRead(_relayPins[relay]));
    }
}

// Turn on all relays
void SelectorRelays8::allOn() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(_relayPins[i], HIGH);
    }
}

// Turn off all relays
void SelectorRelays8::allOff() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(_relayPins[i], LOW);
    }
}
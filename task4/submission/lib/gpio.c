#include "gpio.h"

void pinMode(GPIO_TypeDef* port, uint8_t pin, uint8_t mode) {
    uint8_t shift = pin * 4;
    port->CFGLR &= ~(0xF << shift);
    if (mode == INPUT_PULLUP) {
        port->CFGLR |= (0x8 << shift);
        port->BSHR = (1 << pin); 
    } else {
        port->CFGLR |= (mode << shift);
    }
}

void digitalWrite(GPIO_TypeDef* port, uint8_t pin, uint8_t value) {
    if (value == HIGH) {
        port->BSHR = (1 << pin); 
    } else {
        port->BCR = (1 << pin);  
    }
}

uint8_t digitalRead(GPIO_TypeDef* port, uint8_t pin) {
    if (port->INDR & (1 << pin)) {
        return HIGH;
    }
    return LOW;
}
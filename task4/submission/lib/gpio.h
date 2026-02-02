#ifndef GPIO_H
#define GPIO_H

#include <ch32v00x.h>

#define HIGH 1
#define LOW  0

#define INPUT         0x4  // Floating Input (CNF=01, MODE=00)
#define OUTPUT        0x1  // Push-Pull Output 10MHz (CNF=00, MODE=01)
#define INPUT_PULLUP  0x8  // Input with Pull-up (CNF=10, MODE=00)

void pinMode(GPIO_TypeDef* port, uint8_t pin, uint8_t mode);
void digitalWrite(GPIO_TypeDef* port, uint8_t pin, uint8_t value);
uint8_t digitalRead(GPIO_TypeDef* port, uint8_t pin);

#endif
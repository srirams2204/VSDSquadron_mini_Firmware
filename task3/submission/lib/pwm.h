#ifndef PWM_H
#define PWM_H

#include <ch32v00x.h>

void PWM_Write(GPIO_TypeDef* port, uint8_t pin, uint8_t duty);

#endif
#include "pwm.h"
#include "gpio.h"
#include "timer.h"

#define PWM_PERIOD_US 2000

void PWM_Write(GPIO_TypeDef* port, uint8_t pin, uint8_t duty) {

    uint16_t on_time = duty * 20; 
    uint16_t off_time = PWM_PERIOD_US - on_time;

    // 1. Turn ON
    if (duty > 0) {
        port->BSHR = (1 << pin);
        Delay_us(on_time);
    }

    // 2. Turn OFF
    if (duty < 100) {
        port->BCR = (1 << pin);
        Delay_us(off_time);
    }
}
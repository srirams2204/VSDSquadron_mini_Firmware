#include "timer.h"

void Timer_Init(void) {
    RCC->APB1PCENR |= RCC_APB1Periph_TIM2;
    TIM2->PSC = 24 - 1; 
    TIM2->ATRLR = 0xFFFF;
    TIM2->CTLR1 |= TIM_ARPE | TIM_CEN;
}

void Delay_us(uint16_t us) {
    TIM2->CNT = 0;
    while (TIM2->CNT < us);
}

void Delay_ms(uint16_t ms) {
    for (uint16_t i = 0; i < ms; i++) {
        Delay_us(1000);
    }
}
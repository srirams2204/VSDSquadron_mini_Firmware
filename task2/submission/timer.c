#include "timer.h"

void Timer_Init(void) {
    RCC->APB1PCENR |= RCC_APB1Periph_TIM2;
    TIM2->PSC = 24000 - 1; 
    TIM2->ATRLR = 0xFFFF;
    TIM2->CTLR1 |= TIM_ARPE;
}

void Delay_ms(uint16_t ms) {
    TIM2->CNT = 0;
    TIM2->ATRLR = ms;
    TIM2->INTFR &= ~(TIM_UIF);
    TIM2->CTLR1 |= TIM_CEN;
    while (!(TIM2->INTFR & TIM_UIF));
    TIM2->CTLR1 &= ~TIM_CEN;
}
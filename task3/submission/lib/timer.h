#ifndef TIMER_H
#define TIMER_H

#include <ch32v00x.h>
void Timer_Init(void);
void Delay_ms(uint16_t ms);
void Delay_us(uint16_t ms);

#endif
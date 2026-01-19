#include "hse_init.h"

void HSE_Init(void) {
    RCC->CTLR |= RCC_HSEON;
    while(!(RCC->CTLR & RCC_HSERDY));
    RCC->CFGR0 &= ~RCC_HPRE;
    RCC->CFGR0 &= ~RCC_SW;
    RCC->CFGR0 |= RCC_SW_HSE;
    while ((RCC->CFGR0 & RCC_SWS) != RCC_SWS_HSE);
    SystemCoreClockUpdate();
}
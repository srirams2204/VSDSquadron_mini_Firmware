#include "uart.h"

void Serial_Begin(uint32_t baudRate) {
    RCC->APB2PCENR |= RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOD;
    GPIOD->CFGLR &= ~(0xF << (5 * 4)); 
    GPIOD->CFGLR |= (0xB << (5 * 4));  
    GPIOD->CFGLR &= ~(0xF << (6 * 4));
    GPIOD->CFGLR |= (0x4 << (6 * 4));  
    uint32_t f_clk = 24000000; 
    uint32_t divisor = f_clk / baudRate;
    USART1->BRR = divisor;
    USART1->CTLR1 |= (USART_CTLR1_UE | USART_CTLR1_TE | USART_CTLR1_RE);
}

void Serial_Write(char c) {
    while (!(USART1->STATR & USART_STATR_TXE));
    USART1->DATAR = c;
}

void Serial_Print(const char* str) {
    while (*str) {
        Serial_Write(*str++);
    }
}

void Serial_Println(const char* str) {
    Serial_Print(str);
    Serial_Write('\r'); 
    Serial_Write('\n'); 
}

uint8_t Serial_Available(void) {
    if (USART1->STATR & USART_STATR_RXNE) {
        return 1;
    }
    return 0;
}

char Serial_Read(void) {
    return (char)(USART1->DATAR);
}
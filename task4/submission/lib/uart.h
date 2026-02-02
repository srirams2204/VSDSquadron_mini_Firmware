#ifndef UART_H
#define UART_H

#include <ch32v00x.h>
#include <stdio.h> 

void Serial_Begin(uint32_t baudRate);
void Serial_Write(char c);
void Serial_Print(const char* str);
void Serial_Println(const char* str);
uint8_t Serial_Available(void);
char Serial_Read(void);

#endif
#include <stdlib.h> 
#include <string.h> 
#include "uart.h"
#include "pwm.h"
#include "gpio.h"
#include "timer.h"
#include "hse_init.h" 

#define LED_PIN  3  

int main(void) {
    SystemInit();
    HSE_Init();     
    Timer_Init();   
    Serial_Begin(9600); 

    pinMode(GPIOD, LED_PIN, 0x1); 

    Serial_Println("==============================");
    Serial_Println("   UART PWM Controller v1.0   ");
    Serial_Println("   Connect LED to Pin PD3     ");
    Serial_Println("   Type 0-100 & hit ENTER     ");
    Serial_Println("==============================");
    
    int current_duty = 0;
    char inputBuffer[10];
    int bufferIndex = 0;
    memset(inputBuffer, 0, 10);

    while(1) {
        PWM_Write(GPIOD, LED_PIN, current_duty);
        if (Serial_Available()) {
            char c = Serial_Read();
            if (c == '\n' || c == '\r') {
                if (bufferIndex > 0) {
                    inputBuffer[bufferIndex] = '\0'; 
                    Serial_Println(""); 
                    int newVal = atoi(inputBuffer);
                    if (newVal >= 0 && newVal <= 100) {
                        current_duty = newVal;
                        Serial_Print(">> Brightness set to: ");
                        char numStr[5];
                        itoa(current_duty, numStr, 10); 
                        Serial_Print(numStr);
                        Serial_Println("%");
                    } else {
                        Serial_Println(">> Error: Use 0-100 only!");
                    }
                    bufferIndex = 0;
                    memset(inputBuffer, 0, 10);
                }
            }
            else if (c >= '0' && c <= '9') {
                if (bufferIndex < 9) {
                    Serial_Write(c); 
                    inputBuffer[bufferIndex++] = c;
                }
            }
        }
    }
}
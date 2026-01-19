#include "hse_init.h"  
#include "uart.h"      
#include "gpio.h"      
#include "timer.h"     

#define LED_PIN  6  

int main(void) {
    SystemInit();       
    HSE_Init();         
    Timer_Init();       
    
    Serial_Begin(9600);
    
    pinMode(GPIOD, LED_PIN, OUTPUT);

    Serial_Println("System Initialized: Starting Blink Loop...");

    while(1) {
        digitalWrite(GPIOD, LED_PIN, HIGH);  
        Serial_Println("LED Status: ON");     
        Delay_ms(1000);                      
        digitalWrite(GPIOD, LED_PIN, LOW);    
        Serial_Println("LED Status: OFF");    
        Delay_ms(1000);                       
    }
}
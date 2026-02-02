#include "scheduler.h"
#include "gpio.h"
#include "uart.h"
#include "timer.h" 

#define LED_PIN    6  // PD6
#define BUTTON_PIN 4  // PD4

void Task_Blink(void) {
    static int state = 0;
    state = !state;
    digitalWrite(GPIOD, LED_PIN, state);
    
    Serial_Print("[Task A] LED is now: ");
    Serial_Println(state ? "ON" : "OFF");
}

void Task_Status(void) {
    Serial_Print("[Task B] System Heartbeat. OS Tick: ");
    char tickBuf[12];
    itoa(OS_GetTick(), tickBuf, 10);
    Serial_Println(tickBuf);
}

void Task_Input(void) {
    if (digitalRead(GPIOD, BUTTON_PIN) == LOW) {
        Serial_Println("[Task C] EVENT: Button Pressed on PD4!");
    } else {
        Serial_Println("[Task C] Scanning Button State: IDLE");
    }
}

int main(void) {
    SystemInit();
    HSE_Init();
    Serial_Begin(9600);
    
    pinMode(GPIOD, LED_PIN, 0x1); 
    pinMode(GPIOD, BUTTON_PIN, 0x8); 

    Serial_Println("************************************");
    Serial_Println("   VSDSquadron Mini-RTOS Capstone   ");
    Serial_Println("************************************");

    OS_Init();
    OS_AddTask(Task_Input, 1000); 
    OS_AddTask(Task_Blink, 3000); 
    OS_AddTask(Task_Status, 5000); 
    while(1) {
        OS_Run(); 
    }
}
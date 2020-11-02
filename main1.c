#include <stdint.h>
#include <stdbool.h>
#include <tm4c123gh6pm.h>
#include <sysctl.h>
#include "Serial.h"
#include "timer.h"


//void PLLInit()
//{
//    SYSCTL_RCC2_R |= 0x80000000;
//    SYSCTL_RCC2_R |= 0x00000800;
//    SYSCTL_RCC_R = (SYSCTL_RCC_R & ~0x000007C0) + 0x00000540;
//    SYSCTL_RCC2_R &= ~0x00000070;
//    SYSCTL_RCC2_R &= ~0x00002000;
//    SYSCTL_RCC2_R |= 0x40000000;
//    SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (4 << 22);
//    while ((SYSCTL_RIS_R &0x00000040)==0){};
//    SYSCTL_RCC2_R &= ~0x00000800;
//}




/**
 * main1.c
 */
int main1(void)
{
    PLLInit();
    SetupSerial();
    SystickInit();
    SYSCTL_RCGCGPIO_R |= 0x3F; // enable clock for PORT B, D

    GPIO_PORTB_LOCK_R = 0x4C4F434B; // this value unlocks the GPIOCR register.
    GPIO_PORTB_CR_R = 0xFF;
    GPIO_PORTB_AMSEL_R = 0x00; // disable analog functionality
    GPIO_PORTB_PCTL_R = 0x00000000; // Select GPIO mode in PCTL
    GPIO_PORTB_DIR_R = 0x0F; // Pins B0-B3 are outputs
    GPIO_PORTB_AFSEL_R = 0x00; // Disable alternate functionality
    GPIO_PORTB_DEN_R = 0xFF; //Enable digital ports

    GPIO_PORTD_LOCK_R = 0x4C4F434B; // this value unlocks the GPIOCR register.
    GPIO_PORTD_CR_R = 0xFF;
    GPIO_PORTD_AMSEL_R = 0x00; // disable analog functionality
    GPIO_PORTD_PCTL_R = 0x00000000; // Select GPIO mode in PCTL
    GPIO_PORTD_DIR_R = 0x00; // Pins D0-D3 are inputs
    GPIO_PORTD_AFSEL_R = 0x00; // Disable alternate functionality
    GPIO_PORTD_DEN_R = 0xFF; //Enable digital ports

    volatile uint32_t PORTB;
    volatile uint32_t PORTD;
    char* rows[4][4] = {{"1","2","3","A"},{"4","5","6","B"},{"7","8","9","C"},{"*","0","#","D"}};

    volatile int row = -1;
    volatile int col = -1;

    volatile bool buttonPressed = false;
    volatile bool buttonReleased = false;

    while(1)
    {
        GPIO_PORTB_DATA_R = 0x0E;
        GPIO_PORTB_DATA_R = 0x0E;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        if (PORTD == 0x0E && buttonPressed == false)
        {
            col = 0;
            row = 0;
            buttonPressed = true;
            SysTick_Wait100microsec(200);
        }
        if (PORTD == 0x0D&& buttonPressed == false)
        {
            col = 1;
            row = 0;
            buttonPressed = true;
            SysTick_Wait100microsec(200);
        }
        if (PORTD == 0x0B&& buttonPressed == false)
        {
            col = 2;
            row = 0;
            buttonPressed = true;
            SysTick_Wait100microsec(200);
        }
        if (PORTD == 0x07&& buttonPressed == false)
        {
            col = 3;
            row = 0;
            buttonPressed = true;
            SysTick_Wait100microsec(200);
        }

        GPIO_PORTB_DATA_R = 0x0D;
        GPIO_PORTB_DATA_R = 0x0D;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        if (PORTD == 0x0E&& buttonPressed == false)
        {
            col = 0;
            row = 1;
            buttonPressed = true;
        }
        if (PORTD == 0x0D&& buttonPressed == false)
        {
            col = 1;
            row = 1;
            buttonPressed = true;
        }
        if (PORTD == 0x0B&& buttonPressed == false)
        {
            col = 2;
            row = 1;
            buttonPressed = true;
        }
        if (PORTD == 0x07&& buttonPressed == false)
        {
            col = 3;
            row = 1;
            buttonPressed = true;
        }

        GPIO_PORTB_DATA_R = 0x0B;
        GPIO_PORTB_DATA_R = 0x0B;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        if (PORTD == 0x0E&& buttonPressed == false)
        {
            col = 0;
            row = 2;
            buttonPressed = true;
        }
        if (PORTD == 0x0D&& buttonPressed == false)
        {
            col = 1;
            row = 2;
            buttonPressed = true;
        }
        if (PORTD == 0x0B&& buttonPressed == false)
        {
            col = 2;
            row = 2;
            buttonPressed = true;
        }
        if (PORTD == 0x07&& buttonPressed == false)
        {
            col = 3;
            row = 2;
            buttonPressed = true;
        }

        GPIO_PORTB_DATA_R = 0x07;
        GPIO_PORTB_DATA_R = 0x07;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        if (PORTD == 0x0E&& buttonPressed == false)
        {
            col = 0;
            row = 3;
            buttonPressed = true;
        }
        if (PORTD == 0x0D&& buttonPressed == false)
        {
            col = 1;
            row = 3;
            buttonPressed = true;
        }
        if (PORTD == 0x0B&& buttonPressed == false)
        {
            col = 2;
            row = 3;
            buttonPressed = true;
        }
        if (PORTD == 0x07&& buttonPressed == false)
        {
            col = 3;
            row = 3;
            buttonPressed = true;
        }


        GPIO_PORTB_DATA_R = 0x00;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;

        if (buttonPressed == true && PORTD == 15)
        {
            buttonPressed = false;
            buttonReleased = true;
            SysTick_Wait100microsec(200);
        }

        if (buttonReleased == true)
        {
            buttonReleased = false;
            SerialWrite(rows[row][col]);
        }

    }

}

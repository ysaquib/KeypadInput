#include <stdint.h>
#include <stdbool.h>
#include <tm4c123gh6pm.h>
#include <sysctl.h>
#include "Serial.h"
#include "timer.h"

struct State
{
    uint32_t timer;
    char* output[9];
    struct State *NextState[9];
};

typedef struct State stateType;

#define S0 &FSM[0]
#define S1 &FSM[1]
#define S2 &FSM[2]
#define S3 &FSM[3]
#define S4 &FSM[4]
#define S5 &FSM[5]
#define S6 &FSM[6]
#define S7 &FSM[7]
#define S8 &FSM[8]
#define S9 &FSM[9]
#define S10 &FSM[10]
#define S11 &FSM[11]
#define S12 &FSM[12]
#define S13 &FSM[13]
#define S14 &FSM[14]
#define S15 &FSM[15]
#define S16 &FSM[16]
#define S17 &FSM[17]
#define S18 &FSM[18]
#define S19 &FSM[19]
#define S20 &FSM[20]
#define S21 &FSM[21]
#define S22 &FSM[22]
#define S23 &FSM[23]
#define S24 &FSM[24]
#define S25 &FSM[25]
#define S26 &FSM[26]
#define S27 &FSM[27]
#define S28 &FSM[28]
#define S29 &FSM[29]
#define S30 &FSM[30]
#define S31 &FSM[31]
#define S32 &FSM[32]
#define S33 &FSM[33]
#define S34 &FSM[34]

const stateType FSM[35] =
{
     // Time (s), Output, NextStates[]
     {0, {"","","","","","","","",""}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S0


     {10000, {"A","","A","A","A","A","A","A","A"}, {S0,S2,S5,S9,S13,S17,S21,S26,S30}}, //S1
     {10000, {"B","","B","B","B","B","B","B","B"}, {S0,S3,S5,S9,S13,S17,S21,S26,S30}}, //S2
     {10000, {"C","","C","C","C","C","C","C","C"}, {S0,S4,S5,S9,S13,S17,S21,S26,S30}}, //S3
     {10000, {"2","","2","2","2","2","2","2","2"}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S4

     {10000, {"D","D","","D","D","D","D","D","D"}, {S0,S1,S6,S9,S13,S17,S21,S26,S30}}, //S5
     {10000, {"E","E","","E","E","E","E","E","E"}, {S0,S1,S7,S9,S13,S17,S21,S26,S30}}, //S6
     {10000, {"F","F","","F","F","F","F","F","F"}, {S0,S1,S8,S9,S13,S17,S21,S26,S30}}, //S7
     {10000, {"3","3","","3","3","3","3","3","3"}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S8

     {10000, {"G","G","G","","G","G","G","G","G"}, {S0,S1,S5,S10,S13,S17,S21,S26,S30}}, //S9
     {10000, {"H","H","H","","H","H","H","H","H"}, {S0,S1,S5,S11,S13,S17,S21,S26,S30}}, //S10
     {10000, {"I","I","I","","I","I","I","I","I"}, {S0,S1,S5,S12,S13,S17,S21,S26,S30}}, //S11
     {10000, {"4","4","4","","4","4","4","4","4"}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S12

     {10000, {"J","J","J","J","","J","J","J","J"}, {S0,S1,S5,S9,S14,S17,S21,S26,S30}}, //S13
     {10000, {"K","K","K","K","","K","K","K","K"}, {S0,S1,S5,S9,S15,S17,S21,S26,S30}}, //S14
     {10000, {"L","L","L","L","","L","L","L","L"}, {S0,S1,S5,S9,S16,S17,S21,S26,S30}}, //S15
     {10000, {"5","5","5","5","","5","5","5","5"}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S16

     {10000, {"M","M","M","M","M","","M","M","M"}, {S0,S1,S5,S9,S13,S18,S21,S26,S30}}, //S17
     {10000, {"N","N","N","N","N","","N","N","N"}, {S0,S1,S5,S9,S13,S19,S21,S26,S30}}, //S18
     {10000, {"O","O","O","O","O","","O","O","O"}, {S0,S1,S5,S9,S13,S20,S21,S26,S30}}, //S19
     {10000, {"6","6","6","6","6","","6","6","6"}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S20

     {10000, {"P","P","P","P","P","P","","P","P"}, {S0,S1,S5,S9,S13,S17,S22,S26,S30}}, //S21
     {10000, {"Q","Q","Q","Q","Q","Q","","Q","Q"}, {S0,S1,S5,S9,S13,S17,S23,S26,S30}}, //S22
     {10000, {"R","R","R","R","R","R","","R","R"}, {S0,S1,S5,S9,S13,S17,S24,S26,S30}}, //S23
     {10000, {"S","S","S","S","S","S","","S","S"}, {S0,S1,S5,S9,S13,S17,S25,S26,S30}}, //S24
     {10000, {"7","7","7","7","7","7","","7","7"}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S25

     {10000, {"T","T","T","T","T","T","T","","T"}, {S0,S1,S5,S9,S13,S17,S21,S27,S30}}, //S26
     {10000, {"U","U","U","U","U","U","U","","U"}, {S0,S1,S5,S9,S13,S17,S21,S28,S30}}, //S27
     {10000, {"V","V","V","V","V","V","V","","V"}, {S0,S1,S5,S9,S13,S17,S21,S29,S30}}, //S28
     {10000, {"8","8","8","8","8","8","8","","8"}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S29

     {10000, {"W","W","W","W","W","W","W","W",""}, {S0,S1,S5,S9,S13,S17,S21,S26,S31}}, //S30
     {10000, {"X","X","X","X","X","X","X","X",""}, {S0,S1,S5,S9,S13,S17,S21,S26,S32}}, //S31
     {10000, {"Y","Y","Y","Y","Y","Y","Y","Y",""}, {S0,S1,S5,S9,S13,S17,S21,S26,S33}}, //S32
     {10000, {"Z","Z","Z","Z","Z","Z","Z","Z",""}, {S0,S1,S5,S9,S13,S17,S21,S26,S34}}, //S33
     {10000, {"9","9","9","9","9","9","9","9",""}, {S0,S1,S5,S9,S13,S17,S21,S26,S30}}, //S34
};

void PLLInit()
{
    SYSCTL_RCC2_R |= 0x80000000;
    SYSCTL_RCC2_R |= 0x00000800;
    SYSCTL_RCC_R = (SYSCTL_RCC_R & ~0x000007C0) + 0x00000540;
    SYSCTL_RCC2_R &= ~0x00000070;
    SYSCTL_RCC2_R &= ~0x00002000;
    SYSCTL_RCC2_R |= 0x40000000;
    SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (4 << 22);
    while ((SYSCTL_RIS_R &0x00000040)==0){};
    SYSCTL_RCC2_R &= ~0x00000800;
}


const int buttonNum[4][4] = {{10, 1, 2,14},
                           { 3, 4, 5,15},
                           { 6, 7, 8,16},
                           {11,12,13,17}};
const char* charsNoState[8] = {"1","*","0","#","A","B","C","D"};

int getButtonNum ()
{
    int col = -1;
    int row = -1;
    uint32_t PORTD_DATA;
    GPIO_PORTB_DATA_R = 0x0E;
    GPIO_PORTB_DATA_R = 0x0E;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    if (PORTD_DATA == 0x0E)
    {
        col = 0;
        row = 0;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0D)
    {
        col = 1;
        row = 0;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0B)
    {
        col = 2;
        row = 0;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x07)
    {
        col = 3;
        row = 0;
        SysTick_Wait100microsec(200);
    }
    GPIO_PORTB_DATA_R = 0x0D;
    GPIO_PORTB_DATA_R = 0x0D;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    if (PORTD_DATA == 0x0E)
    {
        col = 0;
        row = 1;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0D)
    {
        col = 1;
        row = 1;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0B)
    {
        col = 2;
        row = 1;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x07)
    {
        col = 3;
        row = 1;
        SysTick_Wait100microsec(200);
    }
    GPIO_PORTB_DATA_R = 0x0B;
    GPIO_PORTB_DATA_R = 0x0B;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    if (PORTD_DATA == 0x0E)
    {
        col = 0;
        row = 2;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0D)
    {
        col = 1;
        row = 2;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0B)
    {
        col = 2;
        row = 2;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x07)
    {
        col = 3;
        row = 2;
        SysTick_Wait100microsec(200);
    }
    GPIO_PORTB_DATA_R = 0x07;
    GPIO_PORTB_DATA_R = 0x07;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    PORTD_DATA = GPIO_PORTD_DATA_R & 0x0F;
    if (PORTD_DATA == 0x0E)
    {
        col = 0;
        row = 3;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0D)
    {
        col = 1;
        row = 3;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x0B)
    {
        col = 2;
        row = 3;
        SysTick_Wait100microsec(200);
    }
    if (PORTD_DATA == 0x07)
    {
        col = 3;
        row = 3;
        SysTick_Wait100microsec(200);
    }
    GPIO_PORTB_DATA_R = 0x00;
    GPIO_PORTB_DATA_R = 0x00;
    int result = -1;
    if (row != -1 && col != -1)
        result = buttonNum[row][col];
    return result;

}



int main(void)
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

    volatile stateType *curState;
    curState = S0;
    bool buttonPressed = false;
    bool buttonReleased = false;
    volatile int buttonNumber = -1;
    volatile uint32_t PORTB;
    volatile uint32_t PORTD;
    int timer = -1;
    while (1)
    {
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        PORTD = GPIO_PORTD_DATA_R & 0x0F;
        if (PORTD != 15)
        {
            buttonPressed = true;
            buttonNumber = getButtonNum(); // Check which button was pressed
        }
        if (PORTD == 15 && buttonPressed == true)
        {
            buttonReleased = true;
            buttonPressed = false;
        }

        if (buttonReleased == true)
        {
            buttonReleased = false;

            if (buttonNumber > 0 && buttonNumber < 9)
            {
                char* character = curState->output[buttonNumber];
                curState = curState->NextState[buttonNumber];
                timer = curState->timer;
                SerialWrite(character);
            }
            if (buttonNumber > 9 && buttonNumber < 18)
            {
                char* character = curState->output[0];
                SerialWrite(character);
                curState = curState->NextState[0];
                timer = -1;
                character = charsNoState[buttonNumber%10];
                SerialWrite(character);
            }
        }
        if(timer == 0)
        {
            char* character = curState->output[0];
            curState = curState->NextState[0];
            timer = curState->timer;
            SerialWrite(character);
        }
        if ( timer > 0)
        {
            timer --;
            SysTick_Wait100microsec(1);
        }
            // Handle State Stuff

            /*if (buttonNumber >= 10)
            {
                SysTick_Wait100microsec(200);
                SerialWrite(charsNoState[buttonNumber%10]);
                curState = curState->NextState[0];
            }

            else if (buttonNumber > 0 && buttonNumber < 10)
            {
                int timer = 0;
                curState = curState->NextState[buttonNumber];
                while(timer <= 200000)
                {
                    int temp = buttonNumber;
                    buttonNumber = getButtonNum();
                    if (buttonNumber > 0 && buttonNumber < 10)
                    {
                        timer = 0;
                        if (buttonNumber != temp)
                            SerialWrite(curState->output);
                        curState = curState->NextState[buttonNumber];
                    }

                    else if (buttonNumber >= 10)
                    {
                        SerialWrite(curState->output);
                        SysTick_Wait100microsec(200);
                        SerialWrite(charsNoState[buttonNumber%10]);
                        curState = curState->NextState[0];
                        timer = 200000*10;
                    }
                    timer++;
                }

                if (timer == 200001)
                {
                    SerialWrite(curState->output);
                    curState = S0;
                }
            }


            //Use the button that was pressed and give output

            buttonNumber = -1;
        }*/
    }
}

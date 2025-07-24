//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
//Function Declarations
void redLight();
void yellowLight();
void greenLight();

//Main function that drives the program
int main()
{
    //Initialize variables
    bool isMorning = true;
    bool isTrafficJam = false;

    //Run program infinitely
    while(true)
    {
        //Check if it's morning
        if(isMorning)
        {
            greenLight();//Turn on green light in the morning
            sleep(5);//Delay for 5 seconds
            yellowLight();//Turn on yellow light for 2 seconds
            sleep(2);
            redLight();//Turn on red light for 5 seconds
            sleep(5);
        }
        else if(isTrafficJam)
        {
            redLight();//Turn on red light in case of traffic jam
            sleep(5);
        }
        else
        {
            greenLight();//Turn on green light if no traffic jam
            sleep(5);
            yellowLight();//Turn on yellow light for 2 seconds
            sleep(2);
            redLight();//Turn on red light for 5 seconds
            sleep(5);
        }
    }

    return 0;//Return 0 to indicate success
}

//Red light function
void redLight()
{
    printf("RED light is ON. Please stop!\n");
}

//Yellow light function
void yellowLight()
{
    printf("YELLOW light is ON. Please standby!\n");
}

//Green light function
void greenLight()
{
    printf("GREEN light is ON. Please proceed!\n");
}
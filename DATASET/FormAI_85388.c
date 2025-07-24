//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
// C program for Traffic Light Controller
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Function prototypes
void redLightOn();
void greenLightOn();
void yellowLightOn();

//main driver function
int main()
{
    int trafficCondition = 1;       //1 for heavy traffic 0 for light traffic
    
    while(1)
    {
        if(trafficCondition){       //Heavy traffic
            printf("Traffic is heavy, Red Light is On.\n");
            redLightOn();
            printf("Traffic is heavy, Green Light is On\n");
            greenLightOn();
            printf("Traffic is heavy, Yellow Light is On\n");
            yellowLightOn();
        }else{                     //Light traffic
            printf("Traffic is light, Green Light is On\n");
            greenLightOn();
            printf("Traffic is light, Yellow Light is On\n");
            yellowLightOn();
            printf("Traffic is light, Red Light is On\n");
            redLightOn();
        }
        trafficCondition = !trafficCondition;  //Toggle the traffic condition
    }
    return 0;
}

//Function for Red light
void redLightOn()
{
    printf("Red Light is ON\n");
    sleep(5);         //5 sec delay for red light
}

//Function for Green light
void greenLightOn()
{
    printf("Green Light is ON\n");
    sleep(5);        //5 sec delay for green light
}

//Function for Yellow light
void yellowLightOn()
{
    printf("Yellow Light is ON\n");
    sleep(2);        //2 sec delay for yellow light
}
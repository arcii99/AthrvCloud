//FormAI DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include<stdio.h>

//Function to check if the power is on or off
int isPowerOn(int powerStatus)
{
    if(powerStatus==1)
        return 1;
    else
        return 0;
}

//Function to turn on/off the lights
int lightControl(int powerStatus, int lightStatus)
{
    if(isPowerOn(powerStatus)==1)
    {
        if(lightStatus==1)
        {
            printf("The lights are turned OFF!\n");
            return 0;
        }
        else
        {
            printf("The lights are turned ON!\n");
            return 1;
        }
    }
    else
    {
        printf("Sorry, the power is OFF!\n");
        return lightStatus;
    }
}

//Function to turn on/off the AC
int acControl(int powerStatus, int acStatus)
{
    if(isPowerOn(powerStatus)==1)
    {
        if(acStatus==1)
        {
            printf("The AC is turned OFF!\n");
            return 0;
        }
        else
        {
            printf("The AC is turned ON!\n");
            return 1;
        }
    }
    else
    {
        printf("Sorry, the power is OFF!\n");
        return acStatus;
    }
}

int main()
{
    int powerStatus = 0;
    int lightStatus = 0;
    int acStatus = 0;

    //Power on the system
    powerStatus = 1;
    printf("The power is ON!\n");

    //Control the lights
    lightStatus = lightControl(powerStatus, lightStatus);

    //Control the AC
    acStatus = acControl(powerStatus, acStatus);

    //Power off the system
    powerStatus = 0;
    printf("The power is OFF!\n");

    return 0;
}
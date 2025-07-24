//FormAI DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>

// Function to turn on the lights
void lightsOn()
{
    printf("Turning on the lights.\n");
}

// Function to turn off the lights
void lightsOff()
{
    printf("Turning off the lights.\n");
}

// Function to turn on the TV
void tvOn()
{
    printf("Turning on the TV.\n");
}

// Function to turn off the TV
void tvOff()
{
    printf("Turning off the TV.\n");
}

int main()
{
    int time = 18; // time of day, assumed 24-hour format
    int on = 1; // flag to indicate if someone is at home
    
    printf("Welcome to Smart Home Automation.\n");

    // If it is after 6pm and someone is at home, turn on the lights
    if(time >= 18 && on){
        lightsOn();
    }

    // If it is after 8pm and someone is at home, turn on the TV
    if(time >= 20 && on){
        tvOn();
    }

    // If the time is past midnight, turn off the TV
    if(time >= 0 && time < 6){
        tvOff();
    }

    // If it is after 10pm and no one is at home, turn off the lights
    if(time >= 22 && !on){
        lightsOff();
    }

    return 0;
}
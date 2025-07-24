//FormAI DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>

#define DOOR_LOCKED 0
#define DOOR_UNLOCKED 1
#define LIGHTS_OFF 0
#define LIGHTS_ON 1
#define TEMPERATURE_LOW 20
#define TEMPERATURE_HIGH 30

//Function to check security status
bool checkSecurity(int doorStatus)
{
    if (doorStatus == DOOR_LOCKED)
    {
        printf("Security check passed. Door is locked.\n");
        return true;
    }
    else
    {
        printf("Security check failed. Door is not locked!\n");
        return false;
    }
}

//Function to operate lights
void operateLights(int lightStatus)
{
    if (lightStatus == LIGHTS_OFF)
    {
        printf("Turning on the lights.\n");
        lightStatus = LIGHTS_ON;
    }
    else
    {
        printf("Turning off the lights.\n");
        lightStatus = LIGHTS_OFF;
    }
}

//Function to adjust temperature
void adjustTemperature(int temperature)
{
    if (temperature < TEMPERATURE_LOW)
    {
        printf("Increasing temperature...\n");
        temperature += 5;
    }
    else if (temperature > TEMPERATURE_HIGH)
    {
        printf("Decreasing temperature...\n");
        temperature -= 5;
    }
}

int main()
{
    //Setting the initial states
    int doorStatus = DOOR_LOCKED;
    int lightStatus = LIGHTS_OFF;
    int temperature = 25;

    //Cyber mode ON
    printf("Welcome to the CyberPunk Smart Home Automation System!\n");
    printf("Initiating Cyber mode...\n");

    //Checking security
    if (checkSecurity(doorStatus))
    {
        //Operating Lights
        operateLights(lightStatus);

        //Adjusting temperature
        adjustTemperature(temperature);

        printf("All systems are now Cyber ready!\n");
    }
    else
    {
        printf("Cyber mode activated but system cannot operate as security check failed!\n");
    }

  return 0;
}
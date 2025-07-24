//FormAI DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tempSensor = 0, lightSensor = 0, securitySensor = 0;
    
    printf("Welcome to Smart Home Automation!\n\n");
    
    while(1)   // infinite loop to simulate continuous monitoring of sensors
    {
        // code to read the temperature sensor
        tempSensor = getRandomNumber(50);
        
        // code to read the light sensor
        lightSensor = getRandomNumber(100);
        
        // code to read the security sensor
        securitySensor = getRandomNumber(2);
        
        printf("Temperature: %d\n", tempSensor);
        printf("Light Level: %d\n", lightSensor);
        
        if(securitySensor == 0)
        {
            printf("Security Sensor: OFF\n");
        }
        else
        {
            printf("Security Sensor: ON\n");
        }
        
        // code to adjust the temperature based on the temperature sensor readings
        if(tempSensor < 20)
        {
            printf("Heating turned ON!\n");
        }
        else if(tempSensor > 25)
        {
            printf("Cooling turned ON!\n");
        }
        else
        {
            printf("Temperature is ideal.\n");
        }
        
        // code to adjust the lights based on the light sensor readings
        if(lightSensor < 20)
        {
            printf("Lights turned ON!\n");
        }
        else if(lightSensor > 80)
        {
            printf("Lights turned OFF!\n");
        }
        else
        {
            printf("Lights are at an optimal level.\n");
        }
        
        // code to sound the alarm if the security sensor is triggered
        if(securitySensor == 1)
        {
            printf("INTRUDER ALERT! Alarm activated.\n");
        }
        
        // sleep for 5 seconds before checking sensors again
        sleep(5);
    }
    
    return 0;
}

// function to generate a random number between a given range
int getRandomNumber(int range)
{
    int randomNumber = 0;
    srand(time(NULL));  // seed the random number generator with the current time
    randomNumber = rand() % range;
    return randomNumber;
}
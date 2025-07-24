//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multiplayer
/* Multiplayer Traffic Light Controller Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Declarations
void updateTrafficLights(int trafficLight[], int numOfLights);
int switchLights(int trafficLight);
void printLightStatus(int trafficLight[], int numOfLights);

// Main Function
int main()
{
    srand(time(NULL)); // Seed rand function with time

    int numOfLights = 4; // Number of traffic lights
    int trafficLight[numOfLights]; // Array to hold status of each light

    // Initialize each traffic light to red (0)
    for(int i = 0; i < numOfLights; i++)
    {
        trafficLight[i] = 0;
    }

    // Loop 10 rounds of traffic light status updates
    for(int i = 0; i < 10; i++)
    {
        updateTrafficLights(trafficLight, numOfLights);
        printLightStatus(trafficLight, numOfLights);
    }

    return 0;
}

// Function Definitions

// Update the status of all traffic lights
void updateTrafficLights(int trafficLight[], int numOfLights)
{
    // Randomly switch the status of a traffic light
    trafficLight[rand() % numOfLights] = switchLights(trafficLight[rand() % numOfLights]);
}

// Switch the status of a traffic light
int switchLights(int trafficLight)
{
    // Return the opposite status of the current light
    if(trafficLight == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Print the status of all traffic lights
void printLightStatus(int trafficLight[], int numOfLights)
{
    printf("Traffic Light Status:\n");
    for(int i = 0; i < numOfLights; i++)
    {
        if(trafficLight[i] == 0)
        {
            printf("Light %d: Red\n", i+1);
        }
        else if(trafficLight[i] == 1)
        {
            printf("Light %d: Green\n", i+1);
        }
    }
    printf("\n");
}
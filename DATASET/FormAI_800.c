//FormAI DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global Variables
bool lightOn = false;
bool motionDetected = false;

// Function Prototypes
void turnOnLight();
void turnOffLight();
void detectMotion();

int main()
{
    srand(time(NULL)); // Initializes random number generator
    
    // Loop to simulate light control for 10 minutes (600 seconds)
    for(int i = 0; i < 600; i++)
    {
        detectMotion(); // Simulates motion detector
        
        if(motionDetected)
        {
            turnOnLight(); // Turns on light if motion detected
        }
        else
        {
            turnOffLight(); // Turns off light if no motion detected
        }
        
        // Waits for random amount of time between 1 and 5 seconds
        int delay = rand() % 5 + 1; 
        sleep(delay);
    }
    
    return 0;
}

// Function to turn on light
void turnOnLight()
{
    if(!lightOn) // Only turns on light if it is currently off
    {
        lightOn = true; // Sets lightOn variable to true
        printf("Light turned on.\n");
    }
}

// Function to turn off light
void turnOffLight()
{
    if(lightOn) // Only turns off light if it is currently on
    {
        lightOn = false; // Sets lightOn variable to false
        printf("Light turned off.\n");
    }
}

// Function to simulate motion detector
void detectMotion()
{
    // Simulates a 20% chance of motion being detected
    int probability = rand() % 100 + 1;
    if(probability <= 20)
    {
        motionDetected = true; // Sets motionDetected variable to true
    }
    else
    {
        motionDetected = false; // Sets motionDetected variable to false
    }
}
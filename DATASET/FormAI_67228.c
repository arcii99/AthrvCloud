//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the states of the traffic lights
#define RED 1
#define YELLOW 2
#define GREEN 3

int main()
{
    int state = RED; // Set initial state of traffic light to red
    
    // Set the duration of each light phase in seconds
    int redTime = 10;
    int yellowTime = 3;
    int greenTime = 15;
    
    while (1) // Loop forever
    {
        switch (state)
        {
            case RED:
                printf("RED light is ON.\n");
                sleep(redTime); // Wait for red light phase
                state = GREEN; // Change state to switch to green light
                break;
                
            case YELLOW:
                printf("YELLOW light is ON.\n");
                sleep(yellowTime); // Wait for yellow light phase
                state = RED; // Change state to switch to red light
                break;
                
            case GREEN:
                printf("GREEN light is ON.\n");
                sleep(greenTime); // Wait for green light phase
                state = YELLOW; // Change state to switch to yellow light
                break;
        }
    }
    
    return 0;
}
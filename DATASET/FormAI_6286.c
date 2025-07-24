//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // Needed for sleep()

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Function Prototypes
void displayLights(int r, int y, int g);
void turnOnLight(int light);
void turnOffLight(int light);

// Main Function
int main()
{
    bool isRunning = true;
    int currentState = RED_LIGHT;
    int timeElapsed = 0;
    int redTime = 10;    // Duration of the red light in seconds.
    int yellowTime = 2;  // Duration of the yellow light in seconds.
    int greenTime = 10;  // Duration of the green light in seconds.

    // Loop until the program is terminated by the user
    while (isRunning)
    {
        // Display the current state of the traffic lights
        displayLights(currentState == RED_LIGHT, currentState == YELLOW_LIGHT, currentState == GREEN_LIGHT);

        // Wait for 1 second
        sleep(1);
        timeElapsed++;

        // Determine the next state based on the time elapsed since the last state change
        if (currentState == RED_LIGHT && timeElapsed >= redTime)
        {
            currentState = GREEN_LIGHT;
            timeElapsed = 0;
        }
        else if (currentState == GREEN_LIGHT && timeElapsed >= greenTime)
        {
            currentState = YELLOW_LIGHT;
            timeElapsed = 0;
        }
        else if (currentState == YELLOW_LIGHT && timeElapsed >= yellowTime)
        {
            currentState = RED_LIGHT;
            timeElapsed = 0;
        }
    }

    return 0;
}

// Display the current state of the traffic lights
void displayLights(int r, int y, int g)
{
    if (r)
        printf("RED ");
    else
        printf("    ");

    if (y)
        printf("YELLOW ");
    else
        printf("      ");

    if (g)
        printf("GREEN\n");
    else
        printf("     \n");
}

// Turn on a specific light
void turnOnLight(int light)
{
    switch (light)
    {
        case RED_LIGHT:
            printf("Turning on RED light\n");
            break;
        case YELLOW_LIGHT:
            printf("Turning on YELLOW light\n");
            break;
        case GREEN_LIGHT:
            printf("Turning on GREEN light\n");
            break;
        default:
            printf("Invalid light\n");
            break;
    }
}

// Turn off a specific light
void turnOffLight(int light)
{
    switch (light)
    {
        case RED_LIGHT:
            printf("Turning off RED light\n");
            break;
        case YELLOW_LIGHT:
            printf("Turning off YELLOW light\n");
            break;
        case GREEN_LIGHT:
            printf("Turning off GREEN light\n");
            break;
        default:
            printf("Invalid light\n");
            break;
    }
}
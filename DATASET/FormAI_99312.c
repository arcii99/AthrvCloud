//FormAI DATASET v1.0 Category: Smart home automation ; Style: statistical
#include <stdio.h>
#include <stdbool.h>

// Function prototype
void turnOnLights(bool isDaytime, bool isAway);

int main()
{
    // Variables
    bool isDaytime = true;
    bool isAway = false;

    // Call turnOnLights function
    turnOnLights(isDaytime, isAway);

    return 0;
}

void turnOnLights(bool isDaytime, bool isAway)
{
    // Array of rooms in the house
    char rooms[5][10] = {"living", "kitchen", "bedroom", "bathroom", "garage"};

    // Initialize array of lights
    bool lights[5] = {false, false, false, false, false};

    // Loop through each room
    for(int i = 0; i < 5; i++)
    {
        // Check if it's daytime and if someone is away
        if(isDaytime && isAway)
        {
            // Turn off all lights
            lights[i] = false;
        }
        else
        {
            // Turn on all lights
            lights[i] = true;
        }

        // Print status of lights in current room
        printf("Lights in %s are %s.\n", rooms[i], lights[i] ? "on" : "off");
    }
}
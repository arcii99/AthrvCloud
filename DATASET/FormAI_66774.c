//FormAI DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>

// Define constants for room names
#define KITCHEN 1
#define LIVING_ROOM 2
#define BEDROOM 3

// Declare variables
int temperature;
int lighting;

// Function to set the temperature
void setTemperature(int room, int temp)
{
    if (room == KITCHEN)
    {
        temperature = temp;
        printf("Temperature in the Kitchen set to %d degrees.\n", temperature);
    }
    else if (room == LIVING_ROOM)
    {
        temperature = temp;
        printf("Temperature in the Living Room set to %d degrees.\n", temperature);
    }
    else if (room == BEDROOM)
    {
        temperature = temp;
        printf("Temperature in the Bedroom set to %d degrees.\n", temperature);
    }
    else
    {
        printf("Invalid room number.\n");
    }
}

// Function to set the lighting
void setLighting(int room, int light)
{
    if (room == KITCHEN)
    {
        lighting = light;
        printf("Lighting in the Kitchen set to %d.\n", lighting);
    }
    else if (room == LIVING_ROOM)
    {
        lighting = light;
        printf("Lighting in the Living Room set to %d.\n", lighting);
    }
    else if (room == BEDROOM)
    {
        lighting = light;
        printf("Lighting in the Bedroom set to %d.\n", lighting);
    }
    else
    {
        printf("Invalid room number.\n");
    }
}

int main()
{
    // Set the temperature and lighting in the Kitchen
    setTemperature(KITCHEN, 20);
    setLighting(KITCHEN, 1);

    // Set the temperature and lighting in the Living Room
    setTemperature(LIVING_ROOM, 22);
    setLighting(LIVING_ROOM, 2);

    // Set the temperature and lighting in the Bedroom
    setTemperature(BEDROOM, 18);
    setLighting(BEDROOM, 3);

    return 0;
}
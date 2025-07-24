//FormAI DATASET v1.0 Category: Smart home automation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to control the lights in the room
void controlLights(bool isOn)
{
    if(isOn)
    {
        printf("Lights are now on\n");
    }
    else
    {
        printf("Lights are now off\n");
    }
}

// Function to adjust the temperature of the room
void adjustTemperature(int temperature)
{
    printf("Temperature adjusted to %d degrees Celsius\n", temperature);
}

// Function to control the TV in the room
void controlTV(bool isOn)
{
    if(isOn)
    {
        printf("TV is now on\n");
    }
    else
    {
        printf("TV is now off\n");
    }
}

int main()
{
    // Initialize variables for the devices in the room
    bool lightsOn = true;
    int temperature = 22;
    bool tvOn = false;

    // Print out the current state of the devices in the room
    printf("Current state:\n");
    printf("- Lights are %s\n", lightsOn ? "on" : "off");
    printf("- Temperature is %d degrees Celsius\n", temperature);
    printf("- TV is %s\n", tvOn ? "on" : "off");

    // Turn off the lights
    controlLights(false);

    // Adjust the temperature to 20 degrees Celsius
    adjustTemperature(20);

    // Turn on the TV
    controlTV(true);

    // Print out the new state of the devices in the room
    printf("New state:\n");
    printf("- Lights are %s\n", lightsOn ? "on" : "off");
    printf("- Temperature is %d degrees Celsius\n", temperature);
    printf("- TV is %s\n", tvOn ? "on" : "off");

    return 0;
}
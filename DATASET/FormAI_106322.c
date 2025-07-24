//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>

// Define constants for each smart device
#define LIGHTS 1
#define THERMOSTAT 2
#define LOCKS 3

int main()
{
    int lights_status = 0; // Assuming lights are off initially
    int thermostat_temp = 72; // Assuming initial temperature is 72 degrees Fahrenheit
    int lock_status = 0; // Assuming doors are locked initially

    // Let's turn on lights
    printf("Turning on lights...\n");
    lights_status = 1;

    // Let's increase the temperature by 2 degrees
    printf("Increasing temperature by 2 degrees...\n");
    thermostat_temp += 2;

    // Let's unlock the doors
    printf("Unlocking doors...\n");
    lock_status = 1;

    // Let's turn off the lights
    printf("Turning off lights...\n");
    lights_status = 0;

    // Let's decrease the temperature by 2 degrees
    printf("Decreasing temperature by 2 degrees...\n");
    thermostat_temp -= 2;

    // Let's lock the doors
    printf("Locking doors...\n");
    lock_status = 0;

    // The following code determines the exact message displayed in the final step
    if (lights_status == 0 && thermostat_temp == 72 && lock_status == 0) {
        printf("The smart home is now in its default state.\n");
    } else {
        printf("The smart home has been customized.\n");
    }

    return 0;
}
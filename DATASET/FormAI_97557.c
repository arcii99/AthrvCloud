//FormAI DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>

void shape_shifter(int temp, int light, bool motion)
{
    if (temp > 30) // If temperature is greater than 30 degrees Celsius
    {
        printf("Air conditioner turned on.\n");
    }

    if (light < 25) // If light is less than 25
    {
        printf("Lights turned on.\n");
    }

    if (motion == true) // If motion is detected
    {
        printf("Security system activated.\n");
    }

    if (temp < 20) // If temperature is less than 20 degrees Celsius
    {
        printf("Heater turned on.\n");
    }

    if (light > 75) // If light is greater than 75
    {
        printf("Lights turned off.\n");
    }
}

int main()
{
    int temp = 27; // Temperature in degrees Celsius
    int light = 50; // Light level in percentage
    bool motion = true; // If motion is detected

    printf("Starting smart home automation...\n");
    printf("Current temperature: %d degrees Celsius.\n", temp);
    printf("Current light level: %d percent.\n", light);
    printf("Motion detected: %s.\n", motion ? "Yes" : "No");

    shape_shifter(temp, light, motion);

    printf("Smart home automation complete.\n");

    return 0;
}
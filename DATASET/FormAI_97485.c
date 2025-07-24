//FormAI DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define all the sensor variables
    int temperature, humidity, light, motion;

    // Set initial states for all sensors
    temperature = 20;
    humidity = 50;
    light = 0;
    motion = 0;

    // Check temperature
    if (temperature > 25)
    {
        // Alert the user that the temperature is getting too high
        printf("WARNING: Temperature is above 25 degrees Celsius!\n");

        // Turn on the air conditioning
        printf("Turning on the AC...\n");

        // Reduce the temperature to 22 degrees Celsius
        temperature = 22;
    }

    // Check humidity
    if (humidity > 60 && temperature > 22)
    {
        // Alert the user that the humidity is getting too high
        printf("WARNING: Humidity is above 60 percent!\n");

        // Turn on the dehumidifier
        printf("Turning on the dehumidifier...\n");

        // Reduce the humidity to 50 percent
        humidity = 50;
    }

    // Check light
    if (light > 100)
    {
        // Alert the user that the lights are too bright
        printf("WARNING: Lights are too bright!\n");

        // Turn off the lights
        printf("Turning off the lights...\n");

        // Set light level to 0
        light = 0;
    }

    // Check motion
    if (motion)
    {
        // Alert the user that there is motion detected
        printf("WARNING: Motion detected!\n");

        // Activate the security system
        printf("Activating the security system...\n");
    }

    // All checks have been completed, print current sensor states
    printf("\nCurrent Sensor States:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d percent\n", humidity);
    printf("Light: %d percent\n", light);
    printf("Motion: %s\n", motion ? "Detected" : "Not detected");

    // Return success
    return 0;
}
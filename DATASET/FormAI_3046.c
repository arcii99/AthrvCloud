//FormAI DATASET v1.0 Category: Smart home automation ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

// function to control the temperature
void controlTemperature(float temp, bool isSummer) {
    if (isSummer) {
        if (temp > 25.0) {
            printf("Temperature is too high, cooling the room...\n");
            // code to turn on the AC
        } else if (temp < 22.0) {
            printf("Temperature is too low, warming the room...\n");
            // code to turn off the AC
        } else {
            printf("Temperature is within range.\n");
            // code to maintain the AC state
        }
    } else {
        if (temp > 22.0) {
            printf("Temperature is too high, cooling the room...\n");
            // code to turn on the AC
        } else if (temp < 18.0) {
            printf("Temperature is too low, warming the room...\n");
            // code to turn on the heater
        } else {
            printf("Temperature is within range.\n");
            // code to maintain the AC and heater state
        }
    }
}

// function to control the lighting
void controlLighting(bool isNight) {
    if (isNight) {
        printf("Night time, turning on the lights...\n");
        // code to turn on the lights
    } else {
        printf("Day time, turning off the lights...\n");
        // code to turn off the lights
    }
}

// main function
int main() {
    // assume initial values
    float currentTemp = 20.0;
    bool isSummer = true;
    bool isNight = false;

    // simulate time change
    printf("Simulating time change...\n");
    isNight = true;

    // control temperature and lighting
    controlTemperature(currentTemp, isSummer);
    controlLighting(isNight);

    // simulate temperature change
    printf("Simulating temperature change...\n");
    currentTemp = 26.0;

    // control temperature and lighting again
    controlTemperature(currentTemp, isSummer);
    controlLighting(isNight);

    return 0;
}
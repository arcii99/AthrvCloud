//FormAI DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to automate turning lights on/off
void turnLightsOnOff(char* timeOfDay, int motionDetected) {
    if (strcmp(timeOfDay, "daytime") == 0 && motionDetected == 1) {
        printf("Turning lights on...\n");
    } else if (strcmp(timeOfDay, "nighttime") == 0 && motionDetected == 1) {
        printf("Turning lights on...\n");
    } else {
        printf("Lights are off.\n");
    }
}

// Function to automate turning thermostat up/down
void setThermostat(char* timeOfDay, int temperature, int desiredTemperature) {
    if (strcmp(timeOfDay, "daytime") == 0 && temperature > desiredTemperature) {
        printf("Turning thermostat down...\n");
    } else if (strcmp(timeOfDay, "nighttime") == 0 && temperature < desiredTemperature) {
        printf("Turning thermostat up...\n");
    } else {
        printf("Thermostat is set correctly.\n");
    }
}

int main() {
    char* timeOfDay = "daytime";
    int motionDetected = 1;
    int temperature = 70;
    int desiredTemperature = 72;

    // Turn lights on/off based on time of day and motion detected
    turnLightsOnOff(timeOfDay, motionDetected);

    // Set thermostat based on time of day and desired temperature
    setThermostat(timeOfDay, temperature, desiredTemperature);

    // Change time of day to nighttime and motion detected to false
    timeOfDay = "nighttime";
    motionDetected = 0;

    // Turn lights on/off and set thermostat again based on new conditions
    turnLightsOnOff(timeOfDay, motionDetected);
    setThermostat(timeOfDay, temperature, desiredTemperature);

    return 0;
}
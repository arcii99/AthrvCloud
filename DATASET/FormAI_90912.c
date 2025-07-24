//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

// Function to turn on/off lights
void turnOnLight(bool status) {
    if(status) {
        printf("Light is turned on.\n");
    } else {
        printf("Light is turned off.\n");
    }
}

// Function to control temperature
void controlTemperature(float temp, float lowerLimit, float upperLimit) {
    if(temp < lowerLimit) {
        printf("Temperature is too low. Turning on heater.\n");
    } else if(temp > upperLimit) {
        printf("Temperature is too high. Turning on air conditioner.\n");
    } else {
        printf("Temperature is maintained at a comfortable level.\n");
    }
}

// Function to control security systems
void controlSecurity(bool doorLocked, bool windowLocked) {
    if(doorLocked && windowLocked) {
        printf("Security systems are active.\n");
    } else {
        printf("Security systems need to be activated.\n");
    }
}

int main() {
    // Input parameters
    bool lightStatus = true;
    float currentTemp = 25.0;
    float lowerTempLimit = 22.0;
    float upperTempLimit = 28.0;
    bool doorLocked = true;
    bool windowLocked = false;

    // Automation rules
    if(lightStatus) {
        turnOnLight(true);
    }
    controlTemperature(currentTemp, lowerTempLimit, upperTempLimit);
    controlSecurity(doorLocked, windowLocked);

    // Changes made by user
    lightStatus = false;
    currentTemp = 20.0;
    doorLocked = false;

    // Updated automation rules
    if(lightStatus) {
        turnOnLight(true);
    }
    controlTemperature(currentTemp, lowerTempLimit, upperTempLimit);
    controlSecurity(doorLocked, windowLocked);

    return 0;
}
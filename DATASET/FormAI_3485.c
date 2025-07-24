//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define variables for sensors and devices
int temperatureSensor;
int lightSensor;
int doorSensor;
int windowSensor;
bool smartLight;
bool smartLock;
bool smartThermostat;

int main() {
    // Initialize sensors and devices
    temperatureSensor = 70;
    lightSensor = 50;
    doorSensor = 0;
    windowSensor = 0;
    smartLight = false;
    smartLock = false;
    smartThermostat = false;

    // Display current state of sensors and devices
    printf("Temperature: %d degrees Fahrenheit\n", temperatureSensor);
    printf("Light level: %d%%\n", lightSensor);
    printf("Door status: %d\n", doorSensor);
    printf("Window status: %d\n", windowSensor);
    printf("Smart Light: %d\n", smartLight);
    printf("Smart Lock: %d\n", smartLock);
    printf("Smart Thermostat: %d\n", smartThermostat);

    // Check temperature and adjust smart thermostat
    if (temperatureSensor >= 75) {
        smartThermostat = true;
        printf("Smart thermostat has been turned on to keep the temperature at a comfortable level.\n");
    }

    // Check light level and adjust smart light
    if (lightSensor <= 25) {
        smartLight = true;
        printf("Smart light has been turned on to provide adequate lighting.\n");
    } else {
        smartLight = false;
        printf("Smart light has been turned off since there is enough natural lighting.\n");
    }

    // Check door and window status and adjust smart lock
    if (doorSensor == 1 && windowSensor == 1) {
        smartLock = true;
        printf("Smart lock has been turned on to secure the house.\n");
    } else {
        smartLock = false;
        printf("Smart lock has been turned off since either the door or window is open.\n");
    }

    // Display updated state of sensors and devices
    printf("Temperature: %d degrees Fahrenheit\n", temperatureSensor);
    printf("Light level: %d%%\n", lightSensor);
    printf("Door status: %d\n", doorSensor);
    printf("Window status: %d\n", windowSensor);
    printf("Smart Light: %d\n", smartLight);
    printf("Smart Lock: %d\n", smartLock);
    printf("Smart Thermostat: %d\n", smartThermostat);

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>

void turnOnLights(int level) {
    if (level == 0) {
        printf("Lights are off.\n");
    } else {
        printf("Lights are at level %d\n", level);
        turnOnLights(level-1);
    }
}

void setTemperature(int temperature, int currentTemp) {
    if (temperature == currentTemp) {
        printf("Temperature is set to %d degrees.\n", temperature);
    } else if (temperature > currentTemp) {
        printf("Temperature is set to %d degrees.\n", currentTemp+1);
        setTemperature(temperature, currentTemp+1);
    } else {
        printf("Temperature is set to %d degrees.\n", currentTemp-1);
        setTemperature(temperature, currentTemp-1);
    }
}

void main() {
    printf("Welcome to Smart Home automation!\n");

    // Turn on lights
    printf("Turning on lights...\n");
    turnOnLights(5);

    // Set temperature
    printf("\nSetting temperature...\n");
    setTemperature(25, 20);

    printf("\nThank you for using Smart Home automation.");
}
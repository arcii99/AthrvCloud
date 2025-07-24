//FormAI DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool isLightOn = false;
    bool isTemperatureNormal = true;

    printf("Welcome to your smart home!\n");

    // Check temperature
    float temperature = 25.0;
    if (temperature > 28.0) {
        printf("Temperature is too high! Turning on air conditioning...\n");
        // Turn on air conditioning
        isTemperatureNormal = false;
    } else if (temperature < 16.0) {
        printf("Temperature is too low! Turning on heating...\n");
        // Turn on heating
        isTemperatureNormal = false;
    } else {
        printf("Temperature is normal.\n");
    }

    // Check light status
    if (isLightOn) {
        printf("Lights are on.\n");
    } else {
        printf("Lights are off. Turning on lights...\n");
        // Turn on lights
        isLightOn = true;
    }

    // Check door status
    bool isDoorLocked = false;
    if (isDoorLocked) {
        printf("Door is locked.\n");
    } else {
        printf("Door is unlocked. Locking door...\n");
        // Lock door
        isDoorLocked = true;
    }

    printf("System status: \nLight: %s\nTemperature: %s\nDoor: %s\n", isLightOn ? "On" : "Off", isTemperatureNormal ? "Normal" : "Abnormal", isDoorLocked ? "Locked" : "Unlocked");
    return 0;
}
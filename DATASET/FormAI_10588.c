//FormAI DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if user is at home or not
bool checkUserPresence() {
    // Code to detect user presence can be added here
    return true; // For now, let's assume user is always present
}

int main() {
    bool lightsOn = false;
    bool fanOn = false;
    bool acOn = false;

    if (checkUserPresence()) {
        // Turn on the lights
        lightsOn = true;
        printf("Lights turned on.\n");

        // Turn on the fan
        fanOn = true;
        printf("Fan turned on.\n");

        // Check room temperature
        int temperature = 25; // Assume room temperature is 25 degrees Celsius
        if (temperature > 30) {
            // If temperature is higher than 30, turn on the AC
            acOn = true;
            printf("AC turned on.\n");
        }
    } else {
        // Turn off the lights
        lightsOn = false;
        printf("Lights turned off.\n");

        // Turn off the fan
        fanOn = false;
        printf("Fan turned off.\n");

        // Turn off the AC
        acOn = false;
        printf("AC turned off.\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>

// Function to turn on the lights
void turnOnLights(int roomNumber, int lightNumber) {
    printf("Turning on the light in room %d, light %d\n", roomNumber, lightNumber);
    // Code to turn on the light
}

// Function to turn off the lights
void turnOffLights(int roomNumber, int lightNumber) {
    printf("Turning off the light in room %d, light %d\n", roomNumber, lightNumber);
    // Code to turn off the light
}

// Function to check the status of the light
void checkLightStatus(int roomNumber, int lightNumber) {
    // Code to check the status of the light
    int status = 1; // Assume light is on
    if (status == 1) {
        printf("The light in room %d, light %d is on.\n", roomNumber, lightNumber);
    } else {
        printf("The light in room %d, light %d is off.\n", roomNumber, lightNumber);
    }
}

int main() {
    // Some sample usage of the functions
    turnOnLights(1, 1);
    checkLightStatus(1, 1);
    turnOffLights(1, 1);
    checkLightStatus(1, 1);
    
    return 0;
}
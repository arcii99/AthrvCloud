//FormAI DATASET v1.0 Category: Smart home light control ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// Light struct to hold information about each light
typedef struct {
    int id;
    bool isOn;
    int brightnessLevel;
} Light;

// Array of lights
Light lights[MAX_LIGHTS];

// Function to turn on a specific light
void turnOn(int lightId) {
    if (lightId < 1 || lightId > MAX_LIGHTS) {
        printf("Invalid light id.\n");
        return;
    }
    lights[lightId - 1].isOn = true;
    printf("Light %d is now on.\n", lightId);
}

// Function to turn off a specific light
void turnOff(int lightId) {
    if (lightId < 1 || lightId > MAX_LIGHTS) {
        printf("Invalid light id.\n");
        return;
    }
    lights[lightId - 1].isOn = false;
    printf("Light %d is now off.\n", lightId);
}

// Function to set the brightness level of a specific light
void setBrightness(int lightId, int brightnessLevel) {
    if (lightId < 1 || lightId > MAX_LIGHTS) {
        printf("Invalid light id.\n");
        return;
    }
    if (brightnessLevel < 0 || brightnessLevel > 100) {
        printf("Invalid brightness level.\n");
        return;
    }
    lights[lightId - 1].brightnessLevel = brightnessLevel;
    if (lights[lightId - 1].isOn) {
        printf("Brightness of light %d set to %d%%.\n", lightId, brightnessLevel);
    }
}

int main() {
    // Initialize all lights to be off and brightness level to be 0%
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].isOn = false;
        lights[i].brightnessLevel = 0;
    }

    // Turn on light 3
    turnOn(3);

    // Set the brightness of light 3 to 50%
    setBrightness(3, 50);

    // Turn off light 1
    turnOff(1);

    // Set the brightness of light 1 to 75%
    setBrightness(1, 75);

    return 0;
}
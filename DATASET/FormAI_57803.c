//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of lights that can be controlled
#define MAX_NUM_LIGHTS 10

// Struct to represent a light in the smart home
typedef struct {
    int id; // The unique id of the light
    bool isOn; // Whether the light is currently on or off
} Light;

// Function for initializing the smart home lights
void initializeLights(Light *lights, int numLights) {
    for(int i = 0; i < numLights; i++) {
        lights[i].id = i + 1;
        lights[i].isOn = false;
    }
}

// Function for printing the current state of the smart home lights
void printLights(Light *lights, int numLights) {
    printf("Current state of smart home lights:\n\n");
    for(int i = 0; i < numLights; i++) {
        printf("Light %d: %s\n", lights[i].id, lights[i].isOn ? "On" : "Off");
    }
    printf("\n");
}

// Function for turning a specific light on/off
void toggleLight(Light *lights, int numLights, int lightId) {
    for(int i = 0; i < numLights; i++) {
        if(lights[i].id == lightId) {
            lights[i].isOn = !lights[i].isOn;
            break;
        }
    }
}

int main() {
    // Create an array of lights
    Light lights[MAX_NUM_LIGHTS];

    // Initialize the smart home lights
    initializeLights(lights, MAX_NUM_LIGHTS);

    // Print the current state of the smart home lights
    printLights(lights, MAX_NUM_LIGHTS);

    // Turn on light 2
    toggleLight(lights, MAX_NUM_LIGHTS, 2);

    // Print the current state of the smart home lights again
    printLights(lights, MAX_NUM_LIGHTS);

    return 0;
}
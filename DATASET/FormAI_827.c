//FormAI DATASET v1.0 Category: Smart home light control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 50

// Define a struct to represent a light
typedef struct {
    int id;                 // Unique ID of the light
    bool is_on;             // True if the light is on, false otherwise
    int brightness;         // Brightness level of the light (0-100)
} Light;

// A global array to store all the lights
Light lights[MAX_LIGHTS];

// Function to turn a light on or off
void switchLight(int id, bool on) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id == id) {   // We found the light with the given ID
            lights[i].is_on = on;   // Update the state of the light
            printf("Light %d is now %s\n", id, on ? "on" : "off");
            return;
        }
    }
    printf("Error: Could not find light with ID %d\n", id);
}

// Function to set the brightness of a light
void setBrightness(int id, int brightness) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id == id) {   // We found the light with the given ID
            lights[i].brightness = brightness; // Update the brightness level
            printf("Brightness of light %d set to %d\n", id, brightness);
            return;
        }
    }
    printf("Error: Could not find light with ID %d\n", id);
}

int main() {
    // Initialize the lights with some default values
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].is_on = false;
        lights[i].brightness = 0;
    }

    // Turn on the first light
    switchLight(1, true);

    // Set the brightness of the second light to 80%
    setBrightness(2, 80);

    // Turn off the third light
    switchLight(3, false);

    return 0;
}
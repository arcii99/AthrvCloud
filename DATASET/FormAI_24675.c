//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <string.h>

// Define the maximum number of lights in the house
#define MAX_LIGHTS 10

// Define a struct for a light
typedef struct {
    int id;          // The unique ID number for the light
    char name[20];   // A name to identify the light in the home
    int brightness;  // The current brightness level (0-100)
} Light;

// Define a struct to hold all the lights in the house
typedef struct {
    int count;       // The number of lights in the house
    Light lights[MAX_LIGHTS];  // An array of all the lights
} LightSystem;

// Function to turn on a light
void turnOn(LightSystem *system, int id) {
    for (int i = 0; i < system->count; i++) {
        if (system->lights[i].id == id) {
            system->lights[i].brightness = 100;
            printf("Turned on light: %s\n", system->lights[i].name);
            return;
        }
    }
    printf("Error: light with ID %d not found\n", id);
}

// Function to turn off a light
void turnOff(LightSystem *system, int id) {
    for (int i = 0; i < system->count; i++) {
        if (system->lights[i].id == id) {
            system->lights[i].brightness = 0;
            printf("Turned off light: %s\n", system->lights[i].name);
            return;
        }
    }
    printf("Error: light with ID %d not found\n", id);
}

// Function to set the brightness of a light
void setBrightness(LightSystem *system, int id, int brightness) {
    for (int i = 0; i < system->count; i++) {
        if (system->lights[i].id == id) {
            if (brightness < 0) {
                brightness = 0;
            } else if (brightness > 100) {
                brightness = 100;
            }
            system->lights[i].brightness = brightness;
            printf("Set brightness of light %s to %d\n", system->lights[i].name, brightness);
            return;
        }
    }
    printf("Error: light with ID %d not found\n", id);
}

int main() {
    // Initialize the LightSystem
    LightSystem system;
    system.count = 3;

    // Add some lights to the system
    Light light1 = {1, "Living Room Light", 0};
    Light light2 = {2, "Kitchen Light", 0};
    Light light3 = {3, "Bedroom Light", 0};
    system.lights[0] = light1;
    system.lights[1] = light2;
    system.lights[2] = light3;

    // Turn on the living room light
    turnOn(&system, 1);

    // Set the brightness of the kitchen light to 50
    setBrightness(&system, 2, 50);

    // Turn off the bedroom light
    turnOff(&system, 3);

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

// Define a light structure
typedef struct {
    int id;
    char name[20];
    int brightness;
    int isOn;
} Light;

// Define an array of lights
Light lights[MAX_LIGHTS];

// Function to turn a light on or off
void toggleLight(int id, int isOn) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id == id) {
            lights[i].isOn = isOn;
            return;
        }
    }
    printf("Could not find light with id %d\n", id);
}

// Function to set the brightness of a light
void setLightBrightness(int id, int brightness) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id == id) {
            lights[i].brightness = brightness;
            return;
        }
    }
    printf("Could not find light with id %d\n", id);
}

// Function to print the status of all lights
void printLightStatus() {
    printf("Light status:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].id != -1) {
            printf("%d. %s - ", lights[i].id, lights[i].name);
            if (lights[i].isOn) {
                printf("ON, %d%% brightness\n", lights[i].brightness);
            } else {
                printf("OFF\n");
            }
        }
    }
}

// Main function
int main() {
    // Initialize the lights array
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = -1;
    }

    // Add some lights
    lights[0].id = 0;
    strcpy(lights[0].name, "Living room");
    lights[0].brightness = 100;
    lights[0].isOn = 1;

    lights[1].id = 1;
    strcpy(lights[1].name, "Bedroom");
    lights[1].brightness = 50;
    lights[1].isOn = 0;

    // Print initial light status
    printLightStatus();

    // Turn on the living room light
    toggleLight(0, 1);
    printf("Living room light turned on\n");
    printLightStatus();

    // Dim the living room light
    setLightBrightness(0, 50);
    printf("Living room light dimmed to 50%%\n");
    printLightStatus();

    // Turn off the bedroom light
    toggleLight(1, 0);
    printf("Bedroom light turned off\n");
    printLightStatus();

    return 0;
}
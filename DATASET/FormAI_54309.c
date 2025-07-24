//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
// Donald Knuth-style smart home light control example program

#include <stdio.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// Define a Light struct to hold information about each light
typedef struct {
    int id;
    bool isOn;
    int brightness;
} Light;

// Define an array to store all available lights
Light lights[MAX_LIGHTS];

// Define a function to initialize all available lights
void initLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].isOn = false;
        lights[i].brightness = 0;
    }
}

// Define a function to turn on a specific light
void turnOnLight(int lightId, int brightness) {
    if (lightId < 0 || lightId >= MAX_LIGHTS) {
        printf("Invalid light ID.\n");
        return;
    }
    
    lights[lightId].isOn = true;
    lights[lightId].brightness = brightness;
    printf("Light %d is now on with brightness %d.\n", lightId, brightness);
}

// Define a function to turn off a specific light
void turnOffLight(int lightId) {
    if (lightId < 0 || lightId >= MAX_LIGHTS) {
        printf("Invalid light ID.\n");
        return;
    }
    
    lights[lightId].isOn = false;
    lights[lightId].brightness = 0;
    printf("Light %d is now off.\n", lightId);
}

// Define a function to print the current state of all available lights
void printLightStatus() {
    printf("Available lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: %s %d%% brightness\n", lights[i].id, lights[i].isOn ? "On" : "Off", lights[i].brightness);
    }
}

int main() {
    initLights();
    
    turnOnLight(2, 75);
    turnOnLight(5, 100);
    turnOffLight(2);
    printLightStatus();
    
    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// Struct to hold each light's data
struct Light {
    char name[20];
    int brightness;
    bool isOn;
};

// Function prototypes
void turnOnLight(struct Light * light);
void turnOffLight(struct Light * light);
void adjustBrightness(struct Light * light, int brightness);
void displayLights(struct Light lights[], int numLights);

int main() {
    // create some Light objects
    struct Light livingRoom = {"Living Room", 100, true};
    struct Light kitchen = {"Kitchen", 50, false};
    struct Light bedroom = {"Bedroom", 75, true};

    // create an array of Light objects
    struct Light lights[MAX_LIGHTS];
    lights[0] = livingRoom;
    lights[1] = kitchen;
    lights[2] = bedroom;
    int numLights = 3;

    // display all the current lights
    displayLights(lights, numLights);

    // turn off all the lights
    for (int i=0; i<numLights; i++) {
        turnOffLight(&lights[i]);
    }

    // display all the current lights again
    displayLights(lights, numLights);

    // turn on the living room light and set its brightness to 75
    turnOnLight(&livingRoom);
    adjustBrightness(&livingRoom, 75);

    // display all the current lights again
    displayLights(lights, numLights);

    // add a new light to the array
    struct Light newLight = {"Office", 25, true};
    lights[numLights] = newLight;
    numLights++;

    // display all the current lights one last time
    displayLights(lights, numLights);

    return 0;
}

void turnOnLight(struct Light * light) {
    light->isOn = true;
}

void turnOffLight(struct Light * light) {
    light->isOn = false;
}

void adjustBrightness(struct Light * light, int brightness) {
    light->brightness = brightness;
}

void displayLights(struct Light lights[], int numLights) {
    printf("Current Lights:\n");
    for (int i=0; i<numLights; i++) {
        printf("%s - %s, Brightness: %d%%\n", lights[i].name, lights[i].isOn ? "On" : "Off", lights[i].brightness);
    }
    printf("\n");
}
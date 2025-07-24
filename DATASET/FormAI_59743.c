//FormAI DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define constants */
#define MAX_LIGHTS 10

/* Define struct for each light */
typedef struct {
    bool isOn;
    int brightnessLevel;
} Light;

/* Function to turn on a light */
void turnOnLight(Light *light) {
    light->isOn = true;
}

/* Function to turn off a light */
void turnOffLight(Light *light) {
    light->isOn = false;
}

/* Function to adjust brightness of a light */
void adjustBrightness(Light *light, int brightnessLevel) {
    if (brightnessLevel >= 0 && brightnessLevel <= 100) {
        light->brightnessLevel = brightnessLevel;
    }
}

int main() {
    /* Create an array of lights */
    Light lights[MAX_LIGHTS];

    /* Initialize all lights as off and with brightness level 0 */
    for (int i=0; i<MAX_LIGHTS; i++) {
        lights[i].isOn = false;
        lights[i].brightnessLevel = 0;
    }

    /* Turn on and adjust brightness of first light */
    turnOnLight(&lights[0]);
    adjustBrightness(&lights[0], 50);

    /* Turn off second light */
    turnOffLight(&lights[1]);

    /* Print status of all lights */
    printf("Status of Lights:\n");
    for (int i=0; i<MAX_LIGHTS; i++) {
        if (lights[i].isOn) {
            printf("Light %d is on with brightness level %d%%.\n", i+1, lights[i].brightnessLevel);
        } else {
            printf("Light %d is off.\n", i+1);
        }
    }

    return 0;
}
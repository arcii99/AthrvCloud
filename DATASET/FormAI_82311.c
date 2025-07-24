//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

/*
 * The following structure defines a Light with its attributes.
 */
typedef struct Light_t {
    int brightness;
    bool isOn;
} Light;

/*
 * Switches ON a Light.
 */
void switchOn(Light *light) {
    light->isOn = true;
    printf("The light is now ON.\n");
}

/*
 * Switches OFF a Light.
 */
void switchOff(Light *light) {
    light->isOn = false;
    printf("The light is now OFF.\n");
}

/*
 * Sets brightness of a Light.
 */
void setBrightness(Light *light, int brightness) {
    light->brightness = brightness;
    printf("The brightness of light is set to %d\n", brightness);
}

/*
 * Main function that drives the program.
 */
int main() {
    Light light1 = {75, false};

    printf("Smart Home Light Control Center\n");
    printf("--------------------------------\n");

    printf("Default State: \n");
    printf("Brightness: %d\n", light1.brightness);
    printf("Is On? %s\n\n", light1.isOn ? "Yes" : "No");

    // Turn on the light
    switchOn(&light1);
    printf("Brightness: %d\n", light1.brightness);
    printf("Is On? %s\n\n", light1.isOn ? "Yes" : "No");

    // Set the brightness of the light
    setBrightness(&light1, 100);
    printf("Brightness: %d\n", light1.brightness);
    printf("Is On? %s\n\n", light1.isOn ? "Yes" : "No");

    // Turn off the light
    switchOff(&light1);
    printf("Brightness: %d\n", light1.brightness);
    printf("Is On? %s\n", light1.isOn ? "Yes" : "No");

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

typedef struct {
    int brightness;
    bool isOn;
    bool isDimmable;
    bool hasMotionSensor;
    bool hasColorPicker;
} Light;

void turnOn(Light *light) {
    light->isOn = LIGHT_ON;
    printf("Light is now ON.\n");
}

void turnOff(Light *light) {
    light->isOn = LIGHT_OFF;
    printf("Light is now OFF.\n");
}

void setBrightness(Light *light, int brightness) {
    if (light->isDimmable) {
        light->brightness = brightness;
        printf("Brightness set to %d.\n", brightness);
    } else {
        printf("This light cannot be dimmed.\n");
    }
}

void toggleMotionSensor(Light *light) {
    light->hasMotionSensor = !light->hasMotionSensor;
    printf("Motion sensor is now %s.\n", light->hasMotionSensor ? "ON" : "OFF");
}

void toggleColorPicker(Light *light) {
    light->hasColorPicker = !light->hasColorPicker;
    printf("Color picker is now %s.\n", light->hasColorPicker ? "ON" : "OFF");
}

int main() {
    // Create a new light
    Light myLight = { 80, false, true, false, true };

    // Turn on the light
    turnOn(&myLight);

    // Set brightness to 50%
    setBrightness(&myLight, 50);

    // Toggle motion sensor
    toggleMotionSensor(&myLight);

    // Toggle color picker
    toggleColorPicker(&myLight);

    // Turn off the light
    turnOff(&myLight);

    return 0;
}
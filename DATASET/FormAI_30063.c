//FormAI DATASET v1.0 Category: Smart home light control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define maximum number of lights
#define MAX_LIGHTS 10

// Define a structure for each light
typedef struct {
    bool state;     // true = on, false = off
    int brightness; // integer from 0 to 255
} Light;

// Define the array of lights
Light lights[MAX_LIGHTS];

// Function to turn a light on or off
void turn_light_on_off(int light_number, bool on) {
    if (light_number < 0 || light_number >= MAX_LIGHTS) {
        printf("Invalid light number %d\n", light_number);
        return;
    }
    lights[light_number].state = on;
    printf("Light %d turned %s\n", light_number, on ? "on" : "off");
}

// Function to set the brightness of a light
void set_light_brightness(int light_number, int brightness) {
    if (light_number < 0 || light_number >= MAX_LIGHTS) {
        printf("Invalid light number %d\n", light_number);
        return;
    }
    lights[light_number].brightness = brightness;
    printf("Light %d brightness set to %d\n", light_number, brightness);
}

// Function to print the state of all lights
void print_lights_state() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d is %s and brightness is %d\n", i, lights[i].state ? "on" : "off", lights[i].brightness);
    }
}

int main() {
    // Initialize the lights to off and brightness 0
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].state = false;
        lights[i].brightness = 0;
    }
    
    // Turn on light 5
    turn_light_on_off(5, true);
    
    // Set brightness of light 7 to 127
    set_light_brightness(7, 127);
    
    // Print the state of all lights
    print_lights_state();
    
    return 0;
}
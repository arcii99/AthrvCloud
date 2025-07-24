//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of lights that can be controlled
#define MAX_LIGHTS 10

// Define the structure of a light
typedef struct {
    bool is_on; // is the light on or off?
    int intensity; // the brightness of the light
    int color; // the color of the light
} Light;

// Define an array of lights
Light lights[MAX_LIGHTS];

// Define the function to turn a light on or off
void toggle_light(int light_number) {
    // Check if light_number is within the range of valid light numbers
    if (light_number < 0 || light_number >= MAX_LIGHTS) {
        printf("Invalid light number\n");
        return;
    }
    // Toggle the light
    if (lights[light_number].is_on) {
        lights[light_number].is_on = false;
        printf("Light %d turned off\n", light_number);
    } else {
        lights[light_number].is_on = true;
        printf("Light %d turned on\n", light_number);
    }
}

// Define the function to set the intensity of a light
void set_light_intensity(int light_number, int intensity) {
    // Check if light_number is within the range of valid light numbers
    if (light_number < 0 || light_number >= MAX_LIGHTS) {
        printf("Invalid light number\n");
        return;
    }
    // Set the intensity of the light
    lights[light_number].intensity = intensity;
    printf("Light %d intensity set to %d\n", light_number, intensity);
}

// Define the function to set the color of a light
void set_light_color(int light_number, int color) {
    // Check if light_number is within the range of valid light numbers
    if (light_number < 0 || light_number >= MAX_LIGHTS) {
        printf("Invalid light number\n");
        return;
    }
    // Set the color of the light
    lights[light_number].color = color;
    printf("Light %d color set to %d\n", light_number, color);
}

int main() {
    // Initialize all the lights to be off and have default values
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].is_on = false;
        lights[i].intensity = 50;
        lights[i].color = 0;
    }
    
    // Toggle the first light on
    toggle_light(0);
    
    // Set the intensity of the second light
    set_light_intensity(1, 75);
    
    // Set the color of the third light
    set_light_color(2, 1);
    
    // Toggle the first light off
    toggle_light(0);
    
    return 0;
}
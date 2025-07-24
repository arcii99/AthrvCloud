//FormAI DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

// Define the bright level states
enum BrightnessLevels {
    OFF,
    DIM,
    MEDIUM,
    BRIGHT
};

// Define the light state structure
struct LightState {
    bool isOn;
    enum BrightnessLevels brightnessLevel;
};

// Function to print the current state of the light
void printLightState(struct LightState light) {
    if (light.isOn) {
        printf("The light is currently on\n");
        switch (light.brightnessLevel) {
            case OFF: 
                printf("Brightness: Off\n");
                break;
            case DIM: 
                printf("Brightness: Dim\n");
                break;
            case MEDIUM: 
                printf("Brightness: Medium\n");
                break;
            case BRIGHT: 
                printf("Brightness: Bright\n");
                break;
            default: 
                printf("Unknown brightness level\n");
                break;
        }
    } else {
        printf("The light is currently off\n");
    }
}

int main() {
    // Initialize the light state
    struct LightState light = {
        .isOn = false,
        .brightnessLevel = OFF
    };

    // Print the initial state of the light
    printf("The light is currently off\n");

    // Simulate an event where a user turns on the light
    printf("User: Turn on the light\n");
    light.isOn = true;
    light.brightnessLevel = MEDIUM;
    printLightState(light);

    // Simulate an event where a user turns off the light
    printf("User: Turn off the light\n");
    light.isOn = false;
    printLightState(light);

    // Simulate an event where a user dims the light
    printf("User: Dim the light\n");
    light.isOn = true;
    light.brightnessLevel = DIM;
    printLightState(light);

    // Simulate an event where a user sets the light to maximum brightness
    printf("User: Set the light to maximum brightness\n");
    light.brightnessLevel = BRIGHT;
    printLightState(light);

    return 0;
}
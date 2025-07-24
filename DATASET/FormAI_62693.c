//FormAI DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the light on/off state
typedef enum {
    OFF = 0,
    ON = 1
} LightState;

// Define the light struct with its properties
typedef struct {
    const char* name;
    LightState state;
    int brightness;
} Light;

// Define the actual lights in the house
Light livingRoomLight = {"Living Room Light", OFF, 0};
Light bedroomLight = {"Bedroom Light", OFF, 0};
Light kitchenLight = {"Kitchen Light", OFF, 0};
Light bathroomLight = {"Bathroom Light", OFF, 0};

// Define a function to print the state of all lights in the house
void printLightStatus() {
    printf("Light Status:\n");
    printf("==============\n");
    printf("%s: %s - Brightness: %d%%\n", livingRoomLight.name, livingRoomLight.state == ON ? "ON" : "OFF", livingRoomLight.brightness);
    printf("%s: %s - Brightness: %d%%\n", bedroomLight.name, bedroomLight.state == ON ? "ON" : "OFF", bedroomLight.brightness);
    printf("%s: %s - Brightness: %d%%\n", kitchenLight.name, kitchenLight.state == ON ? "ON" : "OFF", kitchenLight.brightness);
    printf("%s: %s - Brightness: %d%%\n", bathroomLight.name, bathroomLight.state == ON ? "ON" : "OFF", bathroomLight.brightness);
    printf("\n");
}

// Define a function to control each light individually
void controlLight(Light* light, LightState state, int brightness) {
    // Update the state and brightness of the light
    light->state = state;
    light->brightness = brightness;

    // Print the updated status of the light
    printf("%s %s - Brightness: %d%%\n", light->name, state == ON ? "ON" : "OFF", brightness);

    // Print the status of all lights in the house
    printLightStatus();
}

int main() {
    // Welcome message
    printf("Welcome to your Smart Home Light Control System!\n");
    printf("===============================================\n");

    // Initial light status
    printLightStatus();

    // Control the lights
    controlLight(&livingRoomLight, ON, 100);
    controlLight(&bedroomLight, ON, 50);
    controlLight(&kitchenLight, ON, 75);
    controlLight(&bathroomLight, ON, 25);
    controlLight(&livingRoomLight, OFF, 0);
    controlLight(&kitchenLight, OFF, 0);
    controlLight(&bedroomLight, ON, 100);
    controlLight(&bathroomLight, ON, 100);

    // Goodbye message
    printf("Thank you for using your Smart Home Light Control System!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn the smart lights on or off
void turnLightOnOff(bool isOn) {
    if (isOn) {
        printf("Smart lights are on!\n");
    } else {
        printf("Smart lights are off!\n");
    }
}

// Function to change color of the smart lights
void changeLightColor(char* color) {
    printf("Smart lights color changed to %s!\n", color);
}

// Define struct for smart light device
typedef struct SmartLightDevice {
    char* name;
    bool isOn;
    char* color;
    void (*turnOnOff)(bool);
    void (*changeColor)(char*);
} SmartLightDevice;

int main() {
    // Initialize smart light device struct
    SmartLightDevice livingRoomLights = {
        .name = "Living Room Lights",
        .isOn = false,
        .color = "white",
        .turnOnOff = turnLightOnOff,
        .changeColor = changeLightColor
    };

    // Turn living room lights on
    livingRoomLights.isOn = true;
    livingRoomLights.turnOnOff(livingRoomLights.isOn);

    // Change living room light color to blue
    livingRoomLights.color = "blue";
    livingRoomLights.changeColor(livingRoomLights.color);

    // Turn living room lights off
    livingRoomLights.isOn = false;
    livingRoomLights.turnOnOff(livingRoomLights.isOn);

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// function to control the lights in the smart home
void lightControl(bool isLightOn, bool motionDetected) {
    if (isLightOn && !motionDetected) {
        printf("Turning off lights...\n");
        isLightOn = false;
    } else if (!isLightOn && motionDetected) {
        printf("Turning on lights...\n");
        isLightOn = true;
    } else {
        printf("Lights are already %s...\n", isLightOn ? "on" : "off");
    }
}


int main() {
    bool isLightOn = false;
    bool motionDetected = false;

    printf("Welcome to Smart Home Light Control!\n");

    // simulate motion detection by flipping value
    motionDetected = true;
    lightControl(isLightOn, motionDetected);

    // simulate light switch off manually
    isLightOn = true;
    motionDetected = false;
    lightControl(isLightOn, motionDetected);

    // simulate no motion detected, should turn off lights
    motionDetected = false;
    lightControl(isLightOn, motionDetected);

    printf("Thank you for using Smart Home Light Control!\n");

    return 0;
}
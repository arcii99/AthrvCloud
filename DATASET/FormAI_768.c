//FormAI DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>

// Recursive function to control the lights of a smart home
void smartHomeLightControl(int numLights, int currentLight, int *lightStatus) {
    if(currentLight == numLights) {
        // Print the status of all lights after control
        printf("Status of all lights: ");
        for(int i=0; i<numLights; i++) {
            if(lightStatus[i] == 1) {
                printf(" ON ");
            } else {
                printf(" OFF ");
            }
        }
        return;
    }
    // Toggle the light status
    if(lightStatus[currentLight] == 1) {
        lightStatus[currentLight] = 0;
    } else {
        lightStatus[currentLight] = 1;
    }
    // Control the next light
    smartHomeLightControl(numLights, currentLight+1, lightStatus);
    // Re-toggle the light status
    if(lightStatus[currentLight] == 1) {
        lightStatus[currentLight] = 0;
    } else {
        lightStatus[currentLight] = 1;
    }
    // Control the next light again
    smartHomeLightControl(numLights, currentLight+1, lightStatus);
}

int main() {
    int numLights = 3;
    int lightStatus[numLights];
    // Initializing all the lights as OFF
    for(int i=0; i<numLights; i++) {
        lightStatus[i] = 0;
    }
    // Control the lights recursively
    smartHomeLightControl(numLights, 0, lightStatus);
    return 0;
}
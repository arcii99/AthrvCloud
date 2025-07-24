//FormAI DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to control the lights
void light_control(bool isDaytime, bool isLampOn, int ambientLight, int thresholdLight) {
    if (isDaytime) {
        printf("It's daytime. Lights are off.\n");
    } else {
        if (isLampOn) {
            printf("Lamp is already on.\n");
        } else {
            if (ambientLight < thresholdLight) {
                printf("Turning lamp on.\n");
                isLampOn = true;
            } else {
                printf("Lamp is unnecessary, as the ambient light level is sufficient.\n");
            }
        }
    }
}

int main() {
    bool isDaytime = false;
    bool isLampOn = false;
    int ambientLight;
    int thresholdLight;
    
    printf("Enter ambient light level: ");
    scanf("%d", &ambientLight);
    
    printf("Enter threshold light level: ");
    scanf("%d", &thresholdLight);
    
    // Calling light control function
    light_control(isDaytime, isLampOn, ambientLight, thresholdLight);
    
    return 0;
}
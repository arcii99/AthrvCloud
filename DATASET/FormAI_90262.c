//FormAI DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

// Declare the function for controlling the lights
void controlLights(bool isOn) {
    if(isOn) {
        printf("Lights are now on!\n");
    } else {
        printf("Lights are now off.\n");
    }
}

int main() {
    bool isRoomDark = true;

    // Check if the room is dark
    if(isRoomDark) {
        // Turn on the lights
        controlLights(true);
    } else {
        // Dim the lights
        controlLights(false);
    }

    return 0;
}
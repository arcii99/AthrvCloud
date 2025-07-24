//FormAI DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdbool.h>

int main() {
    // initialize sensors and devices
    bool frontDoorOpen = false;
    bool windowOpen = true;
    bool lightsOn = false;
    bool tvOn = false;
    int temperature = 75;

    // monitor sensors and adjust devices accordingly
    while (true) {
        if (frontDoorOpen) {
            // turn lights on when front door is opened
            lightsOn = true;
            printf("Front door opened, turning lights on.\n");
        } else if (!frontDoorOpen && !windowOpen) {
            // turn lights off when front door is closed and window is closed
            lightsOn = false;
            printf("Front door closed and window closed, turning lights off.\n");
        }

        if (windowOpen && temperature > 80) {
            // turn fan on when window is open and temperature is over 80 degrees
            printf("Window open and temperature over 80, turning fan on.\n");
        } else {
            // turn fan off when window is closed or temperature is below 80 degrees
            printf("Window closed or temperature below 80, turning fan off.\n");
        }

        if (tvOn && frontDoorOpen) {
            // turn off TV when front door is opened
            tvOn = false;
            printf("Front door opened, turning TV off.\n");
        }

        if (temperature > 80) {
            // turn AC on when temperature is over 80 degrees
            printf("Temperature over 80, turning AC on.\n");
        } else if (temperature < 70) {
            // turn heat on when temperature is below 70 degrees
            printf("Temperature below 70, turning heat on.\n");
        }

        // simulate temperature changes
        temperature += 5;

        // simulate user interaction
        if (temperature > 90) {
            // user turns on TV and opens front door when it's hot
            tvOn = true;
            frontDoorOpen = true;
        } else {
            // user closes front door and window
            frontDoorOpen = false;
            windowOpen = false;
        }

        // wait for one second
        sleep(1);
    }

    return 0;
}
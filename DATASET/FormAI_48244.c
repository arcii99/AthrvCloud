//FormAI DATASET v1.0 Category: Smart home light control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

// Function to turn on the light
void turn_on_light() {
    printf("Light turned ON\n");
}

// Function to turn off the light
void turn_off_light() {
    printf("Light turned OFF\n");
}

// Main function
int main() {
    bool motion_detected = false;
    int current_light_status = LIGHT_OFF;

    while (true) {
        if (motion_detected) {
            if (current_light_status == LIGHT_OFF) {
                turn_on_light();
                current_light_status = LIGHT_ON;
            }
        } else {
            if (current_light_status == LIGHT_ON) {
                turn_off_light();
                current_light_status = LIGHT_OFF;
            }
        }

        // Wait for 2 seconds
        sleep(2);
    }

    return 0;
}
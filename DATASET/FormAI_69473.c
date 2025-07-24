//FormAI DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Set the default state of the lights
    bool lightsOn = false;
    
    while (true) {
        // Print the current state of the lights and prompt for user input
        printf("The lights are currently %s. Enter 'on' to turn them on or 'off' to turn them off.\n", lightsOn ? "on" : "off");
        char input[4];
        scanf("%s", input);
        
        // Process the user input
        if (strcmp(input, "on") == 0) {
            // Turn on the lights if they are not already on
            if (!lightsOn) {
                printf("Turning on the lights.\n");
                lightsOn = true;
            } else {
                printf("The lights are already on.\n");
            }
        } else if (strcmp(input, "off") == 0) {
            // Turn off the lights if they are not already off
            if (lightsOn) {
                printf("Turning off the lights.\n");
                lightsOn = false;
            } else {
                printf("The lights are already off.\n");
            }
        } else {
            // Invalid input
            printf("Invalid input. Please enter 'on' or 'off'.\n");
        }
    }
    
    return 0;
}
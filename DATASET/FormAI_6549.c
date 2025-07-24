//FormAI DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to turn on the lights
void turnOnLights() {
    printf("Lights turned on!\n");
}

// Function to turn off the lights
void turnOffLights() {
    printf("Lights turned off!\n");
}

int main() {
    char option[10];
    bool lightsOn = false;
    
    printf("Welcome to Smart Home Light Control!\n");
    
    while (true) {
        printf("\nPlease select an option:\n");
        printf("1. Turn on the lights\n");
        printf("2. Turn off the lights\n");
        printf("3. Exit\n");
        printf("Option: ");
        
        // Read user input
        fgets(option, 10, stdin);
        option[strcspn(option, "\n")] = 0; // Remove trailing newline
        
        // Check which option was selected
        if (strcmp(option, "1") == 0) {
            if (lightsOn) {
                printf("Lights are already on!\n");
            } else {
                turnOnLights();
                lightsOn = true;
            }
        } else if (strcmp(option, "2") == 0) {
            if (!lightsOn) {
                printf("Lights are already off!\n");
            } else {
                turnOffLights();
                lightsOn = false;
            }
        } else if (strcmp(option, "3") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option selected!\n");
        }
    }
    
    return 0;
}
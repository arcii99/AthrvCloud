//FormAI DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// Simple structure for individual lights
typedef struct Light {
    int id;
    bool status;
} Light;

// Global array to store the lights in the smart home
Light lights[MAX_LIGHTS];

// Function to turn on a specific light by ID
void turnLightOn(int lightId) {
    for(int i = 0; i < MAX_LIGHTS; i++) {
        if(lights[i].id == lightId) {
            lights[i].status = true;
            printf("Light %d turned on\n", lightId);
            return;
        }
    }

    printf("Light %d not found\n", lightId);
}

// Function to turn off a specific light by ID
void turnLightOff(int lightId) {
    for(int i = 0; i < MAX_LIGHTS; i++) {
        if(lights[i].id == lightId) {
            lights[i].status = false;
            printf("Light %d turned off\n", lightId);
            return;
        }
    }

    printf("Light %d not found\n", lightId);
}

// Function to print the status of all the lights in the smart home
void printAllLightsStatus() {
    printf("Current Lights Status:\n");

    for(int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: %s\n", lights[i].id, lights[i].status ? "On" : "Off");
    }
}

// Main function
int main(int argc, char **argv) {
    // Initialize the smart home with some sample lights
    lights[0].id = 1;
    lights[0].status = false;
    lights[1].id = 2;
    lights[1].status = true;
    lights[2].id = 3;
    lights[2].status = false;

    // Loop indefinitely to accept user input
    while(true) {
        char command[100];
        printf("Enter command (on/light_id, off/light_id, status, quit): ");
        fgets(command, sizeof(command), stdin);

        // Remove the newline character from the input
        command[strcspn(command, "\n")] = 0;

        // Parse and execute the user command
        if(strncmp(command, "on/", 3) == 0) {
            int lightId = atoi(command + 3);
            turnLightOn(lightId);
        }
        else if(strncmp(command, "off/", 4) == 0) {
            int lightId = atoi(command + 4);
            turnLightOff(lightId);   
        }
        else if(strcmp(command, "status") == 0) {
            printAllLightsStatus();
        }
        else if(strcmp(command, "quit") == 0) {
            printf("Exiting...\n");
            exit(0);
        }
        else {
            printf("Invalid command: %s\n", command);
        }
    }

    return 0;
}
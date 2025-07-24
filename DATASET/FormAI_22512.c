//FormAI DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define constants for maximum number of lights and their names
#define MAX_LIGHTS 10
#define MAX_NAME_LENGTH 20

// Define Light struct to hold data for each individual light
typedef struct {
    char name[MAX_NAME_LENGTH];
    bool isOn;
} Light;

// Declare global variables for array of lights and number of lights
Light lights[MAX_LIGHTS];
int numLights = 0;

// Declare function to add a new light
void addLight(char *name) {
    if (numLights < MAX_LIGHTS) {
        strcpy(lights[numLights].name, name);
        lights[numLights].isOn = false;
        numLights++;
        printf("%s has been added to your home.\n", name);
    } else {
        printf("You have reached the maximum number of lights.\n");
    }
}

// Declare function to turn a specific light on or off
void turnLight(char *name, bool isOn) {
    int i;
    for (i = 0; i < numLights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].isOn = isOn;
            printf("%s has been turned %s.\n", name, isOn ? "on" : "off");
            return;
        }
    }
    printf("%s is not a valid light name.\n", name);
}

// Declare function to print the status of all lights
void printLights() {
    int i;
    for (i = 0; i < numLights; i++) {
        printf("%s is %s.\n", lights[i].name, lights[i].isOn ? "on" : "off");
    }
}

int main() {
    // Add some example lights to start with
    addLight("Kitchen");
    addLight("Living room");
    
    // Let the user interact with the lights
    while (true) {
        char input[100];
        printf("What would you like to do? (add, turn, print, quit)\n");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
        
        // Check user input and call appropriate function
        if (strcmp(input, "add") == 0) {
            printf("Enter the name of the new light:\n");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = '\0';
            addLight(input);
        } else if (strcmp(input, "turn") == 0) {
            printf("Enter the name of the light you want to control:\n");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = '\0';
            printf("Enter 'on' or 'off':\n");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strcmp(input, "on") == 0) {
                turnLight(input, true);
            } else if (strcmp(input, "off") == 0) {
                turnLight(input, false);
            } else {
                printf("Invalid input.\n");
            }
        } else if (strcmp(input, "print") == 0) {
            printLights();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }
    
    printf("Goodbye!\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LIGHTS 10

// Struct for each light with name and on/off state
struct Light {
    char name[50];
    int on;
};

// Array of lights in the smart home system
struct Light lights[NUM_LIGHTS] = {
    {"Kitchen lights", 1},
    {"Living room lamps", 0},
    {"Bedroom light", 1},
    {"Bathroom light", 1},
    {"Garage light", 0},
    {"Basement light", 0},
    {"Porch light", 0},
    {"Attic light", 0},
    {"Office light", 1},
    {"Dining room chandelier", 1}
};

// Function to print the current state of all lights
void printLights() {
    printf("Current light status:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].on ? "On" : "Off");
    }
    printf("\n");
}

int main() {
    char input[50];
    int lightNum;

    printf("Welcome to the Smart Home Light Control system!\n");
    printLights();

    while (1) {
        printf("Enter the name of the light you want to toggle (or 'exit' to quit):\n");
        fgets(input, 50, stdin);
        input[strlen(input) - 1] = '\0'; // Remove the newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Find the index of the light with the given name
        lightNum = -1;
        for (int i = 0; i < NUM_LIGHTS; i++) {
            if (strcmp(input, lights[i].name) == 0) {
                lightNum = i;
                break;
            }
        }

        if (lightNum == -1) {
            printf("Invalid light name. Please try again.\n");
        } else {
            // Toggle the on/off state of the light
            lights[lightNum].on = !lights[lightNum].on;
            printf("%s is now %s.\n\n", lights[lightNum].name, lights[lightNum].on ? "on" : "off");
            printLights();
        }
    }

    printf("Goodbye!\n");
    return 0;
}
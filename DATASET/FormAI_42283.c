//FormAI DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define NUM_LIGHTS 4
#define LIGHT_ON 1
#define LIGHT_OFF 0

// Define global variables
int lightState[NUM_LIGHTS] = { LIGHT_OFF, LIGHT_OFF, LIGHT_OFF, LIGHT_OFF };

// Function to print the current state of the lights
void printLightState() {
    printf("Light State: ");
    for(int i=0; i<NUM_LIGHTS; i++) {
        printf("%d ", lightState[i]);
    }
    printf("\n");
}

// Function to turn on a specific light
void turnOnLight(int lightIndex) {
    lightState[lightIndex] = LIGHT_ON;
    printf("Turned on Light %d\n", lightIndex+1);
}

// Function to turn off a specific light
void turnOffLight(int lightIndex) {
    lightState[lightIndex] = LIGHT_OFF;
    printf("Turned off Light %d\n", lightIndex+1);
}

int main() {
    // Initialize variables
    char userInput[50];
    int lightIndex;

    // Print welcome message and initial light state
    printf("Welcome to Smart Home Light Control!\n");
    printLightState();

    // Loop to take user input and process it accordingly
    while(1) {
        printf("\nEnter a command (turn on, turn off, quit): ");
        fgets(userInput, 50, stdin);

        // Process user input to turn on a specific light
        if(strncmp(userInput, "turn on", 7) == 0) {
            // Parse input to get the light index
            lightIndex = atoi(userInput + 8) - 1;

            // Turn on the light or print an error message if input is invalid
            if(lightIndex >= 0 && lightIndex < NUM_LIGHTS) {
                turnOnLight(lightIndex);
            } else {
                printf("Invalid input. Please enter a number between 1 and %d.\n", NUM_LIGHTS);
            }
        }

        // Process user input to turn off a specific light
        else if(strncmp(userInput, "turn off", 8) == 0) {
            // Parse input to get the light index
            lightIndex = atoi(userInput + 9) - 1;

            // Turn off the light or print an error message if input is invalid
            if(lightIndex >= 0 && lightIndex < NUM_LIGHTS) {
                turnOffLight(lightIndex);
            } else {
                printf("Invalid input. Please enter a number between 1 and %d.\n", NUM_LIGHTS);
            }
        }

        // Exit the program if the user enters "quit"
        else if(strncmp(userInput, "quit", 4) == 0) {
            printf("Goodbye!\n");
            return 0;
        }

        // Print an error message if the user enters an invalid command
        else {
            printf("Invalid command. Please enter either 'turn on', 'turn off', or 'quit'.\n");
        }

        // Print the current state of the lights after processing each command
        printLightState();
    }
}
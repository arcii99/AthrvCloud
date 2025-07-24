//FormAI DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to turn on the lights
void turn_on_lights() {
    printf("Turning on the lights...\n");
}

// Function to turn off the lights
void turn_off_lights() {
    printf("Turning off the lights...\n");
}

// Function to turn on the air conditioning
void turn_on_air_conditioning() {
    printf("Turning on the air conditioning...\n");
}

// Function to turn off the air conditioning
void turn_off_air_conditioning() {
    printf("Turning off the air conditioning...\n");
}

int main() {
    // Initialize the state of the lights and the air conditioning to off
    int lights = 0;
    int air_conditioning = 0;

    // Prompt the user for input
    printf("Welcome to Smart Home Automation!\n");
    printf("What would you like to do? ");
    char input[50];
    fgets(input, 50, stdin);

    // Check the user's input and take the appropriate action
    if (strstr(input, "lights")) {
        if (lights == 0) {
            turn_on_lights();
            lights = 1;
        } else {
            turn_off_lights();
            lights = 0;
        }
    } else if (strstr(input, "air conditioning")) {
        if (air_conditioning == 0) {
            turn_on_air_conditioning();
            air_conditioning = 1;
        } else {
            turn_off_air_conditioning();
            air_conditioning = 0;
        }
    } else {
        printf("Sorry, I didn't understand that.\n");
    }

    return 0;
}
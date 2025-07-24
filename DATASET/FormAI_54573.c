//FormAI DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

// Simulating the current status of the lights and AC
bool lightsOn = false;
bool acOn = false;

// Function to toggle the lights
void toggleLights() {
    if (lightsOn) {
        lightsOn = false;
        printf("Lights turned off.\n");
    } else {
        lightsOn = true;
        printf("Lights turned on.\n");
    }
}

// Function to toggle the AC
void toggleAC() {
    if (acOn) {
        acOn = false;
        printf("AC turned off.\n");
    } else {
        acOn = true;
        printf("AC turned on.\n");
    }
}

int main() {

    // Simulating the input of the user
    printf("Enter 'l' to toggle lights and 'a' to toggle AC:\n");
    char userInput;
    scanf("%c", &userInput);

    // Checking the input and calling functions accordingly
    if (userInput == 'l') {
        toggleLights();
    } else if (userInput == 'a') {
        toggleAC();
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
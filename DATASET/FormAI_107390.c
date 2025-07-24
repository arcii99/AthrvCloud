//FormAI DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main () {

    // Let's create a simple program to control your home's lights.

    int light = 0;

    printf("Welcome to the Smart Home Automation program!\n\n");
    printf("Current light level: %d\n", light);

    // Prompt the user to turn the lights on or off.
    printf("Would you like to turn the lights on (1) or off (0)?\n");

    // Read in the user's choice.
    int choice;
    scanf("%d", &choice);

    // Update the light variable accordingly
    if (choice == 1) {
        light = 1;
    } else if (choice == 0) {
        light = 0;
    } else {
        printf("Invalid input. Defaulting to off.\n");
        light = 0;
    }

    // Print the new light level.
    printf("New light level: %d\n", light);

    return 0;
}
//FormAI DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>

// Define constants for light state
#define OFF 0
#define ON 1

// Define function to toggle the light state
int toggle(int lightState) {
    if(lightState == OFF) {
        return ON;
    }
    return OFF;
}

int main() {

    // Initialize light state to off
    int lightState = OFF;

    while(1) {

        // Display current light state
        printf("Current light state: %s\n", lightState == OFF ? "OFF" : "ON");

        // Prompt user for input
        char input;
        printf("Would you like to toggle the light state? (y/n): ");
        scanf(" %c", &input);

        // Handle user input
        if(input == 'y') {
            lightState = toggle(lightState);
            printf("Light state toggled.\n");
        } else if(input == 'n') {
            printf("Light state unchanged.\n");
        } else {
            printf("Invalid input.\n");
        }

        // Add delay to not spam output
        for(int i = 0; i < (1 << 28); i++);

        // Clear console for next iteration
        printf("\033[2J");

    }

    return 0;
}
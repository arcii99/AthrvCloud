//FormAI DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Function to turn on the light
void turnOnLight() {
    printf("The light is now turned on.\n");
}

// Function to turn off the light
void turnOffLight() {
    printf("The light is now turned off.\n");
}

int main() {
    // Variable to hold user input
    char input[10];

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Type 'on' to turn on the light, or 'off' to turn it off.\n");

    // Loop to continuously accept user input
    while (1) {
        printf(">> ");
        scanf("%s", input);

        // Compare user input to turn on the light
        if (strcmp(input, "on") == 0) {
            turnOnLight();
        }
        // Compare user input to turn off the light
        else if (strcmp(input, "off") == 0) {
            turnOffLight();
        }
        // Display error message for invalid user input
        else {
            printf("Invalid input! Please type 'on' or 'off'.\n");
        }
    }

    return 0;
}
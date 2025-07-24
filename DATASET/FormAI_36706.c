//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h> // Standard input-output header file
#include <stdlib.h> // Standard library header file
#include <stdbool.h> // For boolean values
#include <string.h> // For string operations

// Function to control lights in the smart home
void controlLights(bool livingRoom, bool kitchen, bool bedroom, bool bathroom) {
    // Check the status of each room and turn on/off the lights accordingly
    if (livingRoom) {
        printf("Living room lights turned on.\n");
    } else {
        printf("Living room lights turned off.\n");
    }
    if (kitchen) {
        printf("Kitchen lights turned on.\n");
    } else {
        printf("Kitchen lights turned off.\n");
    }
    if (bedroom) {
        printf("Bedroom lights turned on.\n");
    } else {
        printf("Bedroom lights turned off.\n");
    }
    if (bathroom) {
        printf("Bathroom lights turned on.\n");
    } else {
        printf("Bathroom lights turned off.\n");
    }
}

int main() {
    // Create variables to hold the status of each room
    bool livingRoom = false;
    bool kitchen = false;
    bool bedroom = false;
    bool bathroom = false;

    // Welcome message
    printf("Welcome to your smart home.\n");

    // Loop to keep the program running until the user decides to exit
    while (true) {
        // Ask the user which room they want to control
        printf("Which room would you like to control?\n");
        printf("1. Living room\n");
        printf("2. Kitchen\n");
        printf("3. Bedroom\n");
        printf("4. Bathroom\n");
        printf("5. Exit\n");

        // Get the user's input
        char input[10];
        fgets(input, 10, stdin);

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = 0;

        // Use a switch statement to determine which room to control
        switch (atoi(input)) {
            case 1:
                // Toggle the living room lights
                livingRoom = !livingRoom;
                break;
            case 2:
                // Toggle the kitchen lights
                kitchen = !kitchen;
                break;
            case 3:
                // Toggle the bedroom lights
                bedroom = !bedroom;
                break;
            case 4:
                // Toggle the bathroom lights
                bathroom = !bathroom;
                break;
            case 5:
                // Exit the program
                printf("Goodbye.\n");
                return 0;
            default:
                // Invalid input, try again
                printf("Invalid input.\n");
                break;
        }

        // Control the lights based on the current status
        controlLights(livingRoom, kitchen, bedroom, bathroom);
    }

    return 0;
}
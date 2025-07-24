//FormAI DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>

// Function to turn on the lights
void turnOnLights() {
    printf("The lights are turned on.\n");
}

// Function to turn off the lights
void turnOffLights() {
    printf("The lights are turned off.\n");
}

// Main function
int main() {
    char userInput; // Variable to hold user input

    printf("Welcome to the Smart Home Light Control Program.\n");
    printf("Press 'o' to turn on the lights and 'f' to turn off the lights.\n");
    printf("Press 'q' to quit the program.\n");
    printf("Enter your choice:");

    while((userInput = getchar()) != 'q') { // Run the program until user hits 'q'
        switch(userInput) { // Check user input
            case 'o': // If 'o' is pressed, turn on lights
                turnOnLights();
                break;
            case 'f': // If 'f' is pressed, turn off lights
                turnOffLights();
                break;
            default: // If any other key is pressed, ask user to try again
                printf("Invalid input. Please try again.");
                break;
        }
        printf("Enter your choice:"); // Ask user for input
    }

    printf("Thank you for using the Smart Home Light Control Program."); // Goodbye message

    return 0;
}
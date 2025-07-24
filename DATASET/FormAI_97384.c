//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

// Declare function to turn light on
void turnOnLight(int lightNumber) {
    printf("Turning on light %d\n", lightNumber);
}

// Declare function to turn light off
void turnOffLight(int lightNumber) {
    printf("Turning off light %d\n", lightNumber);
}

int main() {
    // Declare a boolean to keep track of whether the user wants to control the lights
    bool controlLights = true;

    // Declare variables to keep track of the state of the lights
    bool light1On = false;
    bool light2On = false;
    bool light3On = false;

    // Print welcome message and instructions to the user
    printf("Welcome to Smart Home Light Control! Type 'help' for a list of commands.\n");

    while (controlLights) {
        // Declare a buffer to hold the user's input
        char buffer[256];

        // Read the user's input from standard input
        printf("> ");
        fgets(buffer, 256, stdin);

        // Parse the user's input and execute the appropriate command
        if (strcmp(buffer, "help\n") == 0) {
            // Print a list of available commands
            printf("Available commands:\n");
            printf("    help\n");
            printf("    on <light number>\n");
            printf("    off <light number>\n");
            printf("    quit\n");
        } else if (strcmp(buffer, "quit\n") == 0) {
            // Stop controlling the lights
            controlLights = false;
        } else if (strncmp(buffer, "on ", 3) == 0) {
            // Parse the light number from the user's input
            int lightNumber = buffer[3] - '0';

            // Turn on the specified light
            switch (lightNumber) {
                case 1:
                    turnOnLight(1);
                    light1On = true;
                    break;
                case 2:
                    turnOnLight(2);
                    light2On = true;
                    break;
                case 3:
                    turnOnLight(3);
                    light3On = true;
                    break;
                default:
                    printf("Invalid light number. Please enter a number between 1 and 3.\n");
                    break;
            }
        } else if (strncmp(buffer, "off ", 4) == 0) {
            // Parse the light number from the user's input
            int lightNumber = buffer[4] - '0';

            // Turn off the specified light
            switch (lightNumber) {
                case 1:
                    turnOffLight(1);
                    light1On = false;
                    break;
                case 2:
                    turnOffLight(2);
                    light2On = false;
                    break;
                case 3:
                    turnOffLight(3);
                    light3On = false;
                    break;
                default:
                    printf("Invalid light number. Please enter a number between 1 and 3.\n");
                    break;
            }
        } else {
            // The user entered an unrecognized command
            printf("Unrecognized command. Type 'help' for a list of commands.\n");
        }
    }

    // Print a message to the user indicating that the program is shutting down
    printf("Thank you for using Smart Home Light Control!\n");

    return 0;
}
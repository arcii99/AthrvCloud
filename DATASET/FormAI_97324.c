//FormAI DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants for pin and state
#define LIGHT_PIN 23
#define ON 1
#define OFF 0

// Define function to control light
void control_light(int state) {
    if (state == ON) {
        printf("Light turned on!\n");
        // Code to turn on light on specific pin
    } else {
        printf("Light turned off!\n");
        // Code to turn off light on specific pin
    }
}

// Define function to get user input
bool get_user_input(char* input) {
    printf("Enter command (on/off): ");
    fgets(input, 10, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    if (strcmp(input, "on") == 0 || strcmp(input, "off") == 0) {
        return true;
    } else {
        printf("Invalid command.\n");
        return false;
    }
}

int main() {
    // Code to initialize pin for light
    printf("Smart home light control\n");

    while (true) {
        // Get user input
        char input[10];
        bool input_valid = false;
        while (!input_valid) {
            input_valid = get_user_input(input);
        }

        // Control light based on user input
        if (strcmp(input, "on") == 0) {
            control_light(ON);
        } else {
            control_light(OFF);
        }
    }

    return 0;
}
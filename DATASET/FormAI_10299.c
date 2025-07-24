//FormAI DATASET v1.0 Category: Smart home light control ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lights_on = false; // Initially, lights are off

int main() {
    char user_input;

    while (true) {
        printf("Welcome to your Smart Home Light Control System!\n");
        printf("Enter '1' to turn lights on, '0' to turn lights off and 'q' to quit: ");
        scanf("%c", &user_input);

        if (user_input == '1') {
            if (lights_on) { // If lights are already on
                printf("Lights are already on!\n");
            } else {
                printf("Turning lights on...\n");
                // Code to control lights
                lights_on = true;
            }
        } else if (user_input == '0') {
            if (lights_on) {
                printf("Turning lights off...\n");
                // Code to turn off lights
                lights_on = false;
            } else { // If lights are already off
                printf("Lights are already off!\n");
            }
        } else if (user_input == 'q') {
            printf("Goodbye! Thanks for using our Smart Home Light Control System.\n");
            break;
        } else { // If user enters wrong input
            printf("Invalid input! Please try again.\n");
        }

        // Clear input buffer to ignore previous inputs
        scanf("%*[^\n]");
        scanf("%*c");
    }

    return 0;
}
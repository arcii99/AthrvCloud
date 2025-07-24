//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains a specific substring
int contains(char* str, char* substr) {
    return strstr(str, substr) != NULL;
}

int main() {
    int lights_on = 0;
    char input[100];

    printf("Welcome to the Smart Home Light Control System.\n");

    while(1) {
        printf("\nPlease enter a command: ");
        fgets(input, sizeof(input), stdin);

        // Turn on/off lights
        if (contains(input, "turn on the lights") || contains(input, "lights on")) {
            if (lights_on) {
                printf("Error: Lights are already on.\n");
            } else {
                printf("Turning on the lights.\n");
                lights_on = 1;
            }
        } else if (contains(input, "turn off the lights") || contains(input, "lights off")) {
            if (!lights_on) {
                printf("Error: Lights are already off.\n");
            } else {
                printf("Turning off the lights.\n");
                lights_on = 0;
            }
        } 
        // Set brightness
        else if (contains(input, "set brightness")) {
            int brightness = atoi(strchr(input, ' ') + 1);

            if (brightness < 0 || brightness > 100) {
                printf("Error: Brightness level must be between 0 and 100.\n");
            } else {
                printf("Setting brightness to %d.\n", brightness);
            }
        } 
        // Set color
        else if (contains(input, "set color")) {
            char* color = strtok(strchr(input, ' ') + 1, "\n");

            if (strlen(color) == 0) {
                printf("Error: Please specify a color.\n");
            } else {
                printf("Setting color to %s.\n", color);
            }
        } 
        // Help
        else if (contains(input, "help")) {
            printf("Commands:\n"
                   "- Turn on the lights\n"
                   "- Turn off the lights\n"
                   "- Set brightness <level>\n"
                   "- Set color <color>\n"
                   "- Help\n");
        } 
        // Invalid command
        else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}
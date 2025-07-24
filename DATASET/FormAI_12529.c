//FormAI DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    int livingRoomLights = 0, bedroomLights = 0, kitchenLights = 0, bathroomLights = 0, backPorchLights = 0;
    char input[25];

    printf("Welcome to your smart home light control system!\n");

    while(1) {
        // Prompt user for input
        printf("\nEnter a command (example: \"turn on the living room lights\"): ");
        fgets(input, 25, stdin);

        // Parse input
        if(strncmp(input, "turn", 4) == 0) {
            // Turn on/off lights
            char *ptr = strtok(input, " ");
            ptr = strtok(NULL, " ");
            ptr = strtok(NULL, " ");

            if(strncmp(ptr, "living", 6) == 0) {
                if(strncmp(ptr+7, "on", 2) == 0) {
                    livingRoomLights = 1;
                    printf("Turning on the living room lights.\n");
                } else if(strncmp(ptr+7, "off", 3) == 0) {
                    livingRoomLights = 0;
                    printf("Turning off the living room lights.\n");
                } else {
                    printf("Invalid command.\n");
                }
            } else if(strncmp(ptr, "bedroom", 7) == 0) {
                if(strncmp(ptr+8, "on", 2) == 0) {
                    bedroomLights = 1;
                    printf("Turning on the bedroom lights.\n");
                } else if(strncmp(ptr+8, "off", 3) == 0) {
                    bedroomLights = 0;
                    printf("Turning off the bedroom lights.\n");
                } else {
                    printf("Invalid command.\n");
                }
            } else if(strncmp(ptr, "kitchen", 7) == 0) {
                if(strncmp(ptr+8, "on", 2) == 0) {
                    kitchenLights = 1;
                    printf("Turning on the kitchen lights.\n");
                } else if(strncmp(ptr+8, "off", 3) == 0) {
                    kitchenLights = 0;
                    printf("Turning off the kitchen lights.\n");
                } else {
                    printf("Invalid command.\n");
                }
            } else if(strncmp(ptr, "bathroom", 8) == 0) {
                if(strncmp(ptr+9, "on", 2) == 0) {
                    bathroomLights = 1;
                    printf("Turning on the bathroom lights.\n");
                } else if(strncmp(ptr+9, "off", 3) == 0) {
                    bathroomLights = 0;
                    printf("Turning off the bathroom lights.\n");
                } else {
                    printf("Invalid command.\n");
                }
            } else if(strncmp(ptr, "back", 4) == 0) {
                if(strncmp(ptr+5, "on", 2) == 0) {
                    backPorchLights = 1;
                    printf("Turning on the back porch lights.\n");
                } else if(strncmp(ptr+5, "off", 3) == 0) {
                    backPorchLights = 0;
                    printf("Turning off the back porch lights.\n");
                } else {
                    printf("Invalid command.\n");
                }
            } else {
                printf("Invalid command.\n");
            }
        } else if(strncmp(input, "status", 6) == 0) {
            // Get status of lights
            char *ptr = strtok(input, " ");
            ptr = strtok(NULL, " ");

            if(strncmp(ptr, "living", 6) == 0) {
                printf("The living room lights are %s.\n", livingRoomLights ? "on" : "off");
            } else if(strncmp(ptr, "bedroom", 7) == 0) {
                printf("The bedroom lights are %s.\n", bedroomLights ? "on" : "off");
            } else if(strncmp(ptr, "kitchen", 7) == 0) {
                printf("The kitchen lights are %s.\n", kitchenLights ? "on" : "off");
            } else if(strncmp(ptr, "bathroom", 8) == 0) {
                printf("The bathroom lights are %s.\n", bathroomLights ? "on" : "off");
            } else if(strncmp(ptr, "back", 4) == 0) {
                printf("The back porch lights are %s.\n", backPorchLights ? "on" : "off");
            } else {
                printf("Invalid command.\n");
            }
        } else if(strncmp(input, "exit", 4) == 0) {
            // Exit the program
            printf("Goodbye!\n");
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    return 0;
}
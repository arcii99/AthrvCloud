//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Welcome message and available options
    printf("Welcome to Smart Home Light Control!\n");
    printf("Below are the available options:\n");
    printf("1. Turn on all the lights\n");
    printf("2. Turn off all the lights\n");
    printf("3. Turn on specific lights\n");
    printf("4. Turn off specific lights\n");

    int option;
    char input[20];

    do {
        // Prompt user for input and read it
        printf("\nEnter your option: ");
        fgets(input, 20, stdin);
        option = atoi(input);

        switch (option) {
            case 1: // Turn on all the lights
                printf("\nTurning on all the lights...\n");
                // Code to turn on all lights goes here
                break;
            
            case 2: // Turn off all the lights
                printf("\nTurning off all the lights...\n");
                // Code to turn off all lights goes here
                break;

            case 3: // Turn on specific lights
                printf("\nEnter the name of the light (e.g. Living Room Light): ");
                fgets(input, 20, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                printf("\nTurning on %s...\n", input);
                // Code to turn on specific light goes here
                break;

            case 4: // Turn off specific lights
                printf("\nEnter the name of the light (e.g. Kitchen Light): ");
                fgets(input, 20, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                printf("\nTurning off %s...\n", input);
                // Code to turn off specific light goes here
                break;

            default:
                printf("\nInvalid option, please try again.\n");
        }
    } while(option < 1 || option > 4);

    printf("\nThank you for using Smart Home Light Control!\n");
    return 0;
}
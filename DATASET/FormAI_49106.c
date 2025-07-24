//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
    // Initializing variables for the light control system
    int lights = 0;
    char user_input[10];

    // Looping until the user exits the program
    while (1)
    {
        printf("Welcome to the Smart Home Light Control System\n");
        printf("To turn on the lights, enter 'on'.\nTo turn off the lights, enter 'off'.\nTo exit, enter 'exit'.\n");

        scanf("%s", &user_input);

        // Handling the user input to turn on the lights
        if (strcmp(user_input, "on") == 0)
        {
            lights = 1;
            printf("The lights are now turned on.\n");
        }
        // Handling the user input to turn off the lights
        else if (strcmp(user_input, "off") == 0)
        {
            lights = 0;
            printf("The lights are now turned off.\n");
        }
        // Handling the user input to exit the program
        else if (strcmp(user_input, "exit") == 0)
        {
            printf("Exiting the Smart Home Light Control System...\n");
            break;
        }
        // Handling invalid user inputs
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}
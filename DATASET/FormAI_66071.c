//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// function to turn on the lights
void turn_on_lights()
{
    printf("Lights have been turned on!\n");
}

// function to turn off the lights
void turn_off_lights()
{
    printf("Lights have been turned off!\n");
}

int main()
{
    // initialize the variables
    int light_status = 0;
    char user_input[10];

    // loop until the user enters "exit" command
    while (1)
    {
        // prompt the user to enter a command
        printf("Enter a command (on/off/exit): ");
        fgets(user_input, 10, stdin);

        // remove the newline character
        user_input[strcspn(user_input, "\n")] = 0;

        // check the user input
        if (strcmp(user_input, "on") == 0)
        {
            if (light_status == 0)
            {
                turn_on_lights();
                light_status = 1;
            }
            else
            {
                printf("Lights are already on!\n");
            }
        }
        else if (strcmp(user_input, "off") == 0)
        {
            if (light_status == 1)
            {
                turn_off_lights();
                light_status = 0;
            }
            else
            {
                printf("Lights are already off!\n");
            }
        }
        else if (strcmp(user_input, "exit") == 0)
        {
            // exit the program
            printf("Exiting the program...\n");
            sleep(1);
            exit(0);
        }
        else
        {
            printf("Invalid command! Please enter 'on', 'off', or 'exit'.\n");
        }
    }

    return 0;
}
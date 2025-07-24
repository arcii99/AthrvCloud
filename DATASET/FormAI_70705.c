//FormAI DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main()
{
    // Define variables
    int brightness = 100;
    char color[10] = "white";
    char command[50];

    // Display welcome message
    printf("Welcome to Smart Home Light Control Program\n");

    // Display current settings
    printf("Current Brightness: %d\n", brightness);
    printf("Current Color: %s\n", color);

    // Loop to accept user commands
    while (1)
    {
        // Accept user command
        printf("Enter a command: ");
        fgets(command, 50, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline character

        // Parse user command and execute corresponding action
        if (strcmp(command, "turn on") == 0)
        {
            printf("Turning on the light\n");
        }
        else if (strcmp(command, "turn off") == 0)
        {
            printf("Turning off the light\n");
        }
        else if (strcmp(command, "increase brightness") == 0)
        {
            brightness += 10;
            printf("Increasing brightness to %d\n", brightness);
        }
        else if (strcmp(command, "decrease brightness") == 0)
        {
            brightness -= 10;
            printf("Decreasing brightness to %d\n", brightness);
        }
        else if (strcmp(command, "set color") == 0)
        {
            printf("Enter a color: ");
            fgets(color, 10, stdin);
            color[strcspn(color, "\n")] = 0; // Remove trailing newline character
            printf("Setting color to %s\n", color);
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting program\n");
            break;
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    return 0;
}
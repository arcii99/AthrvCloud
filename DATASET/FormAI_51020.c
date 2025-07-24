//FormAI DATASET v1.0 Category: Smart home light control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[100];
    int lights_on = 0;

    printf("Welcome to Smart Home Light Control\n");

    while(1)
    {
        printf("\nEnter command: ");
        fgets(command, 100, stdin);

        if(strncmp(command, "turn on lights", 14) == 0)
        {
            if(lights_on == 0)
            {
                printf("Turning on lights\n");
                lights_on = 1;
            }
            else
            {
                printf("Lights are already on\n");
            }
        }
        else if(strncmp(command, "turn off lights", 15) == 0)
        {
            if(lights_on == 1)
            {
                printf("Turning off lights\n");
                lights_on = 0;
            }
            else
            {
                printf("Lights are already off\n");
            }
        }
        else if(strncmp(command, "help", 4) == 0)
        {
            printf("Available commands:\n");
            printf("  turn on lights\n");
            printf("  turn off lights\n");
            printf("  help\n");
            printf("  exit\n");
        }
        else if(strncmp(command, "exit", 4) == 0)
        {
            printf("Exiting Smart Home Light Control\n");
            break;
        }
        else
        {
            printf("Invalid command, type 'help' for a list of available commands\n");
        }
    }

    return 0;
}
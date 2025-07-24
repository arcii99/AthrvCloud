//FormAI DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1

int main()
{
    int light_status = LIGHT_OFF;
    char command[10];

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("The light is currently turned %s.\n", light_status == LIGHT_OFF ? "off" : "on");
    printf("Enter 'on' or 'off' to control the light, or 'exit' to quit.\n");

    while (1) 
    {
        printf("> ");

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character

        if (strcmp(command, "on") == 0) 
        {
            if (light_status == LIGHT_OFF) 
            {
                printf("Turning on the light...\n");
                light_status = LIGHT_ON;
            }
            else
            {
                printf("The light is already turned on.\n");
            }
        } 
        else if (strcmp(command, "off") == 0) 
        {
            if (light_status == LIGHT_ON) 
            {
                printf("Turning off the light...\n");
                light_status = LIGHT_OFF;
            }
            else
            {
                printf("The light is already turned off.\n");
            }
        } 
        else if (strcmp(command, "exit") == 0) 
        {
            printf("Exiting the Smart Home Light Control System.\n");
            break;
        } 
        else 
        {
            printf("Invalid command. Please enter 'on' or 'off', or 'exit' to quit.\n");
        }
    }

    return 0;
}
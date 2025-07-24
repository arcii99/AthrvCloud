//FormAI DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{
    int light_status[5] = {0, 0, 0, 0, 0};
    char command[50];

    printf("Welcome to Smart Home Light Control System\n");

    while (1)
    {
        printf("\nEnter command (eg. switch on 1): ");
        fgets(command, 50, stdin);

        // tokenize the command string
        char *token;
        token = strtok(command, " \n");
        int action;
        int light;

        // parse the action and light number
        if (token != NULL)
        {
            if (strcmp(token, "switch") == 0)
            {
                token = strtok(NULL, " \n");
                if (strcmp(token, "on") == 0)
                {
                    action = 1;
                }
                else if (strcmp(token, "off") == 0)
                {
                    action = 0;
                }
                else
                {
                    printf("Invalid command\n");
                    continue;
                }
                token = strtok(NULL, " \n");
                if (token != NULL)
                {
                    light = atoi(token);
                    if (light < 1 || light > 5)
                    {
                        printf("Invalid light number\n");
                        continue;
                    }
                }
                else
                {
                    printf("Invalid command\n");
                    continue;
                }
            }
            else
            {
                printf("Invalid command\n");
                continue;
            }
        }
        else
        {
            printf("Invalid command\n");
            continue;
        }

        // perform the action
        if (action == 1)
        {
            printf("Turning on light %d\n", light);
            light_status[light-1] = 1;
        }
        else if (action == 0)
        {
            printf("Turning off light %d\n", light);
            light_status[light-1] = 0;
        }
        else
        {
            printf("Invalid command\n");
            continue;
        }

        // print the current state of the lights
        printf("Current light status:");
        for (int i = 0; i < 5; i++)
        {
            if (light_status[i] == 1)
            {
                printf(" %d:on", i+1);
            }
            else
            {
                printf(" %d:off", i+1);
            }
        }
        printf("\n");
    }

    return 0;
}
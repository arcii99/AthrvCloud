//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 50

// Function to parse the user's command
void parse_command(char* command, int* x, int* y)
{
    char* token = strtok(command, " ");
    *x = atoi(token);

    token = strtok(NULL, " ");
    *y = atoi(token);
}

int main()
{
    int x = 0;
    int y = 0;
    char command[MAX_COMMAND_LENGTH];
    bool is_running = true;

    printf("Welcome to the C Drone Remote Control Program!\n");

    while(is_running)
    {
        printf("Enter a command in the format 'x y' (or 'quit' to exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if(strcmp(command, "quit\n") == 0)
        {
            is_running = false;
            printf("Exiting program.\n");
        }
        else
        {
            parse_command(command, &x, &y);

            printf("Moving drone to location (%d, %d).\n", x, y);
        }
    }

    return 0;
}
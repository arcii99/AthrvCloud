//FormAI DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
    char command[MAX_LENGTH];
    char output[MAX_LENGTH];
    FILE *fp;

    printf("Welcome to the System Administration Console!\n");
    printf("Enter a command to execute ('exit' to quit):\n");

    while (1)
    {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0)
        {
            printf("Exiting the console...\n");
            break;
        }

        fp = popen(command, "r");
        if (fp == NULL)
        {
            printf("Error: failed to execute command!\n");
            continue;
        }

        printf("\nOutput of '%s':\n", command);
        while (fgets(output, sizeof(output), fp) != NULL)
        {
            printf("%s", output);
        }

        pclose(fp);
    }

    return 0;
}
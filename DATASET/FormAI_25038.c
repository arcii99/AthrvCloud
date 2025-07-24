//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_TOKENS 100

int main()
{
    char input[MAX_INPUT_LENGTH];
    char *tokens[MAX_TOKENS];
    int token_count = 0;

    printf("Surprised Unix-Like Shell Started!\n");

    while (1)
    {
        printf(">> ");
        fgets(input, MAX_INPUT_LENGTH, stdin);

        token_count = 0;
        tokens[token_count] = strtok(input, " \n");

        while (tokens[token_count] != NULL && token_count < MAX_TOKENS)
        {
            token_count++;
            tokens[token_count] = strtok(NULL, " \n");
        }

        if (tokens[0] == NULL)
        {
            printf("No command entered. Please try again.\n");
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0)
        {
            printf("Exiting Surprised Unix-Like Shell...\n");
            break;
        }

        if (strcmp(tokens[0], "surprise") == 0)
        {
            printf("Wow, you found the 'surprise' command! Congratulations!\n");
            continue;
        }

        pid_t pid = fork();
        if (pid == 0)
        {
            execvp(tokens[0], tokens);
            printf("Command not found: %s\n", tokens[0]);
            exit(1);
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            printf("Error: fork() failed!\n");
            exit(1);
        }
    }

    return 0;
}
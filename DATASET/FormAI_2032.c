//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGUMENTS 10

int main()
{
    char *history[50];     // Array to store up to 50 most recent commands
    int command_count = 0; // Counter for recent commands
    char input[MAX_COMMAND_LENGTH];
    char *args[MAX_NUM_ARGUMENTS];
    int should_run = 1;

    memset(history, '\0', sizeof(history)); // Initializes array to null byte values for safe string operations

    while (should_run)
    {
        printf("osh>");
        fflush(stdout);

        fgets(input, MAX_COMMAND_LENGTH, stdin); // Reads input line
        input[strcspn(input, "\n")] = 0;         // Strips new line character at end of input

        char *token = strtok(input, " ");

        if (token != NULL)
        {
            history[command_count] = strdup(input); // Saves input line to history array
            command_count++;

            int i = 0;
            while (token != NULL)
            {
                args[i] = token;
                i++;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            if (strcmp(args[0], "exit") == 0) // Exits shell if command is "exit"
            {
                should_run = 0;
            }
            else if (strcmp(args[0], "cd") == 0) // Changes current working directory if command is "cd"
            {
                if (args[1] == NULL)
                {
                    printf("Error: no directory specified.\n");
                }
                else
                {
                    if (chdir(args[1]) != 0) // chdir() returns -1 if directory did not change
                    {
                        printf("Error: %s\n", strerror(errno)); // errno contains error message
                    }
                }
            }
            else if (strcmp(args[0], "history") == 0) // Prints up to 50 most recent commands if command is "history"
            {
                int start_index = 0;

                if (command_count > 10) // Only prints most recent 10 commands if total commands is larger than 10
                {
                    start_index = command_count - 10;
                }

                for (int j = start_index; j < command_count; j++) // Loops through history array and prints non-null commands
                {
                    if (history[j] != NULL)
                    {
                        printf("%d: %s\n", j + 1, history[j]);
                    }
                }
            }
            else // Executes any other command by creating a child process and running execvp() on it
            {
                pid_t pid = fork();
                if (pid == -1)
                {
                    printf("Error: fork() failed.\n");
                }
                else if (pid == 0)
                {
                    if (execvp(args[0], args) < 0)
                    {
                        printf("Error: %s\n", strerror(errno));
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    wait(NULL);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 100

/**
 * @brief Structure to hold user inputted command and its arguments
 */
typedef struct
{
    char* args[MAX_COMMANDS + 1];
} Command;

/**
 * @brief Parse user input into a Command structure
 *
 * @param input User input string
 * @param cmd Pointer to Command structure to fill
 * @return int Number of arguments found in input
 */
int parse_input(char* input, Command* cmd)
{
    int argc = 0;
    char* token = strtok(input, " \n");
    while (token != NULL && argc < MAX_COMMANDS)
    {
        cmd->args[argc++] = token;
        token = strtok(NULL, " \n");
    }
    cmd->args[argc] = NULL;
    return argc;
}

int main(int argc, char* argv[])
{
    char input[MAX_COMMAND_LENGTH];
    Command cmd;

    while (1)
    {
        printf(">> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0)
        {
            break;
        }

        int num_args = parse_input(input, &cmd);

        pid_t pid = fork();

        if (pid == -1)
        {
            printf("Failed to fork process\n");
            continue;
        }
        else if (pid == 0)
        {
            // Child process
            execvp(cmd.args[0], cmd.args);
            printf("Failed to execute command\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    printf("Exiting shell\n");
    return EXIT_SUCCESS;
}
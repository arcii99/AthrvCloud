//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUMBER_OF_ARGUMENTS 512

/**
 * Splits the user input in to individual commands
 * @param input The user input
 * @param commands The individual commands
 */
void split_input_into_commands(char* input, char** commands) {
    char* split_character = strchr(input, '|');
    int index = 0;

    while (split_character != NULL) {
        *split_character = '\0';
        commands[index++] = input;
        input = split_character + 1;
        split_character = strchr(input, '|');
    }

    if (strlen(input) > 0) {
        commands[index++] = input;
    }

    commands[index] = NULL;
}

/**
 * Splits the individual commands in to arguments
 * @param input The individual command
 * @param arguments The individual arguments
 * @return The number of arguments
 */
int split_command_into_arguments(char* input, char** arguments) {
    char* split_character = strchr(input, ' ');
    int index = 0;

    while (split_character != NULL) {
        *split_character = '\0';
        arguments[index++] = input;
        input = split_character + 1;
        split_character = strchr(input, ' ');
    }

    if (strlen(input) > 0) {
        arguments[index++] = input;
    }

    arguments[index] = NULL;

    return index;
}

/**
 * Executes a single command
 * @param command The command to execute
 */
void execute_command(char* command) {
    char* arguments[MAX_NUMBER_OF_ARGUMENTS];
    int number_of_arguments = split_command_into_arguments(command, arguments);

    if (strcmp(arguments[0], "exit") == 0) {
        exit(0);
    }

    pid_t child_process_id = fork();

    if (child_process_id == 0) {
        execvp(arguments[0], arguments);
        exit(0);
    } else {
        int child_status;
        waitpid(child_process_id, &child_status, 0);
    }
}

/**
 * Executes a list of commands piped together
 * @param commands The commands to execute
 */
void execute_commands(char** commands) {
    int descriptors[2];
    pid_t child_process_id;
    int input;

    for (int i = 0; commands[i] != NULL; i++) {
        pipe(descriptors);

        child_process_id = fork();

        if (child_process_id == 0) {
            dup2(input, 0);

            if (commands[i + 1] != NULL) {
                dup2(descriptors[1], 1);
            }

            close(descriptors[0]);

            execute_command(commands[i]);
            exit(0);
        } else {
            int child_status;
            waitpid(child_process_id, &child_status, 0);
            close(descriptors[1]);
            input = descriptors[0];
        }
    }
}

/**
 * The main function
 */
int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char* commands[MAX_NUMBER_OF_ARGUMENTS];

    while (1) {
        printf("> ");

        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strlen(command) > 0 && command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        split_input_into_commands(command, commands);
        execute_commands(commands);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 512
#define TRUE 1

/* Function Declarations */
void print_prompt(void);
int read_input(char* input);
void remove_newline(char* input);
int parse_input(char* input, char** arguments);
void execute_command(char** arguments);

/* Main Function */
int main(void) {
    char input[BUFFER_SIZE];
    char* arguments[100];
    int status;

    while (TRUE) {
        print_prompt();

        if (read_input(input) == -1) {
            continue;
        }

        remove_newline(input);

        if (strcmp(input, "exit") == 0) {
            printf("Exiting Shell...\n");
            break;
        }

        if (parse_input(input, arguments) == -1) {
            continue;
        }

        if (fork() == 0) {
            execute_command(arguments);
            exit(EXIT_SUCCESS);
        }
        else if (wait(&status) != -1) {
            printf("Command Complete\n");
        }
    }

    return EXIT_SUCCESS;
}

/* Utility Functions */

/* Prints the shell prompt */
void print_prompt(void) {
    printf("PeacefulShell:> ");
}

/* Reads input from the user */
int read_input(char* input) {
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        return -1;
    }
    return 0;
}

/* Removes newline characters from input */
void remove_newline(char* input) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            return;
        }
    }
}

/* Parses command line input */
int parse_input(char* input, char** arguments) {
    char* argument;
    int argument_count = 0;

    argument = strtok(input, " ");

    while (argument != NULL) {
        arguments[argument_count] = argument;
        argument = strtok(NULL, " ");
        argument_count++;
    }

    arguments[argument_count] = NULL;

    if (argument_count == 0) {
        printf("Please Enter a Command\n");
        return -1;
    }

    return 0;
}

/* Executes commands */
void execute_command(char** arguments) {
    if (execvp(arguments[0], arguments) == -1) {
        printf("Command Failed\n");
        exit(EXIT_FAILURE);
    }
}
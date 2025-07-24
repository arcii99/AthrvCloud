//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */
#define MAX_HISTORY 10 /* Maximum number of commands to store in history */

char *history[MAX_HISTORY]; // Maintains the history of the last 10 commands entered
int history_count = 0;

/**
 * Function that reads the input command from the user
 */
void read_input(char *args[], int *should_run)
{
    char c;
    int position = 0;
    char *buffer = (char*) malloc(sizeof(char) * MAX_LINE);
    int i = 0;
    
    if (!buffer) { // Check if memory allocation for buffer was successful
        fprintf(stderr, "Allocation error!\n");
        exit(EXIT_FAILURE);
    }

    while (1) { // Read and parse the input command
        c = getchar();
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            break;
        } else {
            buffer[position] = c;
        }
        position++;
    }

    if (strlen(buffer) > 0) { // Check if any input was entered
        history[history_count] = (char*) malloc(sizeof(char) * strlen(buffer));
        strncpy(history[history_count], buffer, strlen(buffer));
        history_count = (history_count + 1) % MAX_HISTORY;
    }

    char *token = strtok(buffer, " ");
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) { // Check if user entered the exit command
        *should_run = 0;
    }

    free(buffer); // Free the buffer allocated to read input
}

/**
 * Function that executes the command entered by the user
 */
void execute_command(char *args[])
{
    pid_t pid;
    int status;
    pid = fork(); // Create a child process

    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) { // Execute the command entered by user
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error creating child process");
    } else { // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/**
 * Function that displays the history of the last 10 commands entered
 */
void show_history()
{
    int i;
    int start = (history_count + 1) % MAX_HISTORY;

    for (i = 0; i < MAX_HISTORY; i++) {
        int index = (start + i) % MAX_HISTORY;
        if (history[index] != NULL) {
            printf("%d. %s\n", i+1, history[index]);
        }
    }
}

int main(void)
{
    char *args[MAX_LINE/2 + 1]; /* Command args */
    int should_run = 1; /* Flag to determine when to exit program */
    int i;

    while (should_run) {
        printf("mysh> ");
        fflush(stdout);
        read_input(args, &should_run);

        if (strcmp(args[0], "history") == 0) { // Check if user entered the history command
            show_history();
            continue;
        }

        execute_command(args); // Execute the command entered by the user
    }

    for (i = 0; i < MAX_HISTORY; i++) { // Free up the memory used to store history
        if (history[i] != NULL) {
            free(history[i]);
        }
    }

    return 0; // Exit the program
}
//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 // max length of command
#define MAX_HISTORY 10 // max number of commands stored in history

char* history[MAX_HISTORY]; // array to store history of commands
int history_count = 0; // counter for history array


// function to read user input
int read_input(char* args[])
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    int num_args = 0;
    
    getline(&buffer, &buffer_size, stdin); // read input from user
    
    // parse input and store arguments in array
    char* token = strtok(buffer, " \n");
    while (token != NULL) {
        args[num_args] = token;
        num_args++;
        token = strtok(NULL, " \n");
    }
    args[num_args] = NULL; // set last argument to NULL
    
    // return number of arguments
    return num_args;
}


// function to execute command
void execute_command(char* args[])
{
    pid_t pid = fork(); // create child process
    
    if (pid < 0) { // fork failed
        printf("Error: Fork failed\n");
    }
    else if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) { // execute command
            printf("Error: Command not found\n");
        }
    }
    else { // parent process
        wait(NULL); // wait for child to finish
    }
}


// function to display command history
void show_history()
{
    printf("\nCommand History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d. %s\n", i+1, history[i]);
    }
}


int main()
{
    char *args[MAX_LINE/2 + 1]; // array to store arguments
    int should_run = 1; // flag to exit loop
    
    while (should_run) {
        printf("osh>");
        
        // read input from user
        int num_args = read_input(args);
        
        if (num_args == 0) { // empty command
            continue;
        }
        else if (strcmp(args[0], "exit") == 0) { // exit command
            should_run = 0;
        }
        else if (strcmp(args[0], "history") == 0) { // history command
            show_history();
        }
        else { // other command
            if (history_count < MAX_HISTORY) { // store command in history
                history[history_count] = strdup(args[0]);
                history_count++;
            }
            else { // history is full, shift elements to make space
                free(history[0]);
                for (int i = 0; i < MAX_HISTORY-1; i++) {
                    history[i] = history[i+1];
                }
                history[MAX_HISTORY-1] = strdup(args[0]);
            }
            execute_command(args); // execute command
        }
    }
    
    return 0;
}
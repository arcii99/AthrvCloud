//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

/* Function to split the input command into tokens */
int tokenize(char* command, char** tokens) {

    /* Initializing variables */
    int index = 0;
    char* token;

    /* Splitting the command using strtok() */
    token = strtok(command, " \n");

    /* Looping over the tokens and storing in array */
    while(token != NULL) {
        tokens[index] = token;
        index++;
        token = strtok(NULL, " \n");
    }
    tokens[index] = NULL;

    /* Returning the number of tokens */
    return index;
}

/* Function to execute the command entered by user */
void execute(char** tokens) {

    /* Initializing variables */
    pid_t pid, wpid;
    int status;

    /* Creating child process */
    pid = fork();

    /* Checking if child process is created successfully or not */
    if (pid == 0) {
        /* Executing the command in child process */
        if (execvp(tokens[0], tokens) == -1) {
            /* If error occurs */
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } 
    else if (pid < 0) {
        /* If error occurs */
        perror("Error");
    }
    else {
        /* Parent process */
        do {
            /* Waiting for child to complete */
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/* Main function */
int main(void) {

    /* Initializing variables */
    char *args[MAX_LINE/2 + 1];
    int should_run = 1;
    char command[MAX_LINE];

    /* Printing welcome message */
    printf("Welcome to Statistical Shell!\n");

    /* Looping till user enters exit command */
    while(should_run) {

        /* Clearing the buffer */
        fflush(stdout);

        /* Taking input command from user */
        printf("Statistical Shell > ");
        fgets(command, MAX_LINE, stdin);

        /* Splitting the command into tokens */
        int num_tokens = tokenize(command, args);

        /* Checking if the command is exit */
        if(strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) {
            printf("Exiting Statistical Shell!\n");
            should_run = 0;
        }
        else {
            /* Executing the command */
            execute(args);
        }
    }
    return 0;
}
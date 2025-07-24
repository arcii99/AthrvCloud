//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define MAX_SIZE 1024 // maximum length of input command


void prompt() {
    printf("shell> "); // custom shell prompt
}


void clear_buffer(char* buffer) {
    memset(buffer, 0, MAX_SIZE); // clear buffer to prevent memory leaks
}


void parse_command(char* buffer, char** argv) {
    char* token = strtok(buffer, " \n"); // tokenize the command
    int i = 0;

    while (token != NULL) {
        argv[i] = token; // store arguments in argv array
        i++;
        token = strtok(NULL, " \n");
    }

    argv[i] = NULL; // last argument must be NULL
}


void execute_command(char** argv) {
    pid_t pid = fork(); // create child process

    if (pid == 0) {
        // this is the child process
        if (execvp(argv[0], argv) < 0) {
            printf("Error: could not execute command.\n");
            exit(1);
        }
    }
    else if (pid > 0) {
        // this is the parent process
        wait(NULL); // wait for child to finish
    }
    else {
        printf("Error: could not fork process.\n");
        exit(1);
    }
}


int main() {
    char buffer[MAX_SIZE];
    char* argv[MAX_SIZE/2 + 1];
    int should_run = 1;

    while (should_run) {
        prompt();
        fflush(stdout);

        fgets(buffer, sizeof(buffer), stdin); // read input command
        clear_buffer(buffer); // make sure buffer is empty of junk data
        parse_command(buffer, argv); // parse the command into arguments

        if (strcmp(argv[0], "exit") == 0) {
            should_run = 0; // terminate the program
        }
        else {
            execute_command(argv); // execute the command
        }
    }

    return 0;
}
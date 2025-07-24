//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
// A Basic Unix-like Shell Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // maximum length of a single command
#define MAX_ARGUMENTS 10 // maximum number of arguments in a command 
#define MAX_HISTORY 10 // maximum number of commands saved in history

char history[MAX_HISTORY][MAX_COMMAND_LENGTH]; // array to store history
int historyCount = 0; // count of commands in history

// function that prints the shell prompt
void printShellPrompt() {
    printf(">> ");
}

// function that reads a command from the user
void readCommand(char* command) {
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0; // remove newline character
}

// function that saves a command to history
void saveToHistory(char* command) {
    if (historyCount < MAX_HISTORY) {
        strcpy(history[historyCount], command);
        historyCount++;
    } else {
        int i;
        for (i = 0; i < MAX_HISTORY - 1; i++) {
            strcpy(history[i], history[i + 1]);
        }
        strcpy(history[MAX_HISTORY - 1], command);
    }
}

// function that displays the command history
void displayHistory() {
    int i;
    for (i = 0; i < historyCount; i++) {
        printf("%d. %s\n", i + 1, history[i]);
    }
}

// function that executes the command
void executeCommand(char** args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE); // if executed command fails, exit with failure
    } else if (pid < 0) { // error forking
        perror("Error");
    } else { // parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// function that parses the user's command and arguments
void parseCommand(char* command, char** args) {
    int i = 0;
    char* token = strtok(command, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

// main function
int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGUMENTS];
    int exitShell = 0;

    printf("Welcome to My Shell!\n");

    while (!exitShell) {
        printShellPrompt();
        readCommand(command);
        saveToHistory(command);

        if (strcmp(command, "exit") == 0) { // exit command
            printf("Goodbye!\n");
            exitShell = 1;
        } else if (strcmp(command, "history") == 0) { // history command
            displayHistory();
        } else { // execute command
            parseCommand(command, args);
            executeCommand(args);
        }
    }

    return 0;
}
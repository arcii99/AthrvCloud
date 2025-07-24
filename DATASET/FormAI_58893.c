//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // max command length
#define MAX_ARGS 10 // max number of arguments per command
#define MAX_PATHS 10 // max number of paths to search for executables
#define MAX_PATH_LENGTH 500 // max length of each path
#define MAX_HISTORY 100 // max number of commands to remember in history

char* paths[MAX_PATHS]; // array of paths to search for executables
int numPaths; // number of paths in paths array
char* history[MAX_HISTORY]; // array of past commands
int historyCount = 0; // number of commands in history

void parseCommand(char* command, char** args);
void executeCommand(char** args);
void addToHistory(char* command);

int main() {

    // initialize paths
    paths[0] = "/usr/bin";
    paths[1] = "/usr/local/bin";
    numPaths = 2;

    char str[MAX_COMMAND_LENGTH];

    while(1) {

        printf("$ ");
        fgets(str, MAX_COMMAND_LENGTH, stdin);

        // remove newline character from input
        str[strcspn(str, "\n")] = 0;

        // check if input is empty
        if (strlen(str) == 0) {
            continue;
        }

        char* args[MAX_ARGS];
        parseCommand(str, args);

        // check for built-in commands
        if (strcmp(args[0], "history") == 0) {
            for (int i = 0; i < historyCount; i++) {
                printf("%d. %s\n", i+1, history[i]);
            }
            continue;
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                chdir(getenv("HOME"));
            } else {
                chdir(args[1]);
            }
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        executeCommand(args);

        addToHistory(str);

    }

    return 0;
}

void parseCommand(char* command, char** args) {

    for(int i = 0; i < MAX_ARGS; i++) {
        args[i] = NULL;
    }

    char* token = strtok(command, " ");

    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

}

void executeCommand(char** args) {

    int status;

    pid_t pid = fork();

    if (pid == 0) { // child process

        // search for executable in paths
        for (int i = 0; i < numPaths; i++) {
            char path[MAX_PATH_LENGTH];
            strcpy(path, paths[i]);
            strcat(path, "/");
            strcat(path, args[0]);
            if (access(path, X_OK) == 0) {
                args[0] = path;
                break;
            }
        }

        execv(args[0], args);
        printf("Command not found: %s\n", args[0]);
        exit(1);

    } else if (pid < 0) { // error occurred
        printf("Fork failed.\n");
        exit(1);
    } else { // parent process
        waitpid(pid, &status, 0);
    }

}

void addToHistory(char* command) {

    if (historyCount == MAX_HISTORY) {
        // shift elements in history array to make room for new command
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            history[i] = history[i+1];
        }
        history[historyCount-1] = command;
    } else {
        history[historyCount] = command;
        historyCount++;
    }

}
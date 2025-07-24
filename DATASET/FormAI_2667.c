//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// Function prototypes
void *executeCommands(void *args);
void tokenizeInput(char *input, char **tokens, int *numTokens);
int runCommand(char **tokens, int numTokens, int *bgFlag);

int main() {
    char input[MAX_INPUT_SIZE];
    pthread_t t_id;

    // Run the shell in an infinite loop
    while (1) {
        printf(">");
        fflush(stdout);
        fgets(input, MAX_INPUT_SIZE, stdin);
        int numTokens = 0;
        char *tokens[MAX_NUM_TOKENS];
        int bgFlag = 0;

        // Tokenize the input
        tokenizeInput(input, tokens, &numTokens);

        // Create a new thread for executing the commands
        if (pthread_create(&t_id, NULL, executeCommands, tokens) != 0) {
            printf("Failed to create thread\n");
            return 1;
        }
        // Wait for the thread to finish executing
        pthread_join(t_id, NULL);

    }
    return 0;
}

// Function to execute the input commands in a separate thread
void *executeCommands(void *args) {
    char **tokens = (char **) args;
    int numTokens = 0;
    int bgFlag = 0;

    // Tokenize the input
    tokenizeInput(tokens[0], tokens, &numTokens);

    // Execute the command
    if (runCommand(tokens, numTokens, &bgFlag) != 0) {
        printf("Command execution failed\n");
    }

    return NULL;
}

// Function to tokenize the input
void tokenizeInput(char *input, char **tokens, int *numTokens) {
    char *token = strtok(input, " \t\r\n");
    while (token != NULL && *numTokens < MAX_NUM_TOKENS) {
        tokens[*numTokens] = token;
        (*numTokens)++;
        token = strtok(NULL, " \t\r\n");
    }
    tokens[*numTokens] = NULL;
}

// Function to execute the command
int runCommand(char **tokens, int numTokens, int *bgFlag) {
    pid_t pid;
    int status;
    int i;
    int ampPos = -1;

    // Check if the command ends with '&'
    for (i = 0; i < numTokens; i++) {
        if (strcmp(tokens[i], "&") == 0) {
            *bgFlag = 1;
            ampPos = i;
            tokens[i] = NULL;
            break;
        }
    }

    // Fork a new process to execute the command
    pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return -1;
    } else if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) < 0) {
            printf("Command not found\n");
            exit(1);
        }
    } else {
        // Parent process
        // Wait for the child process to finish executing
        if (*bgFlag == 0) {
            while (wait(&status) != pid);
        }
        // Reset '&' symbol position
        if (ampPos > 0) {
            tokens[ampPos] = "&";
        }
    }

    return 0;
}
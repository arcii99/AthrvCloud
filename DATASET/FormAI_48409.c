//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_SIZE 1024

// Function to take input from user
char *readInput(void) {
    char *buffer = NULL;
    ssize_t bufsize = 0; // have getline allocate a buffer for us
    getline(&buffer, &bufsize, stdin);
    return buffer;
}

// Function to tokenize the input string by spaces
char **tokenizeInput(char *input) {
    int position = 0;
    char **tokens = malloc(MAX_SIZE * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "Allocation error!\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \n\r\t\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        token = strtok(NULL, " \n\r\t\a");
    }
    tokens[position] = NULL;

    return tokens;
}

// Function that executes the command using fork and exec system calls
int executeCommand(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error while executing command.");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // Error forking
        perror("Forking error.");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

// Function that redirects input/output of the command
int executeCommandWithRedirection(char **args, char *inputFile, char *outputFile, int append) {
    pid_t pid, wpid;
    int status;
    int in, out;

    if (inputFile) {
        in = open(inputFile, O_RDONLY);
        if (in == -1) {
            perror("Failed to open input file.");
            return 0;
        }
        dup2(in, STDIN_FILENO);
        close(in);
    }

    if (outputFile) {
        if (append) {
            out = open(outputFile, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        } else {
            out = open(outputFile, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
        }
        if (out == -1) {
            perror("Failed to open output file.");
            return 0;
        }
        dup2(out, STDOUT_FILENO);
        close(out);
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error while executing command.");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { // Error forking
        perror("Forking error.");
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main() {
    char *inputString;
    char **args;
    int status = 1;
    int redirectInput = 0;
    int redirectOutput = 0;
    int appendOutput = 0;
    char *inputFile;
    char *outputFile;

    while (status) {
        printf(">>> "); // Shell prompt
        inputString = readInput(); // Get the input from user
        args = tokenizeInput(inputString); // Tokenize the input string

        // Check for input/output redirection
        int i = 0;
        while (args[i] != NULL) {
            if (strcmp(args[i], "<") == 0) { // Input redirection
                redirectInput = 1;
                inputFile = args[i + 1];
                args[i] = NULL;
            } else if (strcmp(args[i], ">") == 0) { // Output redirection
                redirectOutput = 1;
                outputFile = args[i + 1];
                args[i] = NULL;
            } else if (strcmp(args[i], ">>") == 0) { // Append output redirection
                redirectOutput = 1;
                appendOutput = 1;
                outputFile = args[i + 1];
                args[i] = NULL;
            }
            i++;
        }

        if (args[0] != NULL) {
            if (strcmp(args[0], "cd") == 0) { // Built-in cd command
                if (args[1] == NULL) {
                    fprintf(stderr, "cd command requires an argument.\n");
                } else {
                    if (chdir(args[1]) != 0) {
                        perror("Error while changing directory.");
                    }
                }
            } else if (strcmp(args[0], "exit") == 0) { // Built-in exit command
                status = 0;
            } else { // Non-built-in commands
                if (redirectInput || redirectOutput) {
                    executeCommandWithRedirection(args, inputFile, outputFile, appendOutput);
                } else {
                    executeCommand(args);
                }
            }
        }

        free(inputString);
        free(args);
    }

    return 0;
}
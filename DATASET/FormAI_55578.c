//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 128

void parse_input(char* input, char** tokens, int* num_tokens);
void execute_command(char** tokens, int num_tokens);

int main() {
    char input[MAX_INPUT_SIZE];
    char* tokens[MAX_TOKENS];
    int num_tokens;
    while (1) {
        // print the shell prompt
        printf("$ ");
        fflush(stdout);
        
        // read input from user
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';   // remove the newline character
        
        // parse the input into tokens
        parse_input(input, tokens, &num_tokens);
        
        // execute the command
        execute_command(tokens, num_tokens);
        
        // free memory used by tokens
        for (int i = 0; i < num_tokens; i++) {
            free(tokens[i]);
        }
    }
    return 0;
}

void parse_input(char* input, char** tokens, int* num_tokens) {
    char* token;
    *num_tokens = 0;
    
    // tokenize the input string
    token = strtok(input, " ");
    while (token != NULL) {
        tokens[*num_tokens] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tokens[*num_tokens], token);
        (*num_tokens)++;
        token = strtok(NULL, " ");
    }
    // add a null terminator to the end of the token array
    tokens[*num_tokens] = NULL;
}

void execute_command(char** tokens, int num_tokens) {
    // check if the user wants to exit
    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    }
    
    // create a child process to execute the command
    pid_t pid;
    int status;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    if (pid == 0) {   // child process
        // execute the command
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "command not found\n");
            exit(1);
        }
    }
    else {   // parent process
        // wait for the child process to finish
        waitpid(pid, &status, 0);
    }
}
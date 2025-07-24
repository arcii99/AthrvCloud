//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_BUFFER_LEN 1024
#define MAX_ARGS 64

// Function to parse input
void parse_input(char* input, char** parsed_input_array) {
    for(int i = 0; i < MAX_ARGS; i++) {
        parsed_input_array[i] = strsep(&input, " ");
        if(parsed_input_array[i] == NULL)
            break;
    }
}

// Function to execute commands
void execute_commands(char** parsed_input_array) {
    pid_t pid = fork();

    if(pid == -1) {
        printf("Failed to create a child process!\n");
        return;
    }
    else if(pid == 0) {
        if(execvp(parsed_input_array[0], parsed_input_array) < 0)
            printf("Command not found!\n");
        exit(0);
    }
    else {
        wait(NULL);
        return;
    }
}

int main() {
    char input_buffer[MAX_BUFFER_LEN];
    char* parsed_input_array[MAX_ARGS];
    memset(parsed_input_array, 0, MAX_ARGS);

    while(1) {
        printf(">>> ");
        fgets(input_buffer, MAX_BUFFER_LEN, stdin);
        if(strcmp(input_buffer, "exit\n") == 0 || strcmp(input_buffer, "exit") == 0)
            break;
        input_buffer[strcspn(input_buffer, "\n")] = 0;
        parse_input(input_buffer, parsed_input_array);
        execute_commands(parsed_input_array);

        memset(input_buffer, 0 , MAX_BUFFER_LEN);
        memset(parsed_input_array, 0, MAX_ARGS * sizeof(char*));
    }

    return 0;   
}
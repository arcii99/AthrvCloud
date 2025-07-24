//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENT_COUNT 64

int main() {
    char* input_command = (char*) malloc(MAX_COMMAND_LENGTH);
    char* arguments[MAX_ARGUMENT_COUNT];
    int status;
    
    while (1) {
        printf("user@shell:~$ ");
        fgets(input_command, MAX_COMMAND_LENGTH, stdin);
        input_command[strcspn(input_command, "\n")] = '\0';
        if (strcmp(input_command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        
        int argument_count = 0;
        char* token = strtok(input_command, " ");
        while (token != NULL) {
            arguments[argument_count++] = token;
            token = strtok(NULL, " ");
        }
        arguments[argument_count] = NULL;
        
        pid_t child_pid = fork();
        if (child_pid == 0) {
            execvp(arguments[0], arguments);
            printf("Error: Command not found!\n");
            exit(1);
        } else {
            waitpid(-1, &status, 0);
        }
    }
    
    free(input_command);
    return 0;
}
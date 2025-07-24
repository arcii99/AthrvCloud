//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char input[MAX_INPUT_LENGTH];
    pid_t pid;
    int status;
    
    printf("Interoperable Shell\n");
    printf("---------------------\n");
    
    while (1) {
        printf(">$ ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting.\n");
            exit(0);
        }

        pid = fork();

        if (pid == -1) {
            printf("Error: Forking Failed\n");
            continue;
        } else if (pid == 0) {
            char *args[1024];
            char *token;
            int i = 0;
            
            /* Tokenize Input */
            token = strtok(input, " ");
            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            if (execvp(args[0], args) == -1) {
                printf("Error: Invalid Command\n");
            }
            exit(1);
        } else {
            /* Wait for Child Process to Complete */
            wait(&status);
        }
    }

    return 0;
}
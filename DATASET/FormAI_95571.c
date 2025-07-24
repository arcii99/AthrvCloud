//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    char input[256];

    printf("Welcome to the Holmes Shell!\n");

    while(1) {
        printf("holmes: ");
        fgets(input, 256, stdin);

        if (strncmp(input, "exit", 4) == 0) {
            printf("Farewell, Watson.\n");
            break;
        }

        char* args[64];
        char* arg;
        int index = 0;

        arg = strtok(input, " \n");
        while(arg != NULL) {
            args[index++] = arg;
            arg = strtok(NULL, " \n");
        }
        args[index] = NULL;

        pid_t pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            printf("Could not execute command.\n");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            printf("Fork failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

void* execute_command(void* command) {
    char* cmd = (char*) command;

    // Tokenize command
    char* tokens[100];
    char* token = strtok(cmd, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    // Execute command
    int pid = fork();
    if (pid == 0) {
        execvp(tokens[0], tokens);
        exit(0);
    }
    waitpid(pid, NULL, 0);

    pthread_exit(NULL);
}

int main() {
    char command[100];

    while(1) {
        printf("$ ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command)-1] = '\0';

        pthread_t thread;
        pthread_create(&thread, NULL, execute_command, (void*) command);
        pthread_join(thread, NULL);
    }

    return 0;
}
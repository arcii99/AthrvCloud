//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void* run_command(void* arg);

int main() {
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf(">> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if (strcmp(command, "exit\n") == 0) {
            break;
        }
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, run_command, command)) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
        pthread_join(thread_id, NULL);
    }
    return 0;
}

void* run_command(void* arg) {
    char* command = (char*)arg;
    command[strcspn(command, "\n")] = '\0';
    char* tokens[MAX_ARGS];
    char* token = strtok(command, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGS) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error: Fork failed\n");
        return NULL;
    } else if (pid == 0) {
        execvp(tokens[0], tokens);
        printf("Error: Cannot execute command %s\n", tokens[0]);
        return NULL;
    } else {
        waitpid(pid, NULL, 0);
    }
    return NULL;
}
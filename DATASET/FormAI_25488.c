//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_COMMAND_SIZE 100

void *execute_command(void *command) {
    char *cmd = (char*)command;
    system(cmd);
}

int main() {
    char input[MAX_COMMAND_SIZE];

    while(1) {
        printf(">> ");
        fgets(input, MAX_COMMAND_SIZE, stdin);

        // Remove the newline character from user input
        input[strcspn(input, "\n")] = 0;

        pthread_t tid;
        pthread_attr_t attr;

        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, execute_command, input);

        pthread_join(tid, NULL);
    }

    return 0;
}
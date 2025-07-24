//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 256

struct message_buffer {
    long message_type;
    char message[BUFFER_SIZE];
};

int main() {
    pid_t pid;
    key_t key;
    int message_id;
    struct message_buffer message;

    // Generate a key
    if ((key = ftok("parent", 'A')) == -1) {
        printf("Error: Failed to generate key\n");
        exit(EXIT_FAILURE);
    }

    // Create a message queue
    if ((message_id = msgget(key, 0666 | IPC_CREAT)) == -1) {
        printf("Error: Failed to create message queue\n");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        printf("Error: Failed to fork a child process\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process sends a message to parent
        strcpy(message.message, "Hello, parent from child!");
        message.message_type = 1;

        if (msgsnd(message_id, &message, sizeof(message), 0) == -1) {
            printf("Error: Failed to send message to parent\n");
            exit(EXIT_FAILURE);
        }

        printf("Child process sent message to parent\n");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process receives message from child
        if (msgrcv(message_id, &message, sizeof(message), 1, 0) == -1) {
            printf("Error: Failed to receive message from child\n");
            exit(EXIT_FAILURE);
        }

        printf("Parent process received message from child: %s\n", message.message);
    }

    // Remove message queue
    if (msgctl(message_id, IPC_RMID, NULL) == -1) {
        printf("Error: Failed to remove message queue\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
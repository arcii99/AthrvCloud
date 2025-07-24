//FormAI DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 1024

// Structure for the message queue
struct message_queue {
    long mtype;
    char mtext[BUFFER_SIZE];
};

int main() {
    // Generate a unique key for the message queue
    key_t key = ftok(".", 'q');

    // Create the message queue with the generated key
    int queue_id = msgget(key, 0666 | IPC_CREAT);

    // Check if the message queue was successfully created
    if (queue_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Fork the process to create a child process
    pid_t pid = fork();

    // Check if the fork was successful
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Check if the process is the child process
    if (pid == 0) {
        // Child process receives the message from the message queue
        struct message_queue message;
        if (msgrcv(queue_id, &message, sizeof(message.mtext), 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Child process received message: %s\n", message.mtext);

        // Child process sends a message to the parent process
        sprintf(message.mtext, "%s", "Hello parent process!");
        message.mtype = 2;
        if (msgsnd(queue_id, &message, strlen(message.mtext) + 1, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Child process sent message to parent process.\n");

        // Exit the child process
        exit(EXIT_SUCCESS);
    } else {
        // Parent process sends a message to the child process
        struct message_queue message;
        sprintf(message.mtext, "%s", "Hello child process!");
        message.mtype = 1;
        if (msgsnd(queue_id, &message, strlen(message.mtext) + 1, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Parent process sent message to child process.\n");

        // Parent process receives the message from the child process
        if (msgrcv(queue_id, &message, sizeof(message.mtext), 2, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Parent process received message: %s\n", message.mtext);

        // Remove the message queue
        if (msgctl(queue_id, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
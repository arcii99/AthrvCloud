//FormAI DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_MESSAGES 10
#define MESSAGE_SIZE 100

typedef struct message {
    long type;
    char text[MESSAGE_SIZE];
} message_t;

int main() {
    key_t key;
    int msgid, pid;
    message_t message;

    // Generate a unique key
    if ((key = ftok("progfile", 'A')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create message queue
    if ((msgid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        message.type = 1;
        strcpy(message.text, "Hello from Child!");
        
        // Send message to parent
        if (msgsnd(msgid, &message, MESSAGE_SIZE, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        message.type = 1;
        
        // Receive message from child
        if (msgrcv(msgid, &message, MESSAGE_SIZE, 0, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Received message from Child: %s\n", message.text);

        // Cleanup message queue
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
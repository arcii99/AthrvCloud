//FormAI DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Generate unique key for message queue
    key = ftok("progfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Fork process to allow for communication between child and parent
    pid_t pid = fork();

    if (pid == 0) {
        // Child process

        // Send message to parent process
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from child process");
        msgsnd(msgid, &message, sizeof(message), 0);
    }
    else {
        // Parent process

        // Receive message from child process
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Received message: %s\n", message.msg_text);

        // Send message to child process
        message.msg_type = 2;
        strcpy(message.msg_text, "Hello from parent process");
        msgsnd(msgid, &message, sizeof(message), 0);

        // Wait for child process to finish
        wait(NULL);

        // Delete message queue
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
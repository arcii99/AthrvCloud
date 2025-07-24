//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGSIZE 512 // message size

// Message structure
struct message {
    long mtype;
    char mtext[MSGSIZE];
};

int main() {
    // Message queue key
    key_t key = ftok("msgq.txt", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Message queue id
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) { // Error creating child process
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        struct message message;
        message.mtype = 1;
        strcpy(message.mtext, "Hello from the child process!"); 

        // Send message to parent process
        if (msgsnd(msgid, &message, sizeof(struct message), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
    } else { // Parent process
        // Wait for message from child process
        struct message message;
        if (msgrcv(msgid, &message, sizeof(struct message), 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Parent process received message: %s\n", message.mtext);
    }

    // Remove message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}
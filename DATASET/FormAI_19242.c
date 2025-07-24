//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX 100

struct message {
    long type;
    char text[MAX];
};

int main() {
    key_t key;
    struct message msg;
    int msgid, pid;
    char message[MAX];

    // Generate a unique key
    key = ftok("progfile", 65);
    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    // Child process
    else if (pid == 0) {
        printf("Child process waiting for message...\n");
        // Wait for message
        msgrcv(msgid, &msg, MAX, 1, 0);
        printf("Child process received message: %s\n", msg.text);
    }
    // Parent process
    else {
        printf("Parent process sending message...\n");
        printf("Enter message: ");
        fgets(message, MAX, stdin);
        // Send message
        msg.type = 1;
        strcpy(msg.text, message);
        msgsnd(msgid, &msg, sizeof(msg), 0);
        printf("Parent process sent message: %s\n", msg.text);
    }

    // Delete the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
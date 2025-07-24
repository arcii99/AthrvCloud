//FormAI DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSG_SIZE 512
#define KEY1 1234
#define KEY2 5678

struct message {
    long mtype; 
    char mtext[MSG_SIZE];
} message;

int main() {
    int msgqid1, msgqid2;

    // Creating a message queue
    msgqid1 = msgget(KEY1, IPC_CREAT | 0660);
    if (msgqid1 < 0) {
        perror("Error creating message queue 1.");
        exit(1);
    }

    msgqid2 = msgget(KEY2, IPC_CREAT | 0660);
    if (msgqid2 < 0) {
        perror("Error creating message queue 2.");
        exit(1);
    }

    printf("Message queues created successfully!\n");

    // Sending a message from process 1 to process 2
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Could not create child process.");
        exit(1);
    }

    if (pid == 0) {
        // child process
        message.mtype = 1;
        strcpy(message.mtext, "Hello from process 1!");
        if (msgsnd(msgqid1, &message, sizeof(message), 0) < 0) {
            perror("Error sending message from process 1.");
            exit(1);
        }
    }
    else {
        // parent process
        if (msgrcv(msgqid1, &message, sizeof(message), 0, 0) < 0) {
            perror("Error receiving message in process 2.");
            exit(1);
        }

        printf("Received message in process 2: %s\n", message.mtext);

        // Sending a message from process 2 to process 1
        message.mtype = 1;
        strcpy(message.mtext, "Hello from process 2!");
        if (msgsnd(msgqid2, &message, sizeof(message), 0) < 0) {
            perror("Error sending message from process 2.");
            exit(1);
        }
    }

    // Receiving the message from process 2 in process 1
    if (msgrcv(msgqid2, &message, sizeof(message), 0, 0) < 0) {
        perror("Error receiving message in process 1.");
        exit(1);
    }

    printf("Received message in process 1: %s\n", message.mtext);

    // Removing the message queues
    if (msgctl(msgqid1, IPC_RMID, NULL) < 0 || msgctl(msgqid2, IPC_RMID, NULL) < 0) {
        perror("Error removing message queue.");
        exit(1);
    }

    printf("Message queues removed successfully!\n");

    return 0;
}
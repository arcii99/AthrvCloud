//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSIZE 128

struct message {
    long mtype;
    char mtext[MSGSIZE];
};

int main() {
    // Key creation for message queue
    key_t key = ftok("msgq.txt", 'A');
    if (key == -1) {
        perror("ftok error");
        exit(EXIT_FAILURE);
    }

    // Queue creation and checking
    int qid = msgget(key, IPC_CREAT | 0666);
    if (qid == -1) {
        perror("msgget error");
        exit(EXIT_FAILURE);
    }

    // Parent process
    if (fork() == 0) {
        struct message m;
        m.mtype = 1; // Message priority
        strcpy(m.mtext, "Hello from parent process!");

        // Send message to queue
        if (msgsnd(qid, &m, strlen(m.mtext) + 1, 0) == -1) {
            perror("msgsnd error");
            exit(EXIT_FAILURE);
        }

        printf("Parent: sent message to queue\n");

        // Wait for child process to send its message
        if (msgrcv(qid, &m, MSGSIZE, 2, 0) == -1) {
            perror("msgrcv error");
            exit(EXIT_FAILURE);
        }

        printf("Parent: received message from queue: %s\n", m.mtext);
    }
    // Child process
    else {
        struct message m;
        m.mtype = 2; // Message priority
        strcpy(m.mtext, "Hello from child process!");

        // Send message to queue
        if (msgsnd(qid, &m, strlen(m.mtext) + 1, 0) == -1) {
            perror("msgsnd error");
            exit(EXIT_FAILURE);
        }

        printf("Child: sent message to queue\n");

        // Wait for parent process to send its message
        if (msgrcv(qid, &m, MSGSIZE, 1, 0) == -1) {
            perror("msgrcv error");
            exit(EXIT_FAILURE);
        }

        printf("Child: received message from queue: %s\n", m.mtext);
    }

    // Delete message queue
    if (msgctl(qid, IPC_RMID, NULL) == -1) {
        perror("msgctl error");
        exit(EXIT_FAILURE);
    }

    return 0;
}
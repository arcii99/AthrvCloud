//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

typedef struct message {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message;

int main() {
    int msqid;
    key_t key;
    message msg_send, msg_recv;

    // Generate a unique key for the message queue
    if ((key = ftok("ipc_communication.c", 'B')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue and obtain its ID
    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // child process
        // Receive message from parent
        if (msgrcv(msqid, &msg_recv, MAX_MSG_SIZE, 2, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Child: received message \"%s\"\n", msg_recv.mtext);

        // Send message to parent
        msg_send.mtype = 3;
        strcpy(msg_send.mtext, "Hello parent, this is your child!");
        if (msgsnd(msqid, &msg_send, strlen(msg_send.mtext) + 1, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Child: sent message \"%s\"\n", msg_send.mtext);
    } else {  // parent process
        // Send message to child
        msg_send.mtype = 2;
        strcpy(msg_send.mtext, "Hello child, this is your parent!");
        if (msgsnd(msqid, &msg_send, strlen(msg_send.mtext) + 1, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Parent: sent message \"%s\"\n", msg_send.mtext);

        // Receive message from child
        if (msgrcv(msqid, &msg_recv, MAX_MSG_SIZE, 3, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Parent: received message \"%s\"\n", msg_recv.mtext);
    }

    // Delete message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
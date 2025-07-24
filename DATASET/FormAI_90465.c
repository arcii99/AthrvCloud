//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#define BUF_SIZE 256

/* Message structure */
struct message {
    long mType;
    char mData[BUF_SIZE];
};

/* Global variables */
int queueID;

/* Signal handler function to remove message queue on termination */
void cleanup(int sig) {
    msgctl(queueID, IPC_RMID, NULL);
    exit(0);
}

int main() {
    /* Generate unique key for message queue */
    key_t key = ftok("/tmp", 'Q');

    /* Create message queue */
    queueID = msgget(key, IPC_CREAT | 0666);
    if (queueID < 0) {
        perror("msgget");
        exit(1);
    }

    /* Register signal handler to remove message queue on termination */
    signal(SIGINT, cleanup);

    /* Initialize message structure and message data */
    struct message msg;
    msg.mType = 1;
    strncpy(msg.mData, "Hello world!", BUF_SIZE);

    /* Send message to queue */
    int ret = msgsnd(queueID, (void *)&msg, BUF_SIZE, 0);
    if (ret < 0) {
        perror("msgsnd");
        exit(1);
    }

    /* Receive message from queue */
    memset(&msg, 0, sizeof(struct message));
    ret = msgrcv(queueID, (void *)&msg, BUF_SIZE, 0, 0);
    if (ret < 0) {
        perror("msgrcv");
        exit(1);
    }

    /* Print received message */
    printf("Received message: %s\n", msg.mData);

    /* Wait for signal */
    while(1) {
        pause();
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 128

// Define a message structure
struct message {
    long mtype;
    char mtext[MSG_SIZE];
};

int main() {
    int qid;
    key_t key;
    struct message msg;

    // Generate a unique key
    key = ftok(".", 'm');

    // Create a message queue
    qid = msgget(key, IPC_CREAT | 0666);

    if (qid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Message queue created with qid = %d\n", qid);

    // Send a message
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello from process 1!");
    msgsnd(qid, &msg, strlen(msg.mtext)+1, 0);

    printf("Sent message: %s\n", msg.mtext);

    // Receive a message
    msgrcv(qid, &msg, MSG_SIZE, 2, 0);

    printf("Received message: %s\n", msg.mtext);

    // Remove the message queue
    msgctl(qid, IPC_RMID, NULL);

    return 0;
}
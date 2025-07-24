//FormAI DATASET v1.0 Category: Interprocess communication ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX 100

typedef struct msgbuf {
    long mtype;
    char mtext[MAX];
} message_buf;

int main() {
    int msgqid;
    key_t key;
    message_buf buf;

    // Create a unique key for the message queue
    if ((key = ftok("/tmp", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue with the given key
    if ((msgqid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message queue created with key %d\n", key);

    // Continuously listen for incoming messages
    while (1) {
        if (msgrcv(msgqid, &buf, MAX, 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        // Print the received message
        printf("Received message: %s\n", buf.mtext);

        // Send a confirmation message back
        strcpy(buf.mtext, "Message received");
        buf.mtype = 2;
        if (msgsnd(msgqid, &buf, strlen(buf.mtext)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
    }

    return 0;
}
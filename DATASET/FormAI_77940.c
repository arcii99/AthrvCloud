//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSZ     128

/* Define a message structure */
typedef struct msgbuf {
    long mtype;
    char mtext[MSGSZ];
} message_buf;

/* Define a key for the message queue */
const key_t KEY = 1234;

int main()
{
    message_buf  rbuf;
    size_t buflen = MSGSZ;
    int msqid;

    /* Create the message queue */
    if ((msqid = msgget(KEY, 0666 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    /* Send a message to the queue */
    message_buf sbuf;
    sbuf.mtype = 1;
    strcpy(sbuf.mtext, "Hello, this is a message!");

    if (msgsnd(msqid, &sbuf, buflen, IPC_NOWAIT) == -1) {
        perror("msgsnd");
        exit(1);
    }

    /* Receive a message from the queue */
    if (msgrcv(msqid, &rbuf, buflen, 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    /* Print the received message */
    printf("Received message: %s\n", rbuf.mtext);

    /* Destroy the message queue */
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}
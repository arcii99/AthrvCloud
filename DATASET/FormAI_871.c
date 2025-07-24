//FormAI DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSGSZ     128

/* Define a message structure */
typedef struct msgbuf {
    long    mtype;
    char    mtext[MSGSZ];
} message_buf;

int main() {
    key_t key;
    int msgid;
    message_buf buf;

    /* Generate a unique key value */
    key = ftok(".", 'A');

    /* Create a message queue */
    if ((msgid = msgget(key, 0666 | IPC_CREAT)) < 0) {
        perror("msgget");
        return 1;
    }

    /* Send a message to the queue */
    buf.mtype = 1;
    sprintf(buf.mtext, "Hello world!");
    if (msgsnd(msgid, &buf, sizeof(buf), IPC_NOWAIT) < 0) {
        perror("msgsnd");
        return 1;
    }

    /* Receive a message from the queue */
    if (msgrcv(msgid, &buf, sizeof(buf), 1, IPC_NOWAIT) < 0) {
        perror("msgrcv");
        return 1;
    }

    /* Print the received message */
    printf("Received message: %s\n", buf.mtext);

    /* Delete the message queue */
    if (msgctl(msgid, IPC_RMID, NULL) < 0) {
        perror("msgctl");
        return 1;
    }

    return 0;
}
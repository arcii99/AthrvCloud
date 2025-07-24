//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 75
#define MSGSZ 128

/* create a message struct */
typedef struct msgbuf {
    long mtype;
    char mtext[MSGSZ];
} message_buf;

int main() {
    message_buf sbuf;
    int msgid;

    /* create a message queue, or retrieve it if it already exists */
    msgid = msgget(MSGKEY, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    while (1) {
        /* read input from terminal */
        fgets(sbuf.mtext, MSGSZ, stdin);

        /* construct message */
        sbuf.mtype = 1;
        if (msgsnd(msgid, &sbuf, strlen(sbuf.mtext)+1, IPC_NOWAIT) == -1) {
            perror("msgsnd");
            exit(1);
        }

        /* clear message buffer */
        memset(&sbuf, 0, sizeof(message_buf));

        /* receive and output message */
        if (msgrcv(msgid, &sbuf, MSGSZ, 1, IPC_NOWAIT) == -1) {
            perror("msgrcv");
        } else {
            printf("Received message: %s\n", sbuf.mtext);
        }

        /* clear message buffer */
        memset(&sbuf, 0, sizeof(message_buf));

        /* sleep for 1 second to prevent message flooding */
        sleep(1);
    }

    return 0;
}
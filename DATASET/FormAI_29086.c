//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSZ     128

/* Define the message structure */ 
typedef struct msgbuf {
         long    mtype;
         char    mtext[MSGSZ];
         } message_buf;

int main()
{
    int msqid;
    message_buf sbuf,rbuf;

    key_t key = ftok("ipc_chat", 'B');    /* Generate unique key for our message queue */
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msqid = msgget(key, 0644 | IPC_CREAT); /* create the message queue with permission 0644 */
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Chatbot (PID:%d) running\n", getpid());

    /* Send the message */
    while(1) {
        printf("Enter message: ");
        fgets(sbuf.mtext, MSGSZ, stdin);
        sbuf.mtype = 1;

        if (msgsnd(msqid, &sbuf, strlen(sbuf.mtext)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        if(!strcmp(sbuf.mtext, "quit\n"))
            break;

        /* Read the message */
        if (msgrcv(msqid, &rbuf, MSGSZ, 2, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        printf("Chatbot: %s", rbuf.mtext);
    }

    /* Remove the queue */
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Chatbot shutting down.\n");
    return 0;
}
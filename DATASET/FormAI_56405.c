//FormAI DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSIZE 25

// message structure definition
struct msgbuf {
    long mtype;
    char mtext[MSGSIZE];
};

int main() {
    key_t key;
    int msqid;
    struct msgbuf buf, rcv_buf;
    pid_t pid;

    // create message queue
    key = ftok(".", 'a');
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // get pid of current process
    pid = getpid();

    // send message to parent process
    if (pid != 0) {
        buf.mtype = 1;
        strcpy(buf.mtext, "Hello parent");
        if (msgsnd(msqid, &buf, MSGSIZE, IPC_NOWAIT) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
    }

    // receive message from child process
    else {
        if (msgrcv(msqid, &rcv_buf, MSGSIZE, 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Message received from child: %s\n", rcv_buf.mtext);
    }

    // fork child process
    pid = fork();

    // child process
    if (pid == 0) {
        buf.mtype = 1;
        strcpy(buf.mtext, "Hello child");
        if (msgsnd(msqid, &buf, MSGSIZE, IPC_NOWAIT) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }

    // parent process
    else {
        if (msgrcv(msqid, &rcv_buf, MSGSIZE, 1, 0) == -1) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Message received from child: %s\n", rcv_buf.mtext);
    }

    // delete message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
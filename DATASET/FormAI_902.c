//FormAI DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT_SIZE 100

struct message {
    long mtype;
    char mtext[MAX_TEXT_SIZE];
};

int main() {
    pid_t pid;
    int msgqid;
    key_t key;
    struct message msg;

    key = ftok(".", 'a');

    msgqid = msgget(key, IPC_CREAT | 0666);
    if (msgqid == -1) {
        perror("msgget");
        exit(1);
    }

    pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            /* Child process */
            printf("Child process created with PID: %d\n", getpid());
            /* Send message to parent */
            msg.mtype = 1;
            strncpy(msg.mtext, "Hello from child process!", MAX_TEXT_SIZE);
            msgsnd(msgqid, &msg, sizeof(struct message) - sizeof(long), 0);
            exit(0);
        default:
            /* Parent process */
            printf("Parent process created with PID: %d\n", getpid());
            /* Receive message from child */
            msgrcv(msgqid, &msg, sizeof(struct message) - sizeof(long), 1, 0);
            printf("Received message from child process: %s\n", msg.mtext);
            /* Remove message queue */
            msgctl(msgqid, IPC_RMID, NULL);
            exit(0);
    }
}
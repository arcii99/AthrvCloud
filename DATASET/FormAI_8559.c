//FormAI DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MESSAGE_SIZE 160

struct message {
    long mtype;
    char mtext[MESSAGE_SIZE];
};

void sender(int msgid) {
    struct message msg = {0};
    msg.mtype = 1;
    snprintf(msg.mtext, MESSAGE_SIZE, "Hello from sender process %d", getpid());
    if (msgsnd(msgid, &msg, strlen(msg.mtext) + 1, 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "Sent message: %s\n", msg.mtext);
}

void receiver(int msgid) {
    struct message msg = {0};
    if (msgrcv(msgid, &msg, MESSAGE_SIZE, 0, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "Received message: %s\n", msg.mtext);
}

int main() {
    int msgid;
    key_t key = ftok("msgq_file", 'R');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    pid_t pid;
    switch (pid = fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            sleep(1);
            receiver(msgid);
            break;
        default:
            sender(msgid);
            wait(NULL);
            if (msgctl(msgid, IPC_RMID, NULL) == -1) {
                perror("msgctl");
                exit(EXIT_FAILURE);
            }
            break;
    }

    exit(EXIT_SUCCESS);
}
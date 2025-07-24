//FormAI DATASET v1.0 Category: Interprocess communication ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

/* Define message structure */
struct mymsg {
    long int msgtype;
    char msgtext[MSG_SIZE];
};

int main() {
    /* Declare variables */
    key_t key;
    int msgid;
    struct mymsg mesg;

    /* Generate a unique key */
    key = ftok("progfile", 65);

    /* Create message queue */
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1) {
        perror("msgget()");
        exit(EXIT_FAILURE);
    }

    /* Fork a child process */
    pid_t pid = fork();

    /* Child process */
    if (pid == 0) {
        /* Send message to parent */
        strcpy(mesg.msgtext, "Hello parent, I am your child.");
        mesg.msgtype = 1;
        msgsnd(msgid, &mesg, sizeof(mesg), 0);
    } else if (pid > 0) {   /* Parent process */
        /* Receive message from child */
        msgrcv(msgid, &mesg, sizeof(mesg), 1, 0);
        printf("Received message: %s\n", mesg.msgtext);
    } else {   /* Error occurred */
        perror("fork()");
        exit(EXIT_FAILURE);
    }

    /* Remove message queue */
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
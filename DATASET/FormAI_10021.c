//FormAI DATASET v1.0 Category: Interprocess communication ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SZ 256

struct msgBuf {
    long mtype;
    char mtext[MSG_SZ];
};

int main() {

    printf("Welcome to the Interprocess Communication program!\n\n");

    //generate a message queue key
    key_t key = ftok(".", 'm');
    if (key == -1) {
        perror("Error generating key");
        exit(EXIT_FAILURE);
    }

    //create a message queue
    int mqid = msgget(key, 0666 | IPC_CREAT);
    if (mqid == -1) {
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }

    //fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        //child process

        //prepare message buffer
        struct msgBuf buf;
        memset(buf.mtext, 0, MSG_SZ);

        //receive message from parent
        if (msgrcv(mqid, &buf, MSG_SZ, 1, 0) == -1) {
            perror("Error receiving message");
            exit(EXIT_FAILURE);
        }

        printf("Child Process: Received Message: %s\n", buf.mtext);

        //modify message
        strcat(buf.mtext, " - modified by child process");

        //send message back to parent
        buf.mtype = 2;
        if (msgsnd(mqid, &buf, strlen(buf.mtext) + 1, 0) == -1) {
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }

        printf("Child Process: Sent Message: %s\n", buf.mtext);

        //exit child process
        exit(EXIT_SUCCESS);

    } else {
        //parent process

        //prepare message buffer
        struct msgBuf buf;
        buf.mtype = 1;
        strcpy(buf.mtext, "Hello from parent process");

        //send message to child
        if (msgsnd(mqid, &buf, strlen(buf.mtext) + 1, 0) == -1) {
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }

        printf("Parent Process: Sent Message: %s\n", buf.mtext);

        //receive message from child
        if (msgrcv(mqid, &buf, MSG_SZ, 2, 0) == -1) {
            perror("Error receiving message");
            exit(EXIT_FAILURE);
        }

        printf("Parent Process: Received Message: %s\n", buf.mtext);

        //destroy message queue
        if (msgctl(mqid, IPC_RMID, NULL) == -1) {
            perror("Error destroying message queue");
            exit(EXIT_FAILURE);
        }

        printf("\nExiting the Interprocess Communication program! :D");

        //exit parent process
        exit(EXIT_SUCCESS);
    }
}
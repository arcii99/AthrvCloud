//FormAI DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define MSG_TYPE 1

// The immersive story of two processes communicating via message queues

int main() {

    // Before anything, we must acquire the keys

    int key = ftok(".", 'm');
    if (key == -1) {
        perror("ftok error");
        exit(1);
    }

    // The Message Queue

    int msg_qid;
    struct msgbuf {
        long mtype;
        char mtext[256];
    } msg;

    // The two processes

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork error");
        exit(1);
    }

    // The Parent Process

    if (pid > 0) {

        printf("Parent: Alright, time to send a message to the child.\n");

        sleep(1); // Wait for the child process to initialize

        int msg_qid = msgget(key, MSG_PERMS | IPC_CREAT);
        if (msg_qid == -1) {
            perror("msgget error");
            exit(1);
        }

        msg.mtype = MSG_TYPE;
        sprintf(msg.mtext, "Hey, child! It's your parent here!");
        if (msgsnd(msg_qid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd error (parent)");
            exit(1);
        }

        printf("Parent: Sent the message. Waiting for a response...\n");

        if (msgrcv(msg_qid, &msg, sizeof(msg.mtext), MSG_TYPE+1, 0) == -1) {
            perror("msgrcv error (parent)");
            exit(1);
        }

        printf("Parent: Got a response from the child! It says: '%s'\n", msg.mtext);

        msgctl(msg_qid, IPC_RMID, NULL); // Remove the message queue

    }

    // The Child Process

    if (pid == 0) {

        printf("Child: Hello, world! I'm ready to chat.\n");

        sleep(1); // Wait for the parent process to initialize

        int msg_qid = msgget(key, MSG_PERMS | IPC_CREAT);
        if (msg_qid == -1) {
            perror("msgget error");
            exit(1);
        }

        if (msgrcv(msg_qid, &msg, sizeof(msg.mtext), MSG_TYPE, 0) == -1) {
            perror("msgrcv error (child)");
            exit(1);
        }

        printf("Child: Got a message from the parent! It says: '%s'\n", msg.mtext);

        msg.mtype = MSG_TYPE+1;
        sprintf(msg.mtext, "Hey, parent! It's your child here!");
        if (msgsnd(msg_qid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd error (child)");
            exit(1);
        }

        printf("Child: Sent a response to the parent! Closing the message queue now.\n");

        msgctl(msg_qid, IPC_RMID, NULL); // Remove the message queue

    }

    return 0;

}
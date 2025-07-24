//FormAI DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 128 // maximum message size
#define KEY 1234 // key for message queue

// struct for message
struct messageBuffer {
    long mtype; // message type (must be > 0)
    char mtext[MSG_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct messageBuffer message;

    // generate key for message queue
    if ((key = ftok("ipc_example", KEY)) == -1) {
        perror("ftok");
        exit(1);
    }

    // create message queue with specified key
    if ((msgid = msgget(key, 0600 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    printf("This is the parent process with PID %d\n", getpid());

    // fork child process
    pid_t pid = fork();

    if (pid == -1) { // error occurred during fork
        perror("fork");
        exit(1);
    } else if (pid == 0) { // child process
        printf("This is the child process with PID %d\n", getpid());
        sleep(1); // wait for parent process to send message

        // receive message from parent process
        if (msgrcv(msgid, &message, MSG_SIZE, 2, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Received message from parent process: %s\n", message.mtext);

        // send reply message to parent process
        strcpy(message.mtext, "Reply message from child process");
        message.mtype = 1;
        if (msgsnd(msgid, &message, strlen(message.mtext)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Reply message sent to parent process\n");

        // exit child process
        exit(0);
    } else { // parent process
        // send message to child process
        strcpy(message.mtext, "Message from parent process");
        message.mtype = 2;
        if (msgsnd(msgid, &message, strlen(message.mtext)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Message sent to child process\n");

        // wait for reply message from child process
        if (msgrcv(msgid, &message, MSG_SIZE, 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Received reply message from child process: %s\n", message.mtext);

        // remove message queue
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(1);
        }

        printf("Message queue removed\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 128
#define MSG_TYPE 1

/* Define structure for message queue */
struct Message {
    long mtype;
    char mtext[MSG_SIZE];
};

/* Print an error message and terminate the program */
void handleError(char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int parentPID = getpid();

    /* Create a message queue */
    key_t msgQKey = ftok(".", 'm');
    if (msgQKey == -1) {
        handleError("Error creating key for message queue");
    }

    int msgQID = msgget(msgQKey, IPC_CREAT | 0644);
    if (msgQID == -1) {
        handleError("Error creating message queue");
    }

    /* Fork a child process */
    int childPID = fork();
    if (childPID == -1) {
        handleError("Error forking child process");
    }

    /* Communication between parent and child */
    if (childPID == 0) {
        /* Child process */
        struct Message msg;
        printf("Enter a message to send to parent: ");
        fgets(msg.mtext, MSG_SIZE, stdin);
        msg.mtype = MSG_TYPE;

        /* Send message to parent process */
        if (msgsnd(msgQID, &msg, strlen(msg.mtext)+1, 0) == -1) {
            handleError("Error sending message to parent");
        }

    } else {
        /* Parent process */
        struct Message msg;
        if (msgrcv(msgQID, &msg, MSG_SIZE, MSG_TYPE, 0) == -1) {
            handleError("Error receiving message from child");
        }

        /* Print message received from child */
        printf("Message received from child: %s", msg.mtext);
    }

    /* Clean up message queue */
    if (msgctl(msgQID, IPC_RMID, NULL) == -1) {
        handleError("Error removing message queue");
    }

    /* Exit program */
    return 0;
}
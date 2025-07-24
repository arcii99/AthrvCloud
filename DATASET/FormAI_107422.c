//FormAI DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define KEY 1234

struct message {
    long mtype;
    char mtext[100];
};

int main() {

    int msgid;
    key_t key = KEY;
    struct message msg;

    // Create message queue
    if ((msgid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    // Child process
    if (fork() == 0) {
        // Send message to parent
        strcpy(msg.mtext, "Hello parent!");
        msg.mtype = 1; // Type of message
        if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
    }
    // Parent process
    else {
        // Receive message from child
        if (msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        printf("Received message: %s\n", msg.mtext);
    }

    // Remove message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}
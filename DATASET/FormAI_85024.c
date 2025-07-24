//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct message {
    long mtype;
    char mtext[BUFFER_SIZE];
};

int main() {
    key_t key;
    int msgid;
    char buffer[BUFFER_SIZE];
    struct message msg;

    // Generate a unique key
    key = ftok(".", 'm');

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message queue created with ID %d\n", msgid);

    // Send a message
    printf("Enter a message to send: ");
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        perror("fgets");
        exit(1);
    }

    msg.mtype = 1;
    strncpy(msg.mtext, buffer, BUFFER_SIZE);

    if (msgsnd(msgid, &msg, sizeof(struct message), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent!\n");

    // Receive a message
    if (msgrcv(msgid, &msg, sizeof(struct message), 0, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Received message: %s\n", msg.mtext);

    // Close and unlink the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue closed and unlinked.\n");

    return 0;
}
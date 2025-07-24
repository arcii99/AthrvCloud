//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 512

// Define a message structure with a custom header and message payload
struct message {
    long type;          // The message type
    char payload[MAX_SIZE];     // The message payload
} msg;

int main() {
    int msgid, pid;
    pid = getpid();

    // Create a unique key for the message queue
    key_t key = ftok("ipc_example", 'B');

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        printf("Error creating message queue.\n");
        exit(EXIT_FAILURE);
    }

    printf("Message queue with ID %d has been created.\n", msgid);

    // Send a message to the message queue with a custom header and payload
    strcpy(msg.payload, "Hello from process ");
    sprintf(msg.payload+strlen(msg.payload), "%d", pid);
    msg.type = 1;
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Message sent to message queue with ID %d.\n", msgid);

    // Receive a message from the message queue with a custom type
    msgrcv(msgid, &msg, sizeof(msg), 2, 0);
    printf("Message received from message queue with ID %d.\n", msgid);
    printf("Message payload: %s\n", msg.payload);

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message queue with ID %d has been removed.\n", msgid);

    return EXIT_SUCCESS;
}
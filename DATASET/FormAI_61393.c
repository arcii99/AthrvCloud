//FormAI DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 1024

struct message {
    long msg_type;
    char msg[MSG_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate a unique key
    key = ftok(".", 'A');

    // Create the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        printf("Failed to create message queue\n");
        return 1;
    }

    // Get message from user
    printf("Enter a message to send to the other process:\n");
   fgets(msg.msg, MSG_SIZE, stdin);

    // Set the message type to 1
    msg.msg_type = 1;

    // Send message to queue
    if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) {
        printf("Failed to send message to queue\n");
        return 1;
    }

    // Receive message from queue
    if (msgrcv(msgid, &msg, sizeof(msg), 2, 0) == -1) {
        printf("Failed to receive message from queue\n");
        return 1;
    }

    // Print received message
    printf("Received message: %s\n", msg.msg);

    // Close message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        printf("Failed to close message queue\n");
        return 1;
    }

    return 0;
}
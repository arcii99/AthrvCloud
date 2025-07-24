//FormAI DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the structure of the message queue
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    // Create message queue key
    key_t key = ftok("progfile", 65);

    // Create message queue and handle errors
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        printf("Error creating message queue");
        exit(1);
    }

    // Prompt user to enter message to send
    printf("Enter message to send: ");
    fgets(message.msg_text, 100, stdin);

    // Set message type to 1
    message.msg_type = 1;

    // Send message and handle errors
    if ((msgsnd(msgid, &message, sizeof(message), 0)) == -1) {
        printf("Error sending message");
        exit(1);
    }

    printf("Message sent successfully\n");

    // Receive message and handle errors
    if ((msgrcv(msgid, &message, sizeof(message), 1, 0)) == -1) {
        printf("Error receiving message");
        exit(1);
    }

    printf("Received message: %s", message.msg_text);

    // Destroy message queue
    if ((msgctl(msgid, IPC_RMID, NULL)) == -1) {
        printf("Error destroying message queue");
        exit(1);
    }

    return 0;
}
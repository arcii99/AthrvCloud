//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
// A satisfied example program for demonstrating Interprocess Communication in C Language
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Custom struct for holding message information
struct message_buffer {
    long message_type;
    char message_text[100];
};

// Main function
int main() {
    key_t key;
    int message_id;
    struct message_buffer message;

    // Generate a message queue key
    key = ftok("messaging", 65);

    // Create a message queue and get its ID
    message_id = msgget(key, 0666 | IPC_CREAT);

    // Prompt the user to input message to be sent
    printf("Enter a message to send: ");
    fgets(message.message_text, 100, stdin);

    // Set the message type as 1
    message.message_type = 1;

    // Send the message through the message queue
    msgsnd(message_id, &message, sizeof(message), 0);

    printf("Message sent successfully\n");

    // Receive the message
    msgrcv(message_id, &message, sizeof(message), 1, 0);

    printf("Received message: %s", message.message_text);

    // Remove the message queue
    msgctl(message_id, IPC_RMID, NULL);

    return 0;
}
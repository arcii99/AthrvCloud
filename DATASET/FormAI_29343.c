//FormAI DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
//This program demonstrates Interprocess Communication between two processes using message queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

// Define the structure for the message that needs to be sent
struct message {
    long int messageType; // Message Type
    char messageText[100]; // Message Text
} msg;

int main() {
    // Create the message queue
    key_t messageQueueKey = ftok("message.txt", 'A');
    int messageQueueId = msgget(messageQueueKey, 0666 | IPC_CREAT);

    // Check if the message queue was created successfully
    if (messageQueueId == -1) {
        printf("Error creating message queue.\n");
        exit(EXIT_FAILURE);
    }

    // Prompt user to enter message to send
    printf("Enter Message to send: ");
    fgets(msg.messageText, 100, stdin);
    msg.messageType = 1;

    // Send the message to the message queue
    msgsnd(messageQueueId, (void *)&msg, sizeof(msg), 0);
    printf("Message sent to message queue.\n");

    // Sleep for 3 seconds to simulate processing time
    sleep(3);

    // Receive the message from the message queue
    msgrcv(messageQueueId, (void *)&msg, sizeof(msg), msg.messageType, 0);
    printf("Received Message: %s", msg.messageText);

    // Delete the message queue
    msgctl(messageQueueId, IPC_RMID, NULL);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 1024

// Define a structure for the message that will be sent between processes
struct message {
    long messageType;
    char messageContent[MSG_SIZE];
};

int main() {
    int messageQueueId;
    struct message messageToReceive, messageToSend;
    pid_t childProcess;
    
    // Generate a unique IPC key to use for the message queue
    key_t ipcKey = ftok("ipcExample.c", 'b');
    
    // Create a message queue with the specified IPC key
    messageQueueId = msgget(ipcKey, 0666 | IPC_CREAT);
    
    // Fork a child process to send and receive messages
    childProcess = fork();
    
    if (childProcess == 0) {
        // This is the child process
        
        // Create a message to send to the parent process
        messageToSend.messageType = 1; // Set the message type
        strncpy(messageToSend.messageContent, "Hello from child process!", MSG_SIZE); // Set the message content
        
        // Send the message to the parent process
        msgsnd(messageQueueId, &messageToSend, sizeof(messageToSend) - sizeof(long), 0);
        
        // Wait for a response from the parent process
        msgrcv(messageQueueId, &messageToReceive, sizeof(messageToReceive) - sizeof(long), 2, 0);
        
        // Print the message received from the parent process
        printf("Message received from parent process: %s\n", messageToReceive.messageContent);
        
    } else {
        // This is the parent process
        
        // Wait for a message from the child process
        msgrcv(messageQueueId, &messageToReceive, sizeof(messageToReceive) - sizeof(long), 1, 0);
        
        // Print the message received from the child process
        printf("Message received from child process: %s\n", messageToReceive.messageContent);
        
        // Create a message to send back to the child process
        messageToSend.messageType = 2; // Set the message type
        strncpy(messageToSend.messageContent, "Hello from parent process!", MSG_SIZE); // Set the message content
        
        // Send the message back to the child process
        msgsnd(messageQueueId, &messageToSend, sizeof(messageToSend) - sizeof(long), 0);
        
        // Wait for the child process to finish
        wait(NULL);
        
        // Remove the message queue
        msgctl(messageQueueId, IPC_RMID, NULL);
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// Define the message structure
struct message {
    long type;
    char text[100];
};

// Define a function to send messages
void sendMessage(int messageQueueID, char* messageText) {
    struct message msg;
    msg.type = 1;
    strcpy(msg.text, messageText);
    
    // Send the message
    msgsnd(messageQueueID, &msg, sizeof(msg), 0);
    
    printf("Sent Message: %s\n", msg.text);
}

// Define a function to receive messages
void receiveMessage(int messageQueueID) {
    struct message msg;
    msgrcv(messageQueueID, &msg, sizeof(msg), 1, 0);
    
    printf("Received Message: %s\n", msg.text);
}

int main() {
    // Generate a unique key
    key_t key = ftok("ipc_demo", 'a');
    
    // Create a message queue
    int messageQueueID = msgget(key, IPC_CREAT | 0666);
    
    printf("Message Queue ID: %d\n", messageQueueID);
    
    // Fork a child process
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child Process
        printf("Child Process\n");
        
        // Receive a message from the parent
        receiveMessage(messageQueueID);
        
        // Send a response to the parent
        sendMessage(messageQueueID, "Hello from Child");
    } else if (pid > 0) {
        // Parent Process
        printf("Parent Process\n");
        
        // Send a message to the child
        sendMessage(messageQueueID, "Hello from Parent");
        
        // Receive a response from the child
        receiveMessage(messageQueueID);
    } else {
        perror("fork()");
        exit(1);
    }
    
    // Remove the message queue
    msgctl(messageQueueID, IPC_RMID, NULL);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: visionary
/*
    As technology advances, so does the need for efficient communication between processes. 
    This program demonstrates Interprocess Communication (IPC) between a parent process and a child process. 
    The parent process sends a message to the child process and the child process prints the message.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

// Define the message structure
struct message {
   long msgType;
   char msg[100];
};

// Main program
int main() {
    // Declare variables
    int msgqid, pid;
    struct message message;
    
    // Create message queue and check for errors
    msgqid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msgqid == -1) {
        perror("Error creating message queue");
        exit(1);
    }
    
    // Fork the process
    pid = fork();
    
    // Check for errors in forking process
    if (pid < 0) {
        perror("Error forking process");
        exit(1);
    }
    
    // Parent process
    else if (pid > 0) {
        printf("Parent process sending message...\n");
        strcpy(message.msg, "Hello, child process!");
        message.msgType = 1;
        
        // Send message to child process and check for errors
        if (msgsnd(msgqid, &message, sizeof(struct message), 0) == -1) {
            perror("Error sending message");
            exit(1);
        }
    }
    
    // Child process
    else if (pid == 0) {
        printf("Child process checking for message...\n");
        if (msgrcv(msgqid, &message, sizeof(struct message), 1, 0) == -1) {
            perror("Error receiving message");
            exit(1);
        }
        printf("Child process received message: %s\n", message.msg);
    }
    
    // Remove the message queue
    msgctl(msgqid, IPC_RMID, NULL);
    
    // Exit the program
    exit(0);
}
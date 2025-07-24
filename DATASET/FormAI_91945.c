//FormAI DATASET v1.0 Category: Interprocess communication ; Style: modular
/*
 * This program demonstrates interprocess communication between two processes using message queues.
 * The first process sends a message to the second process, and the second process receives the message.
 * This program follows modular programming style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define a message structure
struct message {
    long mtype; // message type
    char mtext[100]; // message text
};

// Declare the key and message queue IDs
key_t key;
int msgid;

// Declare functions for sending and receiving messages
void send_message(struct message*);
void receive_message(struct message*);

// Main function
int main() {
    // Generate a unique key
    key = ftok("file.txt", 'A');
    
    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    
    // Check if there was an error creating message queue
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }
    
    // Declare and initialize a message to be sent
    struct message msg = {1, "Hello, World!"};
    
    // Send the message
    send_message(&msg);
    
    // Declare a message to receive the incoming message
    struct message msg_rcv;
    
    // Receive the message
    receive_message(&msg_rcv);
    
    // Print the received message
    printf("Received message: %s\n", msg_rcv.mtext);
    
    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);
    
    return 0;
}

// Function to send a message
void send_message(struct message* msg) {
    // Send the message
    if (msgsnd(msgid, msg, sizeof(struct message) - sizeof(long), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
    
    // Print the sent message
    printf("Sent message: %s\n", msg->mtext);
}

// Function to receive a message
void receive_message(struct message* msg) {
    // Receive the message
    if (msgrcv(msgid, msg, sizeof(struct message) - sizeof(long), 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }
}
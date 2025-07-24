//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

// Define the message structure
struct message {
    long mtype;
    char mtext[100];
};

// Declare the global variables
int running = 1;
int msqid1, msqid2;
key_t key1 = 1234, key2 = 5678;
pthread_t thread;

// Function to receive messages from the queue
void *receive_message(void *arg) {
    struct message message;

    while(running) {
        // Receive the message
        msgrcv(msqid2, &message, sizeof(message), 0, 0);

        // Print the message
        printf("Message received: %s\n", message.mtext);

        // Check if the message is "exit"
        if(strcmp(message.mtext, "exit") == 0) {
            running = 0;
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Create the message queues
    msqid1 = msgget(key1, IPC_CREAT | 0666);
    msqid2 = msgget(key2, IPC_CREAT | 0666);

    // Check if the queues were created successfully
    if(msqid1 == -1 || msqid2 == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Start the receiving thread
    pthread_create(&thread, NULL, receive_message, NULL);

    // Send messages to the queue
    struct message message;
    message.mtype = 1;
    while(1) {
        // Get input from the user
        printf("Enter a message: ");
        fgets(message.mtext, 100, stdin);

        // Send the message
        msgsnd(msqid1, &message, sizeof(message), 0);

        // Check if the message is "exit"
        if(strcmp(message.mtext, "exit\n") == 0) {
            running = 0;
            break;
        }
    }

    // Wait for the receiving thread to exit
    pthread_join(thread, NULL);

    // Destroy the message queues
    msgctl(msqid1, IPC_RMID, NULL);
    msgctl(msqid2, IPC_RMID, NULL);

    return 0;
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define SIZE 50

// Structure definition for message queue
struct message_buffer {
    long message_type;
    char message[SIZE];
} message;

// Function to generate random numbers
int randomNumberGenerator() {
    int num = rand() % 100;
    return num;
}

// Main program
int main() {
    // Message queue declaration
    key_t key;
    int message_queue_id;
    
    // Generate a unique key for message queue
    key = ftok("message_queue", 65);
    
    // Create the message queue and get the id
    message_queue_id = msgget(key, 0666 | IPC_CREAT);
    
    // Error message on message queue creation failure
    if (message_queue_id == -1) {
        perror("msgget");
        exit(1);
    }
    
    // Forking process to create child process
    pid_t process_id = fork();
    
    // Parent process
    if (process_id > 0) {
        printf("Parent process is working\n");
        int number1 = randomNumberGenerator();
        int number2 = randomNumberGenerator();
        int sum = number1 + number2;
        printf("Parent sends: %d + %d = %d\n", number1, number2, sum);
        // Setting the message type to 1, message content to sum
        message.message_type = 1;
        sprintf(message.message, "%d", sum);
        // Sending message to message queue
        msgsnd(message_queue_id, &message, sizeof(message), 0);
    }
    
    // Child process
    else if (process_id == 0) {
        printf("Child process is working\n");
        // Receiving message from message queue
        msgrcv(message_queue_id, &message, sizeof(message), 1, 0);
        int received_sum = atoi(message.message);
        printf("Child receives: %s\n", message.message);
        printf("Child exits\n");
    }
    
    // Error message on forking failure
    else {
        perror("fork");
        exit(1);
    }
    // Deleting the message queue
    msgctl(message_queue_id, IPC_RMID, NULL);
    return 0;
}
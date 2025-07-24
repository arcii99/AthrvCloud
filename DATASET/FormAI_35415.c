//FormAI DATASET v1.0 Category: Interprocess communication ; Style: distributed
// Header files
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// Structure for message queue
struct msg_buffer { 
    long message_type; 
    char message[100]; 
} message, response; 

int main() { 
    pid_t pid = fork(); // Fork the process

    if (pid == -1) { // If fork failed
        printf("Fork failed!"); 
        exit(1); 
    } else if (pid == 0) { // Child process
        // Create the message queue
        key_t key = ftok("progfile", 65); 
        int msgid = msgget(key, 0666 | IPC_CREAT); 
        message.message_type = 1; 

        // Send a message to the parent process
        printf("Child process: Enter a message to send to the parent process: "); 
        fgets(message.message, sizeof(message.message), stdin); 
        msgsnd(msgid, &message, sizeof(message), 0); 

        // Receive the response from the parent process
        msgrcv(msgid, &response, sizeof(response), 2, 0); 
        printf("Child process: Received response: %s\n", response.message); 

        // Remove the message queue
        msgctl(msgid, IPC_RMID, NULL); 
    } else { // Parent process
        // Create the message queue
        key_t key = ftok("progfile", 65); 
        int msgid = msgget(key, 0666 | IPC_CREAT); 
        message.message_type = 1; 

        // Receive the message from the child process
        msgrcv(msgid, &message, sizeof(message), 1, 0); 
        printf("Parent process: Received message: %s\n", message.message); 

        // Send a response to the child process
        printf("Parent process: Enter a response to send to the child process: "); 
        fgets(response.message, sizeof(response.message), stdin); 
        response.message_type = 2; 
        msgsnd(msgid, &response, sizeof(response), 0); 

        // Remove the message queue
        msgctl(msgid, IPC_RMID, NULL); 
    } 

    return 0; 
}
//FormAI DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

typedef struct {
    long messageType;
    char messageText[MAX_BUFFER_SIZE];
} Message;

int main() {
    int messageQueueId;
    Message message;
    key_t key;
    pid_t pid;
    
    key = ftok(".", 'M');
    if (key == -1) {
        perror("Error generating key: ");
        exit(EXIT_FAILURE);
    }
    
    messageQueueId = msgget(key, 0666 | IPC_CREAT);
    if (messageQueueId == -1) {
        perror("Error creating message queue: ");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();
    
    if (pid == 0) {
        // Child process
        while (1) {
            if (msgrcv(messageQueueId, (void *) &message, MAX_BUFFER_SIZE, 1, 0) == -1) {
                perror("Error receiving message: ");
                exit(EXIT_FAILURE);
            }
            
            printf("Child process received message: %s\n", message.messageText);
            
            if (strncmp(message.messageText, "quit", 4) == 0) {
                break;
            }
        }
        
        exit(EXIT_SUCCESS);
    }
    
    // Parent process
    while (1) {
        printf("Enter message to send to child process:\n");
        fgets(message.messageText, MAX_BUFFER_SIZE, stdin);
        message.messageType = 1;
        
        if (msgsnd(messageQueueId, (const void *) &message, strlen(message.messageText) + 1, 0) == -1) {
            perror("Error sending message: ");
            exit(EXIT_FAILURE);
        }
        
        if (strncmp(message.messageText, "quit", 4) == 0) {
            break;
        }
    }
    
    printf("Parent process exiting...\n");
    
    // Cleanup
    msgctl(messageQueueId, IPC_RMID, NULL);
    
    exit(EXIT_SUCCESS);
}
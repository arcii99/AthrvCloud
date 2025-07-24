//FormAI DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define SERVER_QUEUE_KEY 1234
#define CLIENT_QUEUE_KEY 5678

typedef struct message {
    long msg_type;
    char message[100];
} Message;

int main(void) {
    // Creating server queue
    int server_queue = msgget(SERVER_QUEUE_KEY, IPC_CREAT | 0666);
    if (server_queue == -1) {
        perror("Failed to create server queue.");
        exit(EXIT_FAILURE);
    }
    
    printf("Server running.\n");
    
    while (1) {
        // Receiving message from client
        Message message;
        msgrcv(server_queue, &message, sizeof(Message) - sizeof(long), 0, 0);
        printf("Received message from client: %s\n", message.message);
        
        // Creating client queue
        int client_queue = msgget(CLIENT_QUEUE_KEY, IPC_CREAT | 0666);
        if (client_queue == -1) {
            perror("Failed to create client queue.");
            exit(EXIT_FAILURE);
        }
        
        // Sending reply to client
        sprintf(message.message, "Server received your message: %s", message.message);
        message.msg_type = 1;
        msgsnd(client_queue, &message, sizeof(Message) - sizeof(long), 0);
        printf("Reply sent to client.\n\n");
        
        // Removing client queue
        msgctl(client_queue, IPC_RMID, NULL);
    }
    
    // Removing server queue
    msgctl(server_queue, IPC_RMID, NULL);
    
    return 0;
}
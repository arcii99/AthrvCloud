//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd, message_len, read_len;
    struct sockaddr_in server_addr, client_addr;
    char *message = "Welcome to my C chat server!";
    char buffer[1024] = {0};
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Bind socket to port 8080
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port 8080...\n");
    
    // Accept incoming connection and send welcome message
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&message_len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    send(client_fd, message, strlen(message), 0);
    
    // Loop to receive and send messages
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Waiting for message...\n");
        
        // Receive message from client
        if ((read_len = recv(client_fd, buffer, 1024, 0)) > 0) {
            printf("Client: %s\n", buffer);
            
            // Send reply message
            if (send(client_fd, buffer, strlen(buffer), 0) < 0) {
                perror("Send failed");
                exit(EXIT_FAILURE);
            }
        }
        else {
            perror("Recv failed");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}
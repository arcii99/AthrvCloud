//FormAI DATASET v1.0 Category: Client Server Application ; Style: visionary
// Here is a visionary style program which implements a chat room using a C Client Server Application.
// This chat room application consists of a server program and one or more client programs.
// The chat room application allows multiple clients to connect to the server simultaneously and
// communicate with each other in real time.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT 8888

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};
      
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
      
    // Accepting client connections and looping through them
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
          
        // Handle incoming message from client
        valread = read(new_socket, buffer, BUF_SIZE);
        printf("Client Message: %s\n", buffer);
        
        // Send reply to client
        char* message = "Server Reply: Message received!";
        send(new_socket, message, strlen(message), 0);
        printf("Reply Sent.\n");
          
        // Cleanup
        close(new_socket);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Chat server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NUMBER 8000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *welcome_message = "Welcome to the Chat Server!\n";
    
    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket properties
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_NUMBER);

    // Bind the socket to a specific address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat Server started on port %d\n", PORT_NUMBER);
    
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("New client connected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    
    // Send welcome message to new client
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    
    while (1) {
        // Receive message from client
        valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("%s:%d says: %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);
        
        // Broadcast message to all connected clients
        for (int i = 0; i < server_fd; i++) {
            if (i != server_fd && i != new_socket) {
                send(i, buffer, strlen(buffer), 0);
            }
        }
    }

    // Close the socket
    close(new_socket);
    close(server_fd);
    return 0;
}
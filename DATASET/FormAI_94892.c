//FormAI DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main() {
    // Create a socket
    int server_fd;
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to a port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Failed to bind socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_fd, 3) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Chat server is running on port %d...\n", PORT);

    // Accept incoming connections and handle them
    int client_fd, status;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    char buffer[1024] = {0};

    while((client_fd = accept(server_fd, (struct sockaddr*)&client_address, (socklen_t*)&addrlen)) > 0) {
        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Send welcome message to client
        char* welcomeMessage = "Welcome to the chat server!\nEnter your message below:\n";
        send(client_fd, welcomeMessage, strlen(welcomeMessage), 0);

        // Receive message from client and send it to all other clients
        while((status = read(client_fd, buffer, sizeof(buffer))) > 0) {
            printf("%s:%d says: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

            // Send message to all clients, except the sender
            for(int i = 0; i < FD_SETSIZE; ++i) {
                if(client_fd != i && client_fd != server_fd) {
                    send(i, buffer, sizeof(buffer), 0);
                }
            }

            memset(buffer, 0, sizeof(buffer)); // Clear buffer for next message
        }

        // Client disconnected
        printf("Client %s:%d disconnected\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    return 0;
}
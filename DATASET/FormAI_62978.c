//FormAI DATASET v1.0 Category: Chat server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome = "Welcome to the chat server!";

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Wait for a client to connect
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    send(new_socket, welcome, strlen(welcome), 0);

    while (1) {
        // Receive message from client
        valread = read(new_socket, buffer, 1024);
        
        // Check for end of client input
        if (strcmp(buffer, "exit") == 0) {
            printf("Client disconnected\n");
            break;
        }

        // Display client message
        printf("Client: %s\n", buffer);
        
        // Clear buffer
        memset(buffer, 0, sizeof(buffer));

        // Get message from server user
        printf("Server: ");
        fgets(buffer, 1024, stdin);

        // Send message to client
        send(new_socket, buffer, strlen(buffer), 0);
    }

    // Close sockets
    close(new_socket);
    close(server_fd);
    return 0;
}
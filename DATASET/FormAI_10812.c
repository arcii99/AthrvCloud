//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd, read_size;
    struct sockaddr_in server_addr, client_addr;
    char client_message[BUFFER_SIZE];

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Configure the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("Failed to listen for incoming connections");
        return 1;
    }

    // Accept incoming connections
    socklen_t client_addr_len = sizeof(client_addr);
    while ((client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len)) >= 0) {
        // Read incoming messages
        while ((read_size = recv(client_sockfd, client_message, BUFFER_SIZE, 0)) > 0) {
            // Echo back the received message
            write(client_sockfd, client_message, strlen(client_message));
            memset(&client_message, '\0', sizeof(client_message));
        }
    }

    if (client_sockfd < 0) {
        perror("Failed to accept incoming connection");
        return 1;
    }

    return 0;
}
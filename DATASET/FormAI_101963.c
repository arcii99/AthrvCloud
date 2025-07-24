//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_PENDING 5
#define MAX_DATA_SIZE 1024

void error(char* message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd, new_sockfd, n;
    char buffer[MAX_DATA_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    // Bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
        error("Error binding socket");

    // Listen for connections
    listen(sockfd, MAX_PENDING);
    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept connection
        client_addr_size = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_addr_size);
        if (new_sockfd < 0) error("Error accepting connection");

        // Receive data from client
        memset(buffer, 0, MAX_DATA_SIZE);
        n = read(new_sockfd, buffer, MAX_DATA_SIZE-1);
        if (n < 0) error("Error reading from socket");

        // Display received data
        printf("Received message from %s:%d: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);

        // Close connection
        close(new_sockfd);
    }

    // Close socket
    close(sockfd);
    return 0;
}
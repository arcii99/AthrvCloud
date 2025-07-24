//FormAI DATASET v1.0 Category: Client Server Application ; Style: careful
// Example C Client Server Application

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000

int main() {
    int sockfd, newsockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to IP
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen to socket
    if (listen(sockfd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d\n", PORT);

    // Accept incoming connections
    client_len = sizeof(client_addr);
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    // Receive message from client
    memset(buffer, 0, sizeof(buffer));
    if (read(newsockfd, buffer, sizeof(buffer)) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("Message from client: %s\n", buffer);

    // Send message to client
    char *message = "Hello from server!";
    if (send(newsockfd, message, strlen(message), 0) < 0) {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}
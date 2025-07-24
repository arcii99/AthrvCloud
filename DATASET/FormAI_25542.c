//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd, newSockfd;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t socklen = sizeof(struct sockaddr_in);

    char buffer[1024];
    memset(&buffer, 0, sizeof(buffer));

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Clear server address
    memset(&serverAddr, 0, socklen);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 1) < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);

    // Accept incoming connection
    newSockfd = accept(sockfd, (struct sockaddr *) &clientAddr, &socklen);
    if (newSockfd < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("Accepted connection from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

    // Receive message from client
    int bytesReceived = recv(newSockfd, buffer, sizeof(buffer), 0);
    if (bytesReceived < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Send response to client
    char response[] = "Hello from server!";
    if (send(newSockfd, response, strlen(response), 0) < 0) {
        perror("Error sending response");
        exit(EXIT_FAILURE);
    }

    printf("Sent response: %s\n", response);

    // Close sockets
    close(newSockfd);
    close(sockfd);

    return 0;
}
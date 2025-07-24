//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully. Now preparing to connect...\n");

    // Prepare the sockaddr_in structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected successfully to the server. Sending a message...\n");

    // Send a message to the server
    char message[] = "Hello, server!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }

    printf("Message sent successfully. Waiting for a response...\n");

    // Receive a message from the server
    char buffer[1024];
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }

    printf("Received message from the server: %s\n", buffer);

    // Close the socket
    close(sockfd);
    printf("Socket closed successfully. Program exited.\n");

    return 0;
}
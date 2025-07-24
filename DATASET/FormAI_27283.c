//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sockfd, status;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    status = inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    if (status == -1) {
        perror("invalid address family");
        exit(EXIT_FAILURE);
    } else if (status == 0) {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send data to server
    char *message = "Hello from client";
    printf("Sending message to server: '%s'\n", message);
    send(sockfd, message, strlen(message), 0);

    // Receive response from server
    int read_status = read(sockfd, buffer, BUFFER_SIZE);
    if (read_status == -1) {
        perror("failed to read from server");
        exit(EXIT_FAILURE);
    } else if (read_status == 0) {
        printf("Server disconnected\n");
        exit(EXIT_SUCCESS);
    }

    printf("Received message from server: '%s'\n", buffer);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}
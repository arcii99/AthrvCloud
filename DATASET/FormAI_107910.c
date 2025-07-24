//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8000
#define MAX_MSG_LENGTH 256

int main()
{
    int sockfd;
    char buffer[MAX_MSG_LENGTH];
    struct sockaddr_in server_addr;

    // Create socket for client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket: ");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully!\n");

    // Set server address to connect to
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);

    // Attempt to connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server: ");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server!\n");

    // Send message to server
    memset(buffer, 0, MAX_MSG_LENGTH);
    strcpy(buffer, "Hi, server!");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message: ");
        exit(EXIT_FAILURE);
    }
    printf("Message sent to server!\n");

    // Receive message from server
    memset(buffer, 0, MAX_MSG_LENGTH);
    if (recv(sockfd, buffer, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving message: ");
        exit(EXIT_FAILURE);
    }
    printf("Received message from server: %s\n", buffer);

    // Close socket
    close(sockfd);
    printf("Socket closed.\n");

    return 0;
}
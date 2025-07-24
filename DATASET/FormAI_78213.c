//FormAI DATASET v1.0 Category: Socket programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUM 8000
#define BUFFER_SIZE 1024

int main()
{
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUM);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Communicate with the server
    while (1) {
        // Send the message
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }

        // Receive the message
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            perror("Error receiving message");
            exit(EXIT_FAILURE);
        }
        printf("Received message: %s", buffer);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
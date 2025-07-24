//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8888
#define MAX_BUFFER_SIZE 1024

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server\n");

    // Send request to the server
    char request[MAX_BUFFER_SIZE] = "Hello, Server!";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Failed to send request to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Request sent to the server: %s\n", request);

    // Receive response from the server
    char response[MAX_BUFFER_SIZE];
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Response received from the server: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}
//FormAI DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define PORT_NUM 8080

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket.\n");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NUM);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Error setting IP address.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];

    // Send message to server
    strcpy(buffer, "Hello from client");
    write(sockfd, buffer, strlen(buffer));

    // Read response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}
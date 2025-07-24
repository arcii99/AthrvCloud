//FormAI DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, valread;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(sockfd, 3) < 0) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
        perror("Socket accepting failed");
        exit(EXIT_FAILURE);
    }

    // Read incoming message from client
    char buffer[1024] = { 0 };
    valread = read(new_sockfd, buffer, 1024);
    printf("Received message: %s\n", buffer);

    // Send response to client
    char *response = "Hello from server!";
    send(new_sockfd, response, strlen(response), 0);
    printf("Response sent\n");

    return 0;
}
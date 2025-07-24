//FormAI DATASET v1.0 Category: Simple Web Server ; Style: genious
// A Simple Web Server in C
// By [Your Name], [Your Email]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char response[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        socklen_t client_addr_size = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_size);
        if (client_sockfd == -1) {
            perror("Error accepting connection");
            continue;
        }

        // Read HTTP request
        char request[1024];
        size_t bytes_read = read(client_sockfd, request, 1024);
        request[bytes_read] = '\0';
        printf("Request received:\n%s\n", request);

        // Generate response
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: 5\r\n\r\nHello");
        // Send response
        write(client_sockfd, response, strlen(response));

        // Close connection
        close(client_sockfd);
    }

    // Close socket
    close(sockfd);

    return 0;
}
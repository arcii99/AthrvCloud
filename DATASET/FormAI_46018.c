//FormAI DATASET v1.0 Category: Simple Web Server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char* argv[]) {
    struct sockaddr_in server_addr, client_addr;
    int sockfd, client_sockfd;
    socklen_t client_length;
    char buffer[BUFSIZE];
    char response[BUFSIZE];
    int response_length;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr)); // Zero out structure
    server_addr.sin_family = AF_INET; // Address family
    server_addr.sin_port = htons(PORT); // Assign port to this address
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept any incoming address

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening");
        exit(1);
    }

    printf("Server running on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        client_length = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_length);
        if (client_sockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Read client request
        memset(buffer, 0, BUFSIZE);
        if (read(client_sockfd, buffer, BUFSIZE) < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        // Print client request
        printf("Received message: %s\n", buffer);

        // Generate server response
        response_length = snprintf(response, BUFSIZE, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello World!");

        // Send server response
        if (write(client_sockfd, response, response_length) < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        // Close client connection
        close(client_sockfd);
    }

    // Close server socket
    close(sockfd);

    return 0;
}
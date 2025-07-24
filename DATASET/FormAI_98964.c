//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Initialize variables
    int serve_sockfd, client_sockfd, port_no, request_size;
    char buffer[4096], response[4096];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;

    // Create server socket
    serve_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serve_sockfd < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Set server address
    memset((char*)&server_addr, 0, sizeof(server_addr));
    port_no = 8080;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_no);

    // Bind socket to address
    if (bind(serve_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to address");
        exit(1);
    }

    // Listen for client requests
    if (listen(serve_sockfd, 5) < 0) {
        perror("Error listening for client requests");
        exit(1);
    }

    // Accept client requests and send response
    while (1) {
        client_size = sizeof(client_addr);
        client_sockfd = accept(serve_sockfd, (struct sockaddr*)&client_addr, &client_size);
        if (client_sockfd < 0) {
            perror("Error accepting client request");
            continue;
        }

        // Receive client request
        request_size = read(client_sockfd, buffer, 4096);
        if (request_size < 0) {
            perror("Error receiving client request");
            close(client_sockfd);
            continue;
        }

        // Prepare response
        sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: close\n\n<html><body><h1>Hello World!</h1></body></html>");

        // Send response
        if (write(client_sockfd, response, strlen(response)) < 0) {
            perror("Error sending response to client");
        }

        // Close client socket
        close(client_sockfd);
    }

    // Close server socket
    close(serve_sockfd);

    return 0;
}
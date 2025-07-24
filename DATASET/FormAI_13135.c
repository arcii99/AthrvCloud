//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
/*
* This program creates a simple TCP/IP server that listens for incoming
* connections. Once a client connects, the server sends a welcome message
* and then echoes back any messages received from the client.
* 
* Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define ERROR(msg) { perror(msg); exit(EXIT_FAILURE); } // Macro for error handling

#define PORT 8080                        // Port number to listen on
#define BACKLOG 5                        // Maximum number of pending connections

int main() {
    int sockfd;                          // Socket file descriptor
    int newsockfd;                       // Socket file descriptor for new connection
    int opt = 1;                         // Option value for setsockopt
    struct sockaddr_in server_address;   // Server address information
    struct sockaddr_in client_address;   // Client address information
    socklen_t client_address_len;
    char buffer[256];                    // Buffer to store incoming data
    int n;                               // Number of bytes read/write

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        ERROR("Error opening socket");

    // Set socket options to reuse address
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)
        ERROR("Error setting socket options");

    // Set server address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0)
        ERROR("Error binding socket");

    // Listen for incoming connections
    if (listen(sockfd, BACKLOG) < 0)
        ERROR("Error listening for connections");

    printf("Listening for incoming connections on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        client_address_len = sizeof(client_address);
        newsockfd = accept(sockfd, (struct sockaddr*) &client_address, &client_address_len);
        if (newsockfd < 0)
            ERROR("Error accepting incoming connection");

        printf("Accepted incoming connection from %s:%d\n", 
                inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Send welcome message to client
        char* welcome_msg = "Welcome to my TCP/IP server!\n";
        write(newsockfd, welcome_msg, strlen(welcome_msg));

        while (1) {
            // Read data from client
            memset(buffer, 0, 256);
            n = read(newsockfd, buffer, 255);
            if (n < 0)
                ERROR("Error reading from socket");

            if (n == 0) {
                // Client disconnected
                printf("Client disconnected\n");
                break;
            }

            // Echo back data to client
            printf("Received message from client: %s", buffer);
            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0)
                ERROR("Error writing to socket");
        }

        // Close socket for this connection
        close(newsockfd);
    }

    // Close server socket
    close(sockfd);

    return 0;
}
//FormAI DATASET v1.0 Category: Client Server Application ; Style: asynchronous
// Asynchronous Client Server Application Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 5000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, clientfd, maxfd;
    socklen_t client_size;
    int bytes_read;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;
    fd_set readfds, writefds;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set the server address information
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR binding socket");
        exit(1);
    }

    // Listen for client connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR listening for clients");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    // Set the socket to non-blocking mode
    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    // Initialize the file descriptor set for select()
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    // Main loop
    while (1) {
        // Wait for activity on the socket using select()
        if (select(maxfd + 1, &readfds, &writefds, NULL, NULL) < 0) {
            perror("ERROR waiting for activity on socket");
            exit(1);
        }

        // Accept new client connections
        if (FD_ISSET(sockfd, &readfds)) {
            client_size = sizeof(client_address);
            clientfd = accept(sockfd, (struct sockaddr *) &client_address, &client_size);
            if (clientfd < 0) {
                perror("ERROR accepting client connection");
                exit(1);
            }

            // Set the client socket to non-blocking mode
            fcntl(clientfd, F_SETFL, O_NONBLOCK);

            // Add the client socket to the file descriptor set for select()
            FD_SET(clientfd, &readfds);
            if (clientfd > maxfd) {
                maxfd = clientfd;
            }

            printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));
        }

        // Handle activity on client sockets
        for (int i = sockfd + 1; i <= maxfd; i++) {
            if (FD_ISSET(i, &readfds)) {
                // Receive data from the client
                bytes_read = recv(i, buffer, BUFFER_SIZE, 0);
                if (bytes_read <= 0) {
                    // Client closed the connection or there was an error
                    close(i);
                    FD_CLR(i, &readfds);

                    printf("Client disconnected\n");

                    continue;
                }

                // Process the received data
                printf("Received %d bytes from client: %s\n", bytes_read, buffer);
            }
        }

        // Reset the file descriptor sets for select()
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        FD_SET(sockfd, &readfds);
        for (int i = sockfd + 1; i <= maxfd; i++) {
            FD_SET(i, &readfds);
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main() {

    int sockfd, client_sockfd[MAX_CLIENTS], activity, max_sd, new_socket;
    struct sockaddr_in addr;
    fd_set readfds;
    int opt = 1, i, addrlen = sizeof(addr);
    char buffer[1024] = {0};
    char *message = "Welcome to the server\r\n";

    // Create a master socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set master socket to allow multiple connections
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address and bind the socket
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Listening on port %d\n", PORT);

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockfd[i] = 0;
    }

    while (1) {
        // Clear the socket set
        FD_ZERO(&readfds);

        // Add master socket to set
        FD_SET(sockfd, &readfds);
        max_sd = sockfd;

        // Add child sockets to set
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockfd[i] > 0) {
                FD_SET(client_sockfd[i], &readfds);
            }

            if (client_sockfd[i] > max_sd) {
                max_sd = client_sockfd[i];
            }
        }

        // Wait for incoming connections or data
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        // Handle incoming connection
        if (FD_ISSET(sockfd, &readfds)) {
            if ((new_socket = accept(sockfd, (struct sockaddr *)&addr, (socklen_t*)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Send a welcome message to the client
            send(new_socket, message, strlen(message), 0);

            // Add the new socket to the array of sockets
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockfd[i] == 0) {
                    client_sockfd[i] = new_socket;
                    printf("New client connected. Socket fd is %d. IP is %s. Port is %d\n", new_socket, inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
                    break;
                }
            }
        }

        // Handle incoming data
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_sockfd[i], &readfds)) {
                if (read(client_sockfd[i], buffer, 1024) == 0) {
                    // Client disconnected
                    printf("Client disconnected. Socket fd is %d. IP is %s. Port is %d\n", client_sockfd[i], inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
                    close(client_sockfd[i]);
                    client_sockfd[i] = 0;
                } else {
                    // Echo back the message to the client
                    send(client_sockfd[i], buffer, strlen(buffer), 0);
                    printf("Receive from fd=%d: %s\n", client_sockfd[i], buffer);
                    memset(buffer, 0, sizeof(buffer));
                }
            }
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Socket programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9000

int main() {
    printf("Welcome to Retro Socket Programming!\n");

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    int bind_status = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (bind_status < 0) {
        perror("Error binding socket to port");
        exit(1);
    }

    // Listen for incoming connections
    int listen_status = listen(sockfd, 1);
    if (listen_status < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Socket bound to port %d, listening for incoming connections...\n", PORT);

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_size);
    if (client_sockfd < 0) {
        perror("Error accepting incoming connection");
        exit(1);
    }

    printf("Incoming connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    char buffer[256];
    int num_bytes;

    // Send welcome message to client
    const char* welcome_message = "Welcome to Retro Socket Programming! Please enter a message.\n";
    send(client_sockfd, welcome_message, strlen(welcome_message), 0);

    // Receive messages from client and send back as uppercase
    while (1) {
        num_bytes = recv(client_sockfd, buffer, 255, 0);
        if (num_bytes < 0) {
            perror("Error receiving message from client");
            exit(1);
        }
        if (num_bytes == 0) {
            printf("Client disconnected.\n");
            break;
        }

        // Convert message to uppercase
        for (int i = 0; i < num_bytes; i++) {
            buffer[i] = toupper(buffer[i]);
        }

        send(client_sockfd, buffer, num_bytes, 0);
    }

    // Close sockets and exit
    close(client_sockfd);
    close(sockfd);

    return 0;
}
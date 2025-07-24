//FormAI DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_MESSAGE_LENGTH 1024

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char message[MAX_MESSAGE_LENGTH] = {0};
    char buffer[MAX_MESSAGE_LENGTH] = {0};

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for clients
    if (listen(server_sock, 10) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server up and running! Waiting for clients...\n");

    socklen_t addr_len = sizeof(client_addr);

    // Accept incoming client connection
    if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
        perror("Error accepting connection from client");
        exit(EXIT_FAILURE);
    }

    printf("Client connected successfully! Client IP: %s, Port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
        printf("Enter message to send to client: ");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);

        // Send message to client
        if (send(client_sock, message, strlen(message), 0) == -1) {
            perror("Error sending message");
            exit(EXIT_FAILURE);
        }

        printf("Message sent to client!\n");

        // Receive message from client
        memset(buffer, 0, sizeof(buffer));
        if (recv(client_sock, buffer, MAX_MESSAGE_LENGTH, 0) == -1) {
            perror("Error receiving message");
            exit(EXIT_FAILURE);
        }

        printf("Message received from client: %s\n", buffer);
    }

    // Close sockets
    close(client_sock);
    close(server_sock);

    return 0;
}
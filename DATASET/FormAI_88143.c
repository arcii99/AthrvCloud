//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host = argv[1];

    // Create a socket for the client
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("[ERROR] Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Create the server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0) {
        perror("[ERROR] Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("[ERROR] Unable to connect");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    // Send data to the server
    printf("Enter message to send: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Send the message
    if (send(client_fd, buffer, strlen(buffer), 0) < 0) {
        perror("[ERROR] Failed to send data");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server: %s", buffer);

    // Receive data from the server
    memset(buffer, 0, BUFFER_SIZE);

    if (recv(client_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("[ERROR] Failed to receive data");
        exit(EXIT_FAILURE);
    }

    printf("Message received from server: %s", buffer);

    close(client_fd);

    return 0;
}
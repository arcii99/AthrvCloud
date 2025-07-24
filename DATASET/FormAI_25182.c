//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Address conversion error");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server successfully!\n");

    char message[1024] = {0};
    printf("Enter message to send to server: ");
    fgets(message, 1024, stdin);

    // Send message to server
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Sending error");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server successfully!\n");

    char buffer[1024] = {0};
    // Receive response from server
    if (recv(client_socket, buffer, 1024, 0) < 0) {
        perror("Receiving error");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buffer);

    // Close socket
    close(client_socket);

    return 0;
}
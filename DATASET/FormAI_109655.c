//FormAI DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {

    int sock_fd;
    struct sockaddr_in server_address;
    char message[BUF_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed\n");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address / Address not supported\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server socket
    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed\n");
        exit(EXIT_FAILURE);
    }

    // Send messages to server
    while (1) {
        printf("Enter message: ");
        fgets(message, BUF_SIZE, stdin);
        send(sock_fd, message, strlen(message), 0 );
        printf("Message sent\n");

        // Exit if user types "exit"
        if (strcmp(message, "exit\n") == 0) {
            break;
        }

        // Receive response from server
        memset(message, 0, BUF_SIZE);
        recv(sock_fd, message, BUF_SIZE, 0);
        printf("Server response: %s\n", message);
    }

    // Close socket file descriptor
    close(sock_fd);
    return 0;
}
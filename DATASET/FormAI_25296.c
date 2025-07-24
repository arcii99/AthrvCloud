//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int socket_fd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    // Infinite loop to keep communicating with server
    while (1) {

        printf("Enter message: ");
        memset(buffer, 0, BUFFER_SIZE); // Clear buffer
        fgets(buffer, BUFFER_SIZE, stdin); // Read from user input

        // Send message to server
        if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Send Failed");
            exit(EXIT_FAILURE);
        }

        // Clear buffer and receive response from server
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(socket_fd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Recv Failed");
            exit(EXIT_FAILURE);
        }

        printf("Server Response: %s\n", buffer);
    }

    close(socket_fd);
    return 0;
}
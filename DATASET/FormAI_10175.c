//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int socket_fd, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = { 0 };
    char message[BUFFER_SIZE];

    // Create a TCP socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure socket parameters
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Prompt user for input
    printf("Enter a message: ");
    fgets(message, BUFFER_SIZE, stdin);

    // Send message to the server
    send(socket_fd, message, strlen(message), 0);
    printf("Message sent: %s", message);

    // Receive message from the server
    valread = read(socket_fd, buffer, BUFFER_SIZE);
    printf("Message received: %s", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}
//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int socket_fd;
    struct sockaddr_in server_address;

    char *message = "Hello from client";

    // Creating socket file descriptor of IPV4 stream type
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Assigning server details in sockaddr_in
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Setting the address to 127.0.0.1 (localhost)
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("inet_pton error occurred");
        exit(EXIT_FAILURE);
    }

    // Connect to server socket
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Sending message
    if (send(socket_fd, message, strlen(message), 0) != strlen(message)) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server\n");

    // Receiving response from server
    char buffer[1024] = {0};
    if (read(socket_fd, buffer, 1024) < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buffer);

    // Closing socket
    close(socket_fd);

    return 0;
}
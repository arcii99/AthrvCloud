//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
// include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// define constants
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    // create socket file descriptor
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Failed to create socket file descriptor.\n");
        exit(EXIT_FAILURE);
    }

    // set server address and port
    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // convert IP address from string to binary form and assign to server_address struct
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("Invalid IP address.\n");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server.\n");
        exit(EXIT_FAILURE);
    }

    // get message from user
    char message[BUFFER_SIZE] = {0};
    printf("Enter message to send to server: ");
    fgets(message, BUFFER_SIZE, stdin);

    // send message to server
    send(socket_fd, message, strlen(message), 0);
    printf("Message sent to server.\n");

    // receive response from server
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);

    // print response from server
    printf("Response from server: %.*s\n", bytes_received, buffer);

    // close socket file descriptor
    close(socket_fd);

    return 0;
}
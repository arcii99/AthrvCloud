//FormAI DATASET v1.0 Category: Socket programming ; Style: thoughtful
/* This program demonstrates a simple client-server communication using C sockets.
The client sends a message to the server and the server responds with a confirmation message.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    char message[] = "Hello from the client";

    // Creating a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Filling in the server's address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Connecting to the server
    if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Sending a message to the server
    send(socket_fd, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Receiving a response from the server
    read(socket_fd, buffer, 1024);
    printf("Server response: %s\n", buffer);

    // Closing the socket
    close(socket_fd);

    return 0;
}
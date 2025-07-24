//FormAI DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket_fd, val_read;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    const char *hello = "Hello from server!";

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Preparing sockaddr_in structure
    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    // Binding socket to the specified port
    if (bind(socket_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connection request
    if ((new_socket_fd = accept(socket_fd, (struct sockaddr *) &address, (socklen_t*) &address)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Reading data received from client
    val_read = read(new_socket_fd, buffer, 1024);
    printf("%s\n", buffer);

    // Sending response to client 
    send(new_socket_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    return 0;
}
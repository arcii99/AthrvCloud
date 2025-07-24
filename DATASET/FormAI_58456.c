//FormAI DATASET v1.0 Category: Networking ; Style: Linus Torvalds
/* Linus Torvalds-style C Networking Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int server_fd, new_socket;
    struct sockaddr_in address;

    int opt = 1;
    int addrlen = sizeof(address);

    // Creating server socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == 0) {
        perror("Socket Creation Error");
        exit(EXIT_FAILURE);
    }

    // Set socket option to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set Socket Option Error");
        exit(EXIT_FAILURE);
    }

    // Construct the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind server to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind Error");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections with maximum backlog of 3
    if (listen(server_fd, 3) < 0) {
        perror("Listen Error");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept Error");
        exit(EXIT_FAILURE);
    }

    // Send message to the client
    const char *message = "Hello from server!";
    send(new_socket, message, strlen(message), 0);

    printf("Hello message sent\n");

    return 0;
}
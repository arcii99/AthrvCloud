//FormAI DATASET v1.0 Category: Socket programming ; Style: Alan Touring
// Alan Turing Style C Socket Programming Example

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address and port
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    int bind_result = bind(socket_fd, (struct sockaddr *) &address, sizeof(address));
    if (bind_result == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listen_result = listen(socket_fd, 5);
    if (listen_result == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection and handle it
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_fd = accept(socket_fd, (struct sockaddr *) &client_address, &client_address_len);
    if (client_fd == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    // Receive data from client
    char receive_buffer[1024];
    recv(client_fd, receive_buffer, sizeof(receive_buffer), 0);

    // Send response back to client
    char response_buffer[1024] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    send(client_fd, response_buffer, sizeof(response_buffer), 0);

    // Clean up
    close(client_fd);
    close(socket_fd);

    return 0;
}
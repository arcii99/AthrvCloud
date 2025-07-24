//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int socket_fd, new_socket_fd, read_bytes;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    char *greeting = "Welcome to my TCP/IP chat application!";

    // create TCP socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    // prepare server address data structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind the socket to the IP and port
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket to IP and port.\n");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        printf("Failed to listen for incoming connections.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d.\n", PORT);

    // accept incoming connection
    socklen_t client_addr_len = sizeof(client_addr);
    new_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (new_socket_fd < 0) {
        printf("Failed to accept incoming connection.\n");
        exit(EXIT_FAILURE);
    }

    // send welcome message to client
    send(new_socket_fd, greeting, strlen(greeting), 0);

    // receive messages from client
    while ((read_bytes = read(new_socket_fd, buffer, BUFFER_SIZE)) > 0) {
        printf("Received message from client: %s", buffer);

        // send back the same message to client
        send(new_socket_fd, buffer, strlen(buffer), 0);

        // clear the buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (read_bytes == 0) {
        printf("Client disconnected.\n");
    } else {
        printf("Failed to receive message from client.\n");
    }

    // close the sockets
    close(new_socket_fd);
    close(socket_fd);

    return 0;
}
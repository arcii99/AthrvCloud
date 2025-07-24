//FormAI DATASET v1.0 Category: Client Server Application ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT_NUMBER 8080

int main(int argc, char *argv[]) {
    int socket_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // bind socket to server address
    if (bind(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(socket_fd, 1) == -1) {
        perror("Failed to listen for incoming connections");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // accept incoming connection
    socklen_t client_address_size = sizeof(client_address);
    client_fd = accept(socket_fd, (struct sockaddr*) &client_address, &client_address_size);
    if (client_fd == -1) {
        perror("Failed to accept incoming connection");
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // receive message from client
    if ((bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0)) == -1) {
        perror("Failed to receive message from client");
        close(client_fd);
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // print message received from client
    printf("Message received: %.*s\n", bytes_received, buffer);

    // send response to client
    char response[] = "Thank you for connecting!";
    if (send(client_fd, response, strlen(response), 0) == -1) {
        perror("Failed to send response to client");
        close(client_fd);
        close(socket_fd);
        exit(EXIT_FAILURE);
    }

    // close client connection and socket
    close(client_fd);
    close(socket_fd);

    return EXIT_SUCCESS;
}
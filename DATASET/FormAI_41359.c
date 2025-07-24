//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int socket_fd;

    // create a new socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // configure the address struct
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(9999);
    address.sin_addr.s_addr = INADDR_ANY;

    // bind the address to the socket
    bind(socket_fd, (struct sockaddr *)&address, sizeof(address));

    // start listening on the socket
    listen(socket_fd, 5);

    // accept incoming connections
    int client_fd;
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    client_fd = accept(socket_fd, (struct sockaddr *)&client_address, &client_address_length);

    // send a surreal message to the client
    char *message = "The cat is a clownfish in disguise. The client is free to interpret this message however they wish.";
    send(client_fd, message, strlen(message), 0);

    // close the socket
    close(socket_fd);

    return 0;
}
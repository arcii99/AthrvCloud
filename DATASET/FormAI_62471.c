//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int server_socket, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int address_length = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *message = "Hello from server";
     
    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error("Failed to create server socket");
    }

    // set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("Failed to set socket options");
    }

    // set address type and port number
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the specified address and port number
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        error("Failed to bind the server socket");
    }

    // listen for incoming connections
    if (listen(server_socket, 3) == -1) {
        error("Failed to listen for incoming connections");
    }

    printf("Server is now listening on port %d\n", PORT);

    // accept incoming connections
    if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&address_length)) == -1) {
        error("Failed to accept incoming connection");
    }

    // send message to client
    send(new_socket, message, strlen(message), 0);
    printf("Message sent to client: %s\n", message);

    // receive message from client
    valread = read(new_socket, buffer, BUFFER_SIZE);
    printf("Message received from client: %s\n", buffer);

    // close sockets
    close(new_socket);
    close(server_socket);

    return 0;
}
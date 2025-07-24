//FormAI DATASET v1.0 Category: Socket programming ; Style: standalone
// unique socket programming example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, read_val;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    char buffer[BUFFER_SIZE] = {0}, *hello = "Hello from server";

    // create a socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // fill in socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // accept an incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // read data from the client
        read_val = read(new_socket, buffer, BUFFER_SIZE);
        if (read_val < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        // print the data received from the client
        printf("Client: %s\n", buffer);

        // send a message to the client
        send(new_socket, hello, strlen(hello), 0);
        printf("Server: Hello message sent\n");

        // clear out the buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server! :)";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Could not create socket\n");
        return -1;
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Could not set socket options\n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0 ) {
        printf("Could not bind socket to address and port\n");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Could not listen for incoming connections\n");
        return -1;
    }

    // Wait for and accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        printf("Could not accept incoming connection\n");
        return -1;
    }

    // Send message to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Message sent to client! :)\n");

    // Receive message from client
    valread = read(new_socket, buffer, BUFFER_SIZE);
    printf("Message received from client: %s\n", buffer);

    // Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}
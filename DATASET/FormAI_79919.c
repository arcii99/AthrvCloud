//FormAI DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Hello from the server!";

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
  
    // Forcefully attaching socket to the PORT
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
  
    // Binding the socket to the IP address and port
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connections
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t *)&address_len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Reading incoming message
    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    // Sending reply to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    return 0;
}
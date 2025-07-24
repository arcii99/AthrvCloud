//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char **argv) { 
    // Simple TCP server to receive shape shifting data
    int server_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind server to socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for clients
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receive data from client
    char buffer[1024] = {0};
    valread = read(new_socket, buffer, 1024);

    // Shape-shift the data
    int length = strlen(buffer);
    for (int i = 0; i < length; i++) {
        if (buffer[i] == '0') {
            buffer[i] = '1';
        } else {
            buffer[i] = '0';
        }
    }

    // Send the shape-shifted data back to the client
    printf("Shape-shifted data: %s\n", buffer);
    write(new_socket, buffer, strlen(buffer));

    // Close sockets and exit
    close(new_socket);
    close(server_fd);

    return 0;
}
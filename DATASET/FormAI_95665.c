//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to PORT
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                &opt, sizeof(opt))) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the given address
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening to the socket
    if (listen(socket_fd, 3) < 0) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    // Accept clients
    if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, 
                    (socklen_t*)&addrlen))<0) {
        perror("accept error");
        exit(EXIT_FAILURE);
    }

    // Read from the client
    val_read = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);

    // Send message to client
    send(new_socket, hello, strlen(hello), 0);

    // Close sockets and exit
    close(new_socket);
    close(socket_fd);
    return 0;
}
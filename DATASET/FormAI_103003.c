//FormAI DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, ret, opt_val;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    opt_val = 1;
    ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val));
    if (ret == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting address structure
    memset(&address, 0, addrlen);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket
    ret = bind(server_fd, (struct sockaddr *)&address, addrlen);
    if (ret == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening to incoming connections
    ret = listen(server_fd, 3);
    if (ret == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // accepting incoming connections
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (new_socket == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Verifying the identity of the client
    ret = read(new_socket, buffer, BUFFER_SIZE);
    if (ret == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", buffer);
    if (strcmp(buffer, "hello") == 0) {
        char *message = "hello from the server";
        write(new_socket, message, strlen(message));
    } else {
        char *error_message = "invalid message";
        write(new_socket, error_message, strlen(error_message));
    }

    // Closing sockets
    close(new_socket);
    close(server_fd);
    return 0;
}
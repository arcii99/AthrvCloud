//FormAI DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void recursive_echo(int client_fd) {
    char buffer[1024] = {0};
    int read_val = read(client_fd, buffer, 1024);
    if (read_val == -1) {
        perror("Error in read");
        exit(EXIT_FAILURE);
    }
    else if (read_val == 0) {
        printf("Client Disconnected\n");
        return;
    }
    printf("Client message: %s\n", buffer);
    int sent_val = send(client_fd, buffer, read_val, 0);
    if (sent_val == -1) {
        perror("Error in send");
        exit(EXIT_FAILURE);
    }
    recursive_echo(client_fd);
}

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the given IP address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error in binding");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Error in listen");
        exit(EXIT_FAILURE);
    }

    // Accepting connections in a recursive manner
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address,
                          (socklen_t*)&address_len))<0) {
            perror("Error in accept");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted\n");
        recursive_echo(client_fd);
    }

    return 0;
}
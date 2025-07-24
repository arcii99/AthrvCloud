//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
/*
 * This program demonstrates TCP/IP programming in C using sockets.
 * It creates a client-server connection where the client sends a
 * message to the server and the server echoes it back to the client.
 * 
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    int opt = 1;
    int addrlen = sizeof(address);

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // bind socket to address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // accept incoming client connections
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Got a new connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // read incoming message from client
    int read_size;
    while ((read_size = recv(client_fd, buffer, 1024, 0)) > 0 ) {
        printf("Received message: %s", buffer);

        // echo message back to client
        write(client_fd, buffer, strlen(buffer));
        memset(buffer, 0, 1024);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
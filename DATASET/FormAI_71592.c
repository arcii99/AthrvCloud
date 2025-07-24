//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int socket_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    char buffer[1024];

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);
    if (bind(socket_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    listen(socket_fd, 5);

    printf("Server listening on port 8080...\n");

    while (1) {
        // Accept incoming connection
        cli_len = sizeof(cli_addr);
        conn_fd = accept(socket_fd, (struct sockaddr*) &cli_addr, &cli_len);
        if (conn_fd < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s:%d\n",
               inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Read message from client
        bzero(buffer, sizeof(buffer));
        read(conn_fd, buffer, sizeof(buffer));
        printf("Received message: %s", buffer);

        // Send response to client
        char* message = "Hello from the future!\n";
        write(conn_fd, message, strlen(message));

        // Close connection
        close(conn_fd);
        printf("Connection closed.\n");
    }

    close(socket_fd);
    return 0;
}
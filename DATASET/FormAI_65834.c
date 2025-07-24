//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_MAX 1024

int main(int argc, char const *argv[]) {
    int socketfd = 0, new_socket = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_MAX] = {0};

    // Creating socket file descriptor
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(socketfd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    // When a client connects, accept the connection
    if ((new_socket = accept(socketfd, (struct sockaddr *)NULL, NULL)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read message from the client and send it back
    while (1) {
        int bytes_read = recv(new_socket, buffer, BUFFER_MAX, 0);
        if (bytes_read > 0) {
            printf("Received message from client: %s\n", buffer);
            send(new_socket, buffer, strlen(buffer), 0);
            memset(buffer, 0, BUFFER_MAX);
        }
    }

    // Close the sockets
    close(socketfd);
    close(new_socket);

    return 0;
}
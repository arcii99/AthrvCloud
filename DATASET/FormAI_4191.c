//FormAI DATASET v1.0 Category: Client Server Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4444

int main() {
    int server_fd, client_fd, n;
    struct sockaddr_in server_address, client_address;
    char buffer[256];

    // Creating socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Clearing server_address struct
    bzero((char *)&server_address, sizeof(server_address));

    // Setting server_address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding socket to port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind to port");
        exit(1);
    }

    // Listening to incoming connections
    listen(server_fd, 5);

    printf("Server running on port %d\n", PORT);

    // Accepting client connection
    socklen_t client_length = sizeof(client_address);
    client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_length);

    while (1) {
        bzero(buffer, 256);
        n = read(client_fd, buffer, 255);
        if (n < 0) {
            perror("Failed to read from socket");
            exit(1);
        }
        printf("Client: %s", buffer);

        bzero(buffer, 256);
        printf("Server: ");
        fgets(buffer, 255, stdin);
        n = write(client_fd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Failed to write to socket");
            exit(1);
        }
    }

    // Closing sockets
    close(client_fd);
    close(server_fd);

    return 0;
}
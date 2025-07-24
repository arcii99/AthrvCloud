//FormAI DATASET v1.0 Category: Networking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    if (listen(fd, 5) < 0) {
        perror("Error listening on socket");
        exit(1);
    }
    printf("Server waiting for client connections...\n");

    while (1) {
        int client_fd = accept(fd, NULL, NULL);
        if (client_fd < 0) {
            perror("Error accepting client connection");
        } else {
            printf("Client connected.\n");
            char buffer[100];
            while (recv(client_fd, buffer, sizeof(buffer), 0) > 0) {
                printf("Client message: %s", buffer);
                send(client_fd, buffer, sizeof(buffer), 0);
                memset(buffer, 0, sizeof(buffer));
            }
            printf("Client disconnected.\n");
        }
    }
    return 0;
}
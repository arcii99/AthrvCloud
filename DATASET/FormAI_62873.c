//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = "Hello, client! I'm your happy server!";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        printf("Could not create the socket.\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind to the socket.\n");
        return -1;
    }

    if (listen(server_fd, 1) < 0) {
        printf("Could not listen to the socket.\n");
        return -1;
    }

    printf("Server is listening on port %d...\n", SERVER_PORT);

    socklen_t client_addr_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_len);

    if (client_fd < 0) {
        printf("Could not accept the connection.\n");
        return -1;
    }

    printf("Client connected from %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    send(client_fd, buffer, strlen(buffer), 0);

    printf("Message sent to the client: %s\n", buffer);

    close(client_fd);
    close(server_fd);

    return 0;
}
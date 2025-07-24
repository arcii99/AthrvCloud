//FormAI DATASET v1.0 Category: Client Server Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUF_SIZE 1024

void error_handler(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, client_fd, valread;
    struct sockaddr_in server_address = {0};
    struct sockaddr_in client_address = {0};
    char buffer[BUF_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handler("Failed to create socket");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error_handler("Failed to bind");
    }

    if (listen(server_fd, 3) < 0) {
        error_handler("Failed to listen");
    }

    printf("Waiting for connections...\n");

    int addrlen = sizeof(struct sockaddr_in);

    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
        error_handler("Failed to accept connection");
    }

    printf("Connection accepted!\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        valread = read(client_fd, buffer, BUF_SIZE);

        if (valread < 0) {
            error_handler("Failed to read from socket");
        }

        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Closing connection\n");
            break;
        }

        printf("Server: ");
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (send(client_fd, buffer, strlen(buffer), 0) < 0) {
            error_handler("Failed to send message to client");
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("Closing connection\n");
            break;
        }
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
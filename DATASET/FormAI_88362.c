//FormAI DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE] = {0};
    int read_bytes = read(client_fd, buffer, BUFFER_SIZE);
    if (read_bytes == -1) {
        printf("Failed to read from client\n");
        return;
    }

    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
    write(client_fd, response, strlen(response));
    close(client_fd);
}

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Failed to set socket options\n");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Failed to bind socket\n");
        return 1;
    }

    if (listen(server_fd, 3) < 0) {
        printf("Failed to listen on socket\n");
        return 1;
    }

    printf("Server started on port %d...\n", PORT);

    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            printf("Failed to accept client\n");
            continue;
        }

        printf("Client connected\n");

        pid_t pid = fork();
        if (pid == -1) {
            printf("Failed to fork child process\n");
            return 1;
        } else if (pid == 0) {
            handle_client(client_fd);
            return 0;
        } else {
            close(client_fd);
        }
    }

    return 0;
}
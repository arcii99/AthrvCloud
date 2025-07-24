//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock_fd, 5);

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        int read_bytes = read(client_sock_fd, buffer, BUFFER_SIZE);

        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n<!DOCTYPE html><html><head><title>Simple Web Server</title></head><body><h1>Welcome to the Simple Web Server!</h1></body></html>";

        write(client_sock_fd, response, strlen(response));

        close(client_sock_fd);
    }

    close(sock_fd);

    return 0;
}
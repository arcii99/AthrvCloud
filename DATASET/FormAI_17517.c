//FormAI DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define SERVER_PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[2048] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        error("Error creating socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error binding socket");
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        error("Error listening on socket");
    }

    while (1) {
        socklen_t client_len = sizeof(client_addr);

        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            error("Error accepting client connection");
        }

        int n = read(client_fd, buffer, 2047);
        if (n < 0) {
            error("Error reading from socket");
        }

        // Check for HTTP request
        if (strncmp(buffer, "GET / HTTP/1.1", 14) != 0) {
            // Invalid request
            write(client_fd, "HTTP/1.1 400 Bad Request\r\n", 25);
            close(client_fd);
            continue;
        }

        // Write response header
        char *response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        write(client_fd, response_header, strlen(response_header));

        // Write response content
        char *response_content = "<html><body><h1>Hello, World!</h1></body></html>";
        write(client_fd, response_content, strlen(response_content));
        close(client_fd);
    }

    return 0;
}
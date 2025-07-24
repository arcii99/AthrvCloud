//FormAI DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, addrlen) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Handle incoming connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Fork new process to handle incoming request
        int pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process: handle request
            char buffer[30000] = {0};
            int valread = read(new_socket, buffer, 30000);

            // Get requested file path from request
            char *start = strstr(buffer, "GET /") + 5;
            char *end = strstr(start, "HTTP");
            char file_path[end - start + 1];
            memcpy(file_path, start, end - start);
            file_path[end - start] = '\0';

            // Open requested file
            int file_fd = open(file_path, O_RDONLY);
            char file_buffer[30000] = {0};
            if (file_fd > 0) {
                // Read file contents into buffer
                read(file_fd, file_buffer, 30000);
                close(file_fd);
            } else {
                // File not found
                char *error = "HTTP/1.1 404 Not Found\nContent-Length: 0\n\n";
                send(new_socket, error, strlen(error), 0);
                close(new_socket);
                return 0;
            }

            // Send file contents in response
            char response[strlen(file_buffer) + strlen(hello)];
            sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %ld\n\n%s%s", strlen(file_buffer) + strlen(hello), hello, file_buffer);
            send(new_socket, response, strlen(response), 0);
            close(new_socket);
            return 0;
        }
    }

    return 0;
}
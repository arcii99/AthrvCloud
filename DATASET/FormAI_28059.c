//FormAI DATASET v1.0 Category: Simple Web Server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define WEB_ROOT "./web_root"
#define MAX_CONNECTIONS 10
#define MAX_REQUEST_SIZE 2048
#define MAX_RESPONSE_SIZE 4096

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_REQUEST_SIZE] = {0};
    char response[MAX_RESPONSE_SIZE] = {0};
    char filepath[128] = {0};
    char request[8] = {0};
    ssize_t num_bytes_read, num_bytes_written;
    int file_fd;
    int i;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port 8080 on all available network interfaces
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read request from client
        num_bytes_read = read(new_socket, buffer, MAX_REQUEST_SIZE);

        // Check if client sent a valid request
        if (num_bytes_read <= 0) {
            // Invalid request
            close(new_socket);
            continue;
        }

        // Copy HTTP method (GET or POST) from request
        for (i = 0; i < 7; i++) {
            if (buffer[i] == ' ') {
                break;
            }
            request[i] = buffer[i];
        }

        // Check if the HTTP method is GET or POST
        if (strcmp(request, "GET") != 0 && strcmp(request, "POST") != 0) {
            // Invalid request
            close(new_socket);
            continue;
        }

        // Copy filepath from request
        strtok(buffer, "\n"); // Remove first line (HTTP method and filepath)
        strcpy(filepath, strstr(buffer, " ")+1);
        strtok(filepath, " "); // Remove HTTP version

        // Check if filepath is valid
        if (strlen(filepath) <= 1) { // Root directory requested
            snprintf(filepath, sizeof(filepath), "%s/index.html", WEB_ROOT);
        } else {
            snprintf(filepath, sizeof(filepath), "%s%s", WEB_ROOT, filepath);
        }

        // Check if file exists and is readable
        file_fd = open(filepath, O_RDONLY);
        if (file_fd < 0) {
            // File does not exist or is not readable
            snprintf(response, sizeof(response), "HTTP/1.1 404 Not Found\r\n\r\n");
            num_bytes_written = write(new_socket, response, strlen(response));
            close(new_socket);
            continue;
        }

        // Send file to client
        snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\n");
        num_bytes_written = write(new_socket, response, strlen(response));
        while ((num_bytes_read = read(file_fd, buffer, sizeof(buffer))) > 0) {
            num_bytes_written = write(new_socket, buffer, num_bytes_read);
        }

        // Cleanup
        close(file_fd);
        close(new_socket);
    }
    return 0;
}
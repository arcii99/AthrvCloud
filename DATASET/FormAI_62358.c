//FormAI DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Assign address and port to socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Read HTTP request
        valread = read(new_socket, buffer, BUF_SIZE);
        printf("%s\n", buffer);

        // Extract filename from HTTP request
        char filename[BUF_SIZE];
        sscanf(buffer, "GET /%[^ ]", filename);
        printf("filename: %s\n", filename);

        // Open requested file
        int fd = open(filename, O_RDONLY, 0);
        if (fd < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Send file contents
        char file_buffer[BUF_SIZE];
        size_t bytes_read;
        while ((bytes_read = read(fd, file_buffer, BUF_SIZE)) > 0) {
            if (write(new_socket, file_buffer, bytes_read) < 0) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Close file and socket
        close(fd);
        close(new_socket);
    }

    return 0;
}
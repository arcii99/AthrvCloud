//FormAI DATASET v1.0 Category: Simple Web Server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORTNUMBER 8080

int main(void) {
    // Create the socket
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        return 1;
    }

    // Bind the socket to the address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORTNUMBER);

    if (bind(server_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    while (1) {
        int client_fd;
        struct sockaddr_in client_address;
        int address_length = sizeof(client_address);

        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr*) &client_address, (socklen_t*) &address_length)) < 0) {
            perror("Error accepting connection");
            return 1;
        }

        // Read request from client
        char buffer[1024] = {0};
        read(client_fd, buffer, 1024);

        // Extract pathname from request (path is assumed to be the first word of the request)
        char* path = strtok(buffer, " \t\n");

        // Open the requested file
        int file_fd = open(path + 1, O_RDONLY);
        if (file_fd < 0) {
            // If file not found, return 404 error
            char* not_found = "HTTP/1.1 404 Not Found\n\n";
            write(client_fd, not_found, strlen(not_found));
        } else {
            // If file found, return 200 OK and the file contents
            char* ok_header = "HTTP/1.1 200 OK\n\n";
            write(client_fd, ok_header, strlen(ok_header));

            // Read file contents and write to socket
            char file_buffer[1024] = {0};
            int bytes_read;
            while ((bytes_read = read(file_fd, file_buffer, 1024)) > 0) {
                write(client_fd, file_buffer, bytes_read);
            }

            // Close the file
            close(file_fd);
        }

        // Close the client connection
        close(client_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}
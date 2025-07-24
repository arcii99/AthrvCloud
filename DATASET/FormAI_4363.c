//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define PORT_NUMBER 8080
#define FILE_PATH "index.html"

int main(void)
{
    int server_fd, client_fd, bytes_read, file_fd;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE], *file_contents;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);
    struct stat file_stat;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 10) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT_NUMBER);

    while (1) {
        // Accept incoming connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_size);

        if (client_fd == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Read request from client
        bytes_read = read(client_fd, buffer, BUFFER_SIZE);

        if (bytes_read == -1) {
            perror("Error reading request");
            exit(EXIT_FAILURE);
        }

        // Make sure request is valid (ignoring headers)
        if (strncmp(buffer, "GET /", 5) != 0) {
            sprintf(response, "HTTP/1.0 400 Bad Request\n\n<html><body><h1>Bad Request</h1></body></html>");
            send(client_fd, response, strlen(response), 0);
            close(client_fd);
            continue;
        }

        // Open file
        file_fd = open(FILE_PATH, O_RDONLY);

        if (file_fd == -1) {
            sprintf(response, "HTTP/1.0 404 Not Found\n\n<html><body><h1>Not Found</h1></body></html>");
            send(client_fd, response, strlen(response), 0);
            close(client_fd);
            continue;
        }

        // Get file size
        if (fstat(file_fd, &file_stat) == -1) {
            perror("Error getting file size");
            sprintf(response, "HTTP/1.0 500 Internal Server Error\n\n<html><body><h1>Internal Server Error</h1></body></html>");
            send(client_fd, response, strlen(response), 0);
            close(client_fd);
            continue;
        }

        // Read file contents
        file_contents = malloc(file_stat.st_size + 1);
        bytes_read = read(file_fd, file_contents, file_stat.st_size);

        if (bytes_read != file_stat.st_size) {
            perror("Error reading file");
            sprintf(response, "HTTP/1.0 500 Internal Server Error\n\n<html><body><h1>Internal Server Error</h1></body></html>");
            send(client_fd, response, strlen(response), 0);
            close(client_fd);
            continue;
        }

        // Null-terminate file contents
        file_contents[bytes_read] = '\0';

        // Send response
        sprintf(response, "HTTP/1.0 200 OK\nContent-Length: %ld\n\n%s", strlen(file_contents), file_contents);
        send(client_fd, response, strlen(response), 0);

        // Cleanup
        free(file_contents);
        close(file_fd);
        close(client_fd);
    }

    return 0;
}
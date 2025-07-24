//FormAI DATASET v1.0 Category: Simple Web Server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8080
#define MAX_SIZE 1024

void handle_request(int client_socket) {
    char buffer[MAX_SIZE] = {0};
    read(client_socket, buffer, MAX_SIZE);

    // Split the request into different parts
    char * method = strtok(buffer, " ");
    char * path = strtok(NULL, " ");
    strtok(NULL, "\n");

    // Return index page when no path is specified
    if (strcmp(path, "/") == 0) {
        path = "/index.html";
    }

    // Construct file path
    char file_path[MAX_SIZE] = {0};
    sprintf(file_path, "www%s", path);

    // Check if file exists
    if (access(file_path, F_OK) == -1) {
        char * response = "HTTP/1.1 404 Not Found\r\n\r\n";
        write(client_socket, response, strlen(response));
        return;
    }

    // Open the file
    int fd = open(file_path, O_RDONLY);

    // Get the file size
    struct stat file_stat;
    fstat(fd, &file_stat);
    off_t file_size = file_stat.st_size;

    // Construct response
    char header[MAX_SIZE] = {0};
    sprintf(header, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n", file_size);

    // Write the header
    write(client_socket, header, strlen(header));

    // Send file
    char file_buffer[MAX_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, file_buffer, MAX_SIZE)) > 0) {
        write(client_socket, file_buffer, bytes_read);
    }

    // Clean up
    close(fd);
    close(client_socket);
}

int main() {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in address;

    // Create socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addrlen = sizeof(address);
    while ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        handle_request(client_socket);
    }

    return 0;
}
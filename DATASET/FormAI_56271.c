//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Failed to create socket");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Failed to bind socket to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 5) == -1) {
        printf("Failed to listen for incoming connections");
        exit(1);
    }

    // Accept incoming connection
    int client_socket_fd = accept(socket_fd, NULL, NULL);
    if (client_socket_fd == -1) {
        printf("Failed to accept incoming connection");
        exit(1);
    }

    // Read client request
    char request_buffer[1024] = {0};
    int bytes_received = recv(client_socket_fd, request_buffer, sizeof(request_buffer), 0);
    if (bytes_received == -1) {
        printf("Failed to read client request");
        exit(1);
    }

    // Parse request
    char *tokens[3];
    tokens[0] = strtok(request_buffer, " ");
    tokens[1] = strtok(NULL, " ");
    tokens[2] = strtok(NULL, " ");

    // Get requested file path
    char *file_path = tokens[1] + 1; // Remove leading "/"

    // Open requested file
    char *file_content = NULL;
    FILE *file = fopen(file_path, "r");
    if (file) {
        // Read file content
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);
        file_content = malloc(file_size + 1);
        fread(file_content, 1, file_size, file);
        fclose(file);
    }

    // Build and send response
    char response_buffer[1024] = {0};
    if (file_content) {
        sprintf(response_buffer, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n%s", strlen(file_content), file_content);
    } else {
        sprintf(response_buffer, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n");
    }

    if (send(client_socket_fd, response_buffer, strlen(response_buffer), 0) == -1) {
        printf("Failed to send response");
        exit(1);
    }

    // Close sockets
    close(client_socket_fd);
    close(socket_fd);

    return 0;
}
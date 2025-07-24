//FormAI DATASET v1.0 Category: Simple Web Server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAX_REQUEST_LENGTH 1024
#define MAX_URL_LENGTH 256
#define MAX_FILE_LENGTH 4096

void handle_request(int client_sockfd);
void serve_file(int client_sockfd, char *file_path);
void not_found(int client_sockfd);
void send_response(int client_sockfd, char *response_message);
void clean_request(char *request_message);

int main(int argc, char *argv[]) {
    // Create a listening socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "ERROR: Failed to create socket\n");
        exit(1);
    }

    // Prepare the server address and bind the socket
    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "ERROR: Failed to bind server socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) < 0) {
        fprintf(stderr, "ERROR: Failed to listen for incoming connections\n");
        exit(1);
    } else {
        printf("Server is listening on port 8080\n");
    }

    while (true) {
        // Accept an incoming connection
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            fprintf(stderr, "ERROR: Failed to accept incoming connection\n");
            continue;
        }
        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle the client request
        handle_request(client_sockfd);

        // Close the client connection
        close(client_sockfd);
        printf("Closed incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    // Close the server socket
    close(sockfd);
    return 0;
}

void handle_request(int client_sockfd) {
    char request[MAX_REQUEST_LENGTH];
    memset(request, 0, MAX_REQUEST_LENGTH);

    // Read the client request
    int read_len = read(client_sockfd, request, MAX_REQUEST_LENGTH);
    if (read_len <= 0) {
        fprintf(stderr, "ERROR: Failed to read client request\n");
        return;
    }

    // Clean up the request message
    clean_request(request);

    // Parse the request message and extract the requested file name
    char url[MAX_URL_LENGTH];
    memset(url, 0, MAX_URL_LENGTH);
    sscanf(request, "GET %s HTTP/1.1\r\n", url);

    // Serve the requested file if it exists, otherwise return a 404 error
    char file_path[MAX_URL_LENGTH + 2];
    sprintf(file_path, ".%s", url);

    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        not_found(client_sockfd);
    } else {
        serve_file(client_sockfd, file_path);
        close(fd);
    }
}

void serve_file(int client_sockfd, char *file_path) {
    char file_buffer[MAX_FILE_LENGTH];
    memset(file_buffer, 0, MAX_FILE_LENGTH);

    int bytes_read = 0;
    int bytes_sent = 0;

    // Read file to buffer
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        printf("ERROR: Failed to open file at path %s\n", file_path);
        return;
    }

    bytes_read = read(fd, file_buffer, MAX_FILE_LENGTH);

    // Send HTTP response header
    char response_header[1024];
    snprintf(response_header, 1024, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", bytes_read);
    send_response(client_sockfd, response_header);

    // Send file contents
    while (bytes_sent < bytes_read) {
        bytes_sent += write(client_sockfd, &file_buffer[bytes_sent], bytes_read - bytes_sent);
    }
}

void not_found(int client_sockfd) {
    char response_message[1024];
    snprintf(response_message, 1024, "HTTP/1.1 404 NOT FOUND\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>");
    send_response(client_sockfd, response_message);
}

void send_response(int client_sockfd, char *response_message) {
    write(client_sockfd, response_message, strlen(response_message));
}

void clean_request(char *request_message) {
    int i, j;
    for (i = j = 0; request_message[i]; ++i) {
        if (request_message[i] == '\r' && request_message[i+1] == '\n' && request_message[i+2] == '\r' && request_message[i+3] == '\n') {
            request_message[j++] = request_message[i++];
            request_message[j++] = request_message[i++];
            request_message[j++] = request_message[i++];
            request_message[j++] = request_message[i++];
        } else {
            request_message[j++] = request_message[i];
        }
    }
    request_message[j] = '\0';
}
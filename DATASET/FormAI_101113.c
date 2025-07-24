//FormAI DATASET v1.0 Category: Simple Web Server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define WEB_ROOT "./www"

// Function to build the full path of the requested file
void build_path(char *file_path, char *request_path) {
    strcpy(file_path, WEB_ROOT);
    if (strcmp(request_path, "/") == 0) {
        strcat(file_path, "/index.html");
    } else {
        strcat(file_path, request_path);
    }
}

int main() {
    int server_fd, client_fd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // Bind socket to server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, 
                                &client_address_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr),
                                                ntohs(client_address.sin_port));

        // Read request from client
        bzero(buffer, BUFFER_SIZE);
        if (read(client_fd, buffer, BUFFER_SIZE) < 0) {
            perror("Read failed");
            close(client_fd);
            continue;
        }

        printf("Request received from client:\n%s\n", buffer);

        // Parse HTTP GET request
        char *request_path = strtok(buffer, " ");
        char file_path[100];
        build_path(file_path, request_path);
        printf("Requested file: %s\n", file_path);

        // Open requested file
        int file_fd = open(file_path, O_RDONLY);
        if (file_fd < 0) {
            printf("File not found\n");
            close(client_fd);
            continue;
        }

        // Send HTTP response
        char response[BUFFER_SIZE];
        bzero(response, BUFFER_SIZE);
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        send(client_fd, response, strlen(response), 0);

        // Read file contents and send response
        int bytes_read;
        while ((bytes_read = read(file_fd, buffer, BUFFER_SIZE)) > 0) {
            send(client_fd, buffer, bytes_read, 0);
        }
        
        // Close file and client sockets
        close(file_fd);
        close(client_fd);
    }

    return 0;
}
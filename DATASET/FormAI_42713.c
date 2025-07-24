//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {

    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];
    int server_fd, client_fd, file_fd, read_count, file_size;
    char file_path[256];
    char message[1024];
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server started and listening on port %d...\n", SERVER_PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_length);
        if (client_fd < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("Received connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        strcpy(message, "Welcome to the post-apocalyptic world! Enter the file path of the resource you need:");
        send(client_fd, message, strlen(message), 0);

        bzero(buffer, BUFFER_SIZE);
        read_count = read(client_fd, buffer, BUFFER_SIZE);
        if (read_count < 0) {
            perror("Failed to read from incoming connection");
            exit(EXIT_FAILURE);
        }
        
        if (buffer[read_count - 1] == '\n') {
            buffer[read_count-1] = '\0';
        }

        file_fd = open(buffer, O_RDONLY);
        if (file_fd < 0) {
            // File not found
            strcpy(message, "404 - Resource not found");
            send(client_fd, message, strlen(message), 0);
        } else {
            // File found, send it to client
            struct stat file_stat;
            if (fstat(file_fd, &file_stat) < 0) {
                perror("Failed to get file stats");
                exit(EXIT_FAILURE);
            }
            file_size = file_stat.st_size;

            sprintf(message, "HTTP/1.1 200 OK\nContent-Length: %d\nContent-Type: text/html\n\n", file_size);
            send(client_fd, message, strlen(message), 0);

            while ((read_count = read(file_fd, buffer, BUFFER_SIZE)) > 0) {
                write(client_fd, buffer, read_count);
            }
            close(file_fd);
        }

        close(client_fd);
        printf("Connection closed\n");
    }

    return 0;
}
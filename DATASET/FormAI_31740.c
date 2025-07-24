//FormAI DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char const *argv[]) {
    // Create a new socket
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the local address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    // Handle incoming connections
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Failed to accept connection");
            continue;
        }

        // Read request from the client
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        int received_size = read(client_socket, buffer, BUFFER_SIZE - 1);
        if (received_size == -1) {
            perror("Failed to receive data from client");
            close(client_socket);
            continue;
        }

        // Parse request headers
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *protocol = strtok(NULL, "\r\n");
        char *header = strtok(NULL, "\r\n");
        while (header != NULL) {
            printf("%s\n", header);
            header = strtok(NULL, "\r\n");
        }

        // Serve the requested file
        char *filename = path + 1;
        if (strcmp(method, "GET") == 0) {
            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                perror("Failed to open file");
                close(client_socket);
                continue;
            }
            fseek(file, 0, SEEK_END);
            long file_size = ftell(file);
            fseek(file, 0, SEEK_SET);
            char response[BUFFER_SIZE];
            sprintf(response, "%s 200 OK\r\nContent-Length: %ld\r\nConnection: close\r\n\r\n", protocol, file_size);
            write(client_socket, response, strlen(response));
            while (!feof(file)) {
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
                if (bytes_read == -1) {
                    perror("Failed to read file");
                    break;
                }
                write(client_socket, buffer, bytes_read);
            }
            fclose(file);
        } else {
            char *response = "HTTP/1.1 405 Method Not Allowed\r\nConnection: close\r\n\r\n";
            write(client_socket, response, strlen(response));
        }

        // Close the connection
        close(client_socket);
    }

    // Clean up
    close(server_socket);
    return 0;
}
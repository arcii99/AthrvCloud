//FormAI DATASET v1.0 Category: Simple Web Server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

// Function to handle client requests
void handle_request(int client_sock) {
    char buffer[MAX_BUFFER_SIZE] = {0};
    char response[MAX_BUFFER_SIZE] = {0};
    int bytes_received, bytes_sent;

    // Receive client request
    bytes_received = recv(client_sock, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error receiving client request");
        close(client_sock);
        return;
    }

    // Extract requested file name from client request
    char* file_name = strtok(buffer, " ");
    file_name = strtok(NULL, " ");
    printf("Requested file: %s\n", file_name);

    // Check if requested file exists
    struct stat file_stat;
    if (stat(file_name, &file_stat) < 0) {
        printf("File not found\n");
        strcpy(response, "HTTP/1.1 404 Not Found\r\nContent-Length: 15\r\n\r\n404 Not Found");
        bytes_sent = send(client_sock, response, strlen(response), 0);
        close(client_sock);
        return;
    }

    // Open requested file
    FILE* file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        strcpy(response, "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 30\r\n\r\n500 Internal Server Error");
        bytes_sent = send(client_sock, response, strlen(response), 0);
        close(client_sock);
        return;
    }

    // Read contents of file
    char file_content[MAX_BUFFER_SIZE];
    int file_size = 0;
    int bytes_read;
    while ((bytes_read = fread(file_content, 1, MAX_BUFFER_SIZE, file)) > 0) {
        file_size += bytes_read;
        strcat(response, file_content);
    }

    // Send HTTP response header
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", file_size);
    bytes_sent = send(client_sock, response, strlen(response), 0);

    // Send file contents
    bytes_sent = send(client_sock, file_content, file_size, 0);

    // Close file and socket
    fclose(file);
    close(client_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;

    // Create socket for server
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to server address
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_sock, MAX_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
    printf("Server started, listening on port %d\n", SERVER_PORT);

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);

        // Accept client connection
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Error accepting client connection");
            continue;
        }
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client request
        handle_request(client_sock);
    }

    // Close server socket
    close(server_sock);
    return 0;
}
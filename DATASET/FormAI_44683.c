//FormAI DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    read(client_socket, buffer, BUFFER_SIZE);
    
    // Parse the request to extract the file path
    char *request_path = strtok(buffer, " ");
    request_path = strtok(NULL, " ");
    
    // Open the file and read its contents
    FILE *file = fopen(request_path, "r");
    if (file == NULL) {
        // If the file cannot be opened, return a 404 error
        char error_message[] = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\nFile not found";
        write(client_socket, error_message, strlen(error_message));
        return;
    }
    
    char response[BUFFER_SIZE] = {0};
    char *content_type = "Content-Type: text/html";
    sprintf(response, "HTTP/1.1 200 OK\r\n%s\r\n\r\n", content_type);
    
    char file_buffer[BUFFER_SIZE];
    while(fgets(file_buffer, BUFFER_SIZE, file)) {
        strcat(response, file_buffer);
    }
    
    write(client_socket, response, strlen(response));
    fclose(file);
}

int main() {
    int server_socket;
    struct sockaddr_in address;
    
    // Create a socket for the server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Configure the server address and bind it to the socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming requests
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        int client_socket;
        struct sockaddr_in client_address;
        int address_length = sizeof(client_address);
        
        // Wait for a client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Handle the request from the client
        handle_request(client_socket);
        close(client_socket);
    }
    
    return 0;
}
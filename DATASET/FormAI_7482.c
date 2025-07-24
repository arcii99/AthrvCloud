//FormAI DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

void handle_client_request(int client_socket);
void send_http_response(int client_socket, char* response);

int main(int argc, char* argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_size = sizeof(server_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(DEFAULT_PORT);

    // Bind socket to address
    if(bind(server_socket, (struct sockaddr*) &server_address, address_size) == -1) {
        printf("Error binding socket to address\n");
        exit(1);
    }

    // Listen for connections
    if(listen(server_socket, 1) == -1) {
        printf("Error trying to listen for connections\n");
        exit(1);
    }

    printf("Server running on port %d\n", DEFAULT_PORT);

    // Handle incoming connections
    while(true) {
        // Accept connection
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, (socklen_t*) &address_size);
        if(client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        // Handle request
        handle_client_request(client_socket);

        // Close connection
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

void handle_client_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Read request from client
    int bytes_read = read(client_socket, buffer, BUFFER_SIZE-1);
    if(bytes_read < 0) {
        printf("Error reading from socket\n");
        return;
    }

    // Extract request method and path
    char method[10];
    char path[100];
    sscanf(buffer, "%s %s", method, path);

    // Serve file requested by client
    if(strcmp(method, "GET") == 0) {
        FILE* file = fopen(&path[1], "r");
        if(file == NULL) {
            char* error_response = "HTTP/1.1 404 NOT FOUND\nContent-Type: text/plain\n\nError: File not found\n";
            send_http_response(client_socket, error_response);
        }
        else {
            // Read file contents and send to client
            char file_buffer[1024];
            memset(file_buffer, 0, 1024);

            int file_size;
            fseek(file, 0, SEEK_END);
            file_size = ftell(file);
            fseek(file, 0, SEEK_SET);

            char* success_response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\n";
            send_http_response(client_socket, success_response);

            while((bytes_read = fread(file_buffer, 1, 1024, file)) > 0) {
                write(client_socket, file_buffer, bytes_read);
            }

            fclose(file);
        }
    }
    else {
        char* error_response = "HTTP/1.1 501 NOT IMPLEMENTED\nContent-Type: text/plain\n\nError: Method not implemented\n";
        send_http_response(client_socket, error_response); 
    }
}

void send_http_response(int client_socket, char* response) {
    write(client_socket, response, strlen(response));
}
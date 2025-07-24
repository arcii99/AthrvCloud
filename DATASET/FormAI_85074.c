//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024

void send_response(int client_socket, const char* response) {
    char header[256];
    sprintf(header, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nServer: Futuristic Web Server\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n", strlen(response));
    write(client_socket, header, strlen(header));
    write(client_socket, response, strlen(response));
}

void handle_request(int client_socket, const char* request) {
    char method[16], path[128], protocol[16];
    sscanf(request, "%s %s %s", method, path, protocol);
    
    // Only process GET requests
    if (strcmp(method, "GET") != 0) {
        const char* response = "<html><body><h1>405 Method Not Allowed</h1></body></html>";
        send_response(client_socket, response);
        return;
    }

    // Check if path is a CGI script
    char* ext = strrchr(path, '.');
    if (ext != NULL && strcmp(ext, ".cgi") == 0) {
        // Execute CGI script and send response
        char cmd[256];
        sprintf(cmd, "./www%s", path);
        FILE* fp = popen(cmd, "r");
        if (fp == NULL) {
            const char* response = "<html><body><h1>500 Internal Server Error</h1></body></html>";
            send_response(client_socket, response);
            return;
        }
        char response[MAX_REQUEST_SIZE];
        fgets(response, MAX_REQUEST_SIZE, fp);
        send_response(client_socket, response);
        pclose(fp);
    } else {
        // Serve static file
        char filepath[256];
        sprintf(filepath, "./www%s", path);
        FILE* fp = fopen(filepath, "r");
        if (fp == NULL) {
            const char* response = "<html><body><h1>404 Not Found</h1></body></html>";
            send_response(client_socket, response);
            return;
        }
        char response[MAX_REQUEST_SIZE];
        fgets(response, MAX_REQUEST_SIZE, fp);
        send_response(client_socket, response);
        fclose(fp);
    }
}

int main(int argc, char** argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }

    printf("Futuristic Web Server running on port %d...\n", PORT);

    // Accept incoming connections
    int client_address_len = sizeof(client_address);
    while ((client_socket = accept(server_socket, (struct sockaddr*) &client_address, (socklen_t*) &client_address_len))) {
        char request[MAX_REQUEST_SIZE];
        read(client_socket, request, MAX_REQUEST_SIZE);
        handle_request(client_socket, request);
        close(client_socket);
    }

    // Cleanup
    close(server_socket);

    return 0;
}
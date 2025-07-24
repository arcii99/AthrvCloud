//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define PROXY_PORT 8000
#define SERVER_PORT 80

void handle_client_connection(int client_socket) {
    // Read the client request
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    int bytes_read = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        perror("Error reading client request");
        return;
    }
    
    // Extract the hostname and path from the request
    char hostname[MAX_BUFFER_SIZE];
    memset(hostname, 0, MAX_BUFFER_SIZE);
    int hostname_start = strstr(buffer, "Host: ") - buffer + 6;
    int hostname_end = strstr(buffer + hostname_start, "\r\n") - buffer;
    strncpy(hostname, buffer + hostname_start, hostname_end - hostname_start);
    char path[MAX_BUFFER_SIZE];
    memset(path, 0, MAX_BUFFER_SIZE);
    strncpy(path, strstr(buffer, " ") + 1, strstr(strstr(buffer, " "), " ") - strstr(buffer, " ") - 1);
    
    // Connect to the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        return;
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    struct in_addr in_addr;
    inet_aton(hostname, &in_addr);
    server_address.sin_addr = in_addr;
    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return;
    }
    
    // Forward the request to the server
    if (send(server_socket, buffer, bytes_read, 0) < 0) {
        perror("Error forwarding request to server");
        return;
    }
    
    // Read the server response
    memset(buffer, 0, MAX_BUFFER_SIZE);
    bytes_read = recv(server_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        perror("Error reading server response");
        return;
    }
    
    // Forward the response to the client
    if (send(client_socket, buffer, bytes_read, 0) < 0) {
        perror("Error forwarding response to client");
        return;
    }
    
    close(server_socket);
}

int main(int argc, char **argv) {
    // Create the proxy listener socket
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating proxy socket");
        return 1;
    }
    struct sockaddr_in proxy_address;
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_port = htons(PROXY_PORT);
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(proxy_socket, (struct sockaddr *) &proxy_address, sizeof(proxy_address)) < 0) {
        perror("Error binding proxy socket");
        return 1;
    }
    if (listen(proxy_socket, 10) < 0) {
        perror("Error listening on proxy socket");
        return 1;
    }
    printf("Proxy listening on port %d...\n", PROXY_PORT);
    
    // Accept and handle incoming connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(proxy_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }
        handle_client_connection(client_socket);
        close(client_socket);
    }
    
    close(proxy_socket);
    return 0;
}
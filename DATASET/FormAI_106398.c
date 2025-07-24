//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PROXY_PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0); // Create a socket for the proxy
    if (proxy_socket == -1) {
        perror("Could not create proxy socket");
        exit(EXIT_FAILURE);
    }

    // Bind the proxy to the specified port
    struct sockaddr_in proxy_address;
    memset(&proxy_address, 0, sizeof(proxy_address)); // Clear address structure
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(PROXY_PORT);
    if (bind(proxy_socket, (struct sockaddr *) &proxy_address, sizeof(proxy_address)) == -1) {
        perror("Could not bind proxy socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, SOMAXCONN) == -1) {
        perror("Could not listen for connections");
        exit(EXIT_FAILURE);
    }

    while (1) { // Loop to handle incoming connections
        int client_socket = accept(proxy_socket, NULL, NULL); // Accept incoming connection
        if (client_socket == -1) {
            perror("Could not accept incoming connection");
            continue;
        }

        printf("Incoming connection accepted\n");

        char buffer[MAX_BUFFER_SIZE];

        // Read the request from the client
        ssize_t bytes_read = read(client_socket, buffer, MAX_BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("Could not read request from client");
            close(client_socket);
            continue;
        }

        printf("Received request from client:\n%s\n", buffer);

        // Open a new socket to connect to the server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1) {
            perror("Could not create server socket");
            close(client_socket);
            continue;
        }

        // Parse the host and port from the request
        char *host = NULL;
        char *port = NULL;
        char *http_start = strstr(buffer, "http://");
        if (http_start != NULL) {
            host = http_start + strlen("http://"); // Skip "http://"
            char *path_start = strchr(host, '/');
            if (path_start != NULL) {
                *path_start = '\0'; // Terminate host string
                port = strchr(host, ':');
                if (port != NULL) {
                    *port = '\0'; // Terminate port string
                    port++;
                } else {
                    port = "80"; // Default port for HTTP
                }
                path_start++; // Skip '/'
            }
        }

        // Connect to the server
        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address)); // Clear address structure
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(atoi(port));
        if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0) {
            perror("Could not convert server address");
            close(client_socket);
            close(server_socket);
            continue;
        }
        if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
            perror("Could not connect to server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Connected to server %s:%s\n", host, port);

        // Forward the request to the server
        if (write(server_socket, buffer, bytes_read) == -1) {
            perror("Could not forward request to server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Request forwarded to server:\n%s\n", buffer);

        // Read the response from the server
        while ((bytes_read = read(server_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
            // Forward the response to the client
            if (write(client_socket, buffer, bytes_read) == -1) {
                perror("Could not forward response to client");
                close(client_socket);
                close(server_socket);
                break;
            }
        }

        close(client_socket);
        close(server_socket);
    }

    return 0;
}
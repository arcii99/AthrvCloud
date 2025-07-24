//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;

    // Create the proxy socket
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Proxy socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the proxy socket to a port
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(8080);

    if (bind(proxy_socket, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Binding socket to port failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 10) < 0) {
        perror("Proxy socket listen failed");
        exit(EXIT_FAILURE);
    }

    printf("C Simple HTTP Proxy is now running on port 8080\n");

    // Wait for client connections
    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_socket = accept(proxy_socket, (struct sockaddr *) &client_addr, &client_addr_len);

        if (client_socket < 0) {
            perror("Client socket creation failed");
            continue;
        }

        // Read request from client
        char request[1024];
        memset(request, 0, 1024);
        int bytes_received = recv(client_socket, request, 1024, 0);

        if (bytes_received < 0) {
            perror("Error while receiving request");
            close(client_socket);
            continue;
        }

        printf("Received request from client:\n%s\n", request);

        // Get the destination server address from the request
        char *server_host = strtok(request, " ");
        server_host = strtok(NULL, " ");
        server_host = strtok(server_host, "/");
        server_host = strtok(NULL, "/");
        server_host = strtok(server_host, ":");
        server_host = strtok(NULL, "\r\n");
        printf("Request is being forwarded to server %s\n", server_host);

        // Connect to the destination server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        inet_aton(server_host, &server_addr.sin_addr);

        if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            perror("Could not connect to server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        // Forward the request to the server
        if (send(server_socket, request, strlen(request), 0) < 0) {
            perror("Error while forwarding request");
            close(client_socket);
            close(server_socket);
            continue;
        }

        // Read response from server and forward it to the client
        char response[1024];
        memset(response, 0, 1024);
        bytes_received = recv(server_socket, response, 1024, 0);

        if (bytes_received < 0) {
            perror("Error while receiving response");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Received response from server:\n%s\n", response);

        // Forward response to client
        if (send(client_socket, response, strlen(response), 0) < 0) {
            perror("Error while forwarding response");
            close(client_socket);
            close(server_socket);
            continue;
        }

        // Close client and server sockets
        close(client_socket);
        close(server_socket);
    }

    return 0;
}
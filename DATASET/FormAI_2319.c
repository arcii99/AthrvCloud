//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096
#define PORT 8080

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];

    // Create server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    // Accept incoming connections and serve each request
    while(1) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);

        if (client_sock == -1) {
            perror("Error accepting connection");
            continue;
        }

        // Receive request from client
        memset(buf, 0, BUF_SIZE);
        int bytes_received = recv(client_sock, buf, BUF_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error receiving request");
            close(client_sock);
            continue;
        }

        // Parse request headers to get host and port
        char *host = strstr(buf, "Host: ");
        if (host == NULL) {
            host = "localhost";
        } else {
            host += strlen("Host: ");
            char *end = strstr(host, "\r\n");
            if (end != NULL) {
                *end = '\0';
            }
        }
        int port = 80;
        char *port_str = strstr(host, ":");
        if (port_str != NULL) {
            port_str += 1;
            port = atoi(port_str);
            *port_str = '\0';
        }

        // Create remote socket
        int remote_sock;
        struct sockaddr_in remote_addr;
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(host);
        remote_addr.sin_port = htons(port);
        if ((remote_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Error creating remote socket");
            close(client_sock);
            continue;
        }

        // Connect to remote server
        if (connect(remote_sock, (struct sockaddr *) &remote_addr, sizeof(remote_addr)) == -1) {
            perror("Error connecting to remote server");
            close(client_sock);
            close(remote_sock);
            continue;
        }

        // Forward request to remote server
        if (send(remote_sock, buf, bytes_received, 0) == -1) {
            perror("Error forwarding request to remote server");
            close(client_sock);
            close(remote_sock);
            continue;
        }

        // Receive response from remote server and forward to client
        while(1) {
            memset(buf, 0, BUF_SIZE);
            int bytes_received = recv(remote_sock, buf, BUF_SIZE, 0);
            if (bytes_received == -1) {
                perror("Error receiving response from remote server");
                close(client_sock);
                close(remote_sock);
                continue;
            } else if (bytes_received == 0) {
                break;
            }
            if (send(client_sock, buf, bytes_received, 0) == -1) {
                perror("Error forwarding response to client");
                close(client_sock);
                close(remote_sock);
                continue;
            }
        }

        // Close sockets
        close(client_sock);
        close(remote_sock);
    }

    return 0;
}
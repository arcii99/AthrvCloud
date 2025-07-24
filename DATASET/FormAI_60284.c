//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10

void handle_client(int sock);

int main(int argc, char const *argv[]) {
    int server_sock, client_sock, err;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(server_addr);
    int yes = 1;

    // Creating socket file descriptor
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    memset(&server_addr, 0, addrlen);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, addrlen) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
        if (client_sock == -1) {
            perror("Failed to accept connection");
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client connection
        handle_client(client_sock);
    }

    // Close server socket
    close(server_sock);

    return 0;
}

void handle_client(int sock) {
    char buffer[BUFSIZ];
    ssize_t bytes_received;
    int send_status;

    // Receive data from client
    bytes_received = recv(sock, buffer, BUFSIZ, 0);
    if (bytes_received == -1) {
        perror("Failed to receive data from client");
        close(sock);
        return;
    }

    printf("Received data from client: %s", buffer);

    // Send data back to client
    send_status = send(sock, buffer, bytes_received, 0);
    if (send_status == -1) {
        perror("Failed to send data back to client");
        close(sock);
        return;
    }

    // Close client socket
    close(sock);

    return;
}
//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8000

void handle_connection(int conn_socket);

int main() {
    int server_socket, conn_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to server address");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server listening on %s:%d\n", SERVER_IP, SERVER_PORT);

    while (1) {
        // Accept incoming connection
        conn_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (conn_socket < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle connection
        handle_connection(conn_socket);

        // Close connection
        close(conn_socket);
        printf("Connection closed\n");
    }

    // Close server socket
    close(server_socket);
    printf("Server shut down\n");

    return 0;
}

void handle_connection(int conn_socket) {
    char buffer[BUFFER_SIZE];
    int num_bytes_recv, num_bytes_sent;

    // Receive data from client
    num_bytes_recv = recv(conn_socket, buffer, BUFFER_SIZE, 0);
    if (num_bytes_recv < 0) {
        perror("Error receiving data from client");
        exit(1);
    }

    printf("Received data from client: %s\n", buffer);

    // Modify received data
    strcat(buffer, " modified");

    // Send modified data to client
    num_bytes_sent = send(conn_socket, buffer, strlen(buffer), 0);
    if (num_bytes_sent < 0) {
        perror("Error sending data to client");
        exit(1);
    }

    printf("Sent modified data to client: %s\n", buffer);
}
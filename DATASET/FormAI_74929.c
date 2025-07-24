//FormAI DATASET v1.0 Category: Socket programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char** argv) {

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket.\n");
        return -1;
    }

    // Bind the socket to a specific address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket.\n");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        printf("Failed to listen on socket.\n");
        return -1;
    }

    // Accept incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
    if (client_socket == -1) {
        printf("Failed to accept connection.\n");
        return -1;
    }

    // Read data from client
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    if (read(client_socket, buf, sizeof(buf)) == -1) {
        printf("Failed to read from client.\n");
        return -1;
    }

    // Print data received from client
    printf("Received data from client: %s\n", buf);

    // Send response back to client
    char* response = "Hello, client!";
    if (write(client_socket, response, strlen(response)) == -1) {
        printf("Failed to send response to client.\n");
        return -1;
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
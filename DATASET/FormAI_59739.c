//FormAI DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sock_fd, client_fd, port_no, read_size;
    struct sockaddr_in server_addr, client_addr;
    char message[2000], client_response[2000];

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error("Error: creating socket");
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind socket to address
    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Error: binding socket to address");
    }

    // Listen for connections
    if (listen(sock_fd, 3) < 0) {
        error("Error: listening for connections");
    }

    // Accept incoming connections
    int client_len = sizeof(client_addr);
    client_fd = accept(sock_fd, (struct sockaddr*)&client_addr, (socklen_t*)&client_len);
    if (client_fd < 0) {
        error("Error: accepting connection");
    }

    // Receive messages from client
    while (recv(client_fd, &client_response, sizeof(client_response), 0) > 0) {
        printf("Client Says : %s\n", client_response);

        // Send message to client
        printf("Reply To Client : ");
        fgets(message, 2000, stdin);
        write(client_fd, message, strlen(message));
    }

    // Close connections
    close(client_fd);
    close(sock_fd);

    return 0;
}
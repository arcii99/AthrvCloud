//FormAI DATASET v1.0 Category: Chat server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from the other side!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }

    // Set socket options to reuse address
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("setsockopt");
    }

    // Set up the sockaddr_in structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("bind failed");
    }

    // Listen for incoming connections with queue size 3
    if (listen(server_fd, 3) < 0) {
        error("listen");
    }

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        error("accept");
    }

    // Send welcome message to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Server is running on port %d...\n", PORT);

    // Continuously handle client messages
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        // Read client message from socket
        valread = read(new_socket, buffer, 1024);
        if (valread < 0) {
            error("read error");
        }
        // Print client message to server console
        printf("Client: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
        // Get server's message to client from standard input
        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        // Send server's message to client
        send(new_socket, buffer, strlen(buffer), 0);
    }
    return 0;
}
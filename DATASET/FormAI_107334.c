//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void handle_client(int server_socket) {
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to the TCP/IP server!\n";
    send(server_socket, welcome_message, strlen(welcome_message), 0);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(server_socket, buffer, sizeof(buffer));
        printf("Client message: %s", buffer);

        if (strncmp(buffer, "quit", 4) == 0) {
            char *goodbye_message = "Goodbye!\n";
            send(server_socket, goodbye_message, strlen(goodbye_message), 0);
            break;
        }

        char *response_message = "I received your message!\n";
        send(server_socket, response_message, strlen(response_message), 0);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);

    // Create socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address
    int option = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, addrlen) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("TCP/IP server listening on port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        char *client_ip = inet_ntoa(client_address.sin_addr);
        printf("Accepted connection from client IP %s\n", client_ip);

        // Handle client messages
        handle_client(client_socket);

        // Close socket connection
        close(client_socket);
        printf("Closed connection from client IP %s\n", client_ip);
    }

    return 0;
}
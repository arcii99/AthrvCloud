//FormAI DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} client_t;

int main(int argc, char *argv[]) {
    int server_fd, new_socket, client_count = 0;
    struct sockaddr_in server_address, client_address;
    client_t clients[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind server to address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    // Loop to accept clients and handle messages
    while (1) {
        // Accept new connection
        int address_length = sizeof(client_address);
        new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&address_length);
        if (new_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        // Check if maximum number of clients has been reached
        if (client_count >= MAX_CLIENTS) {
            printf("Maximum number of clients reached, closing new connection\n");
            close(new_socket);
            continue;
        }

        // Add new client to list
        clients[client_count].socket_fd = new_socket;
        clients[client_count].address = client_address;
        client_count++;
        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Send welcome message to new client
        char welcome_message[BUFFER_SIZE];
        sprintf(welcome_message, "Welcome to the chat server! %d other clients are currently online.\n", client_count - 1);
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Loop to handle client messages
        while (1) {
            // Receive message from client
            int read_size = recv(new_socket, buffer, BUFFER_SIZE, 0);
            if (read_size <= 0) {
                // Client disconnected
                printf("%s:%d disconnected\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

                // Remove client from list
                for (int i = 0; i < client_count; i++) {
                    if (clients[i].socket_fd == new_socket) {
                        clients[i] = clients[client_count - 1];
                        client_count--;
                        break;
                    }
                }

                // Close socket and break inner loop
                close(new_socket);
                break;
            }

            // Broadcast message to all clients
            for (int i = 0; i < client_count; i++) {
                if (clients[i].socket_fd != new_socket) {
                    send(clients[i].socket_fd, buffer, read_size, 0);
                }
            }
        }
    }

    // Close server socket and exit
    close(server_fd);
    return 0;
}
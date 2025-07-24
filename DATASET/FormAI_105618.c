//FormAI DATASET v1.0 Category: Chat server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main(int argc, char const *argv[]) {

    // Create a server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("Failed to bind socket to address\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        printf("Failed to start listening for incoming connections\n");
        return 1;
    }

    printf("Chat server started on port %d\n", PORT);

    int client_sockets[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = -1;
    }

    // Wait for clients to connect
    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);

        // Add the server socket to the file descriptor set
        FD_SET(server_fd, &read_fds);

        int max_fd = server_fd;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != -1) {
                FD_SET(client_sockets[i], &read_fds);
                max_fd = (client_sockets[i] > max_fd) ? client_sockets[i] : max_fd;
            }
        }

        // Wait for activity on any of the file descriptors
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            printf("Error in select()\n");
            return 1;
        }

        // Check for incoming client connections
        if (FD_ISSET(server_fd, &read_fds)) {
            int new_client = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&address);

            char welcome_message[] = "Welcome to the chat server!\n";
            send(new_client, welcome_message, strlen(welcome_message), 0);

            printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == -1) {
                    client_sockets[i] = new_client;
                    break;
                }
            }
        }

        // Check for client messages
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != -1 && FD_ISSET(client_sockets[i], &read_fds)) {
                char message[1024];
                int bytes_received = recv(client_sockets[i], message, 1024, 0);

                // Client has disconnected
                if (bytes_received == 0) {
                    printf("Client disconnected: %d\n", client_sockets[i]);
                    close(client_sockets[i]);
                    client_sockets[i] = -1;
                }
                else {
                    // Broadcast client message to all connected clients
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (client_sockets[j] != -1 && client_sockets[j] != client_sockets[i]) {
                            send(client_sockets[j], message, bytes_received, 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
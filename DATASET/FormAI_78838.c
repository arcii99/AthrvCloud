//FormAI DATASET v1.0 Category: Client Server Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_error(char* error_message) {
    perror(error_message);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, client_fd, max_clients = MAX_CLIENTS, activity, received_bytes;
    struct sockaddr_in server_address, client_address;
    int clients[MAX_CLIENTS];
    char buffer[BUFFER_SIZE] = {0};
    fd_set readfds;

    // Create server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("Failed to create socket file descriptor");
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        handle_error("Failed to set socket options");
    }

    // Bind server socket to address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        handle_error("Failed to bind server socket to address and port");
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        handle_error("Failed to start listening for incoming connections");
    }

    // Accept incoming connections
    socklen_t client_address_size = sizeof(client_address);
    printf("Waiting for incoming connections...\n");

    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i] = 0;
    }

    while (1) {
        // Clear the socket set
        FD_ZERO(&readfds);

        // Add server socket to the socket set
        FD_SET(server_fd, &readfds);

        // Add active client sockets to the socket set
        int max_sd = server_fd;
        for (int i = 0; i < max_clients; i++) {
            int sd = clients[i];
            if (sd > 0) {
                FD_SET(sd, &readfds);
            }

            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        // Wait for new activity on any of the sockets
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            handle_error("Failed to select socket");
        }

        // Check if there is new incoming connection requests
        if (FD_ISSET(server_fd, &readfds)) {
            if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_size)) < 0) {
                handle_error("Failed to accept incoming connection");
            }

            printf("New connection established from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            
            // Add new client socket to clients array
            for (int i = 0; i < max_clients; i++) {
                if (clients[i] == 0) {
                    clients[i] = client_fd;
                    printf("Added new client to clients array at index %d\n", i);
                    break;
                }
            }
        }

        // Handle incoming messages from active clients
        for (int i = 0; i < max_clients; i++) {
            int sd = clients[i];

            if (FD_ISSET(sd, &readfds)) {
                received_bytes = read(sd, buffer, BUFFER_SIZE);
                if (received_bytes == 0) {
                    // Client disconnected
                    printf("Client %d disconnected\n", i);
                    close(sd);
                    clients[i] = 0;
                } else {
                    // Send message to other clients
                    for (int j = 0; j < max_clients; j++) {
                        int other_sd = clients[j];
                        if (other_sd != sd && other_sd != 0) {
                            send(other_sd, buffer, received_bytes, 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
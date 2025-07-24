//FormAI DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 5555
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd, max_fd, activity, valread;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    fd_set read_fds;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error binding socket to port");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Error starting to listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    // Initialize client socket list
    int client_sockets[MAX_CLIENTS] = {0};
    int num_clients = 0;

    // Set up select functionality for handling multiple clients
    FD_ZERO(&read_fds);
    FD_SET(server_fd, &read_fds);
    max_fd = server_fd;

    while (1) {
        // Wait for activity on any of the sockets
        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Error with select");
            exit(EXIT_FAILURE);
        }

        // Check if there is a new incoming connection
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((client_fd = accept(server_fd, NULL, NULL)) < 0) {
                perror("Error accepting connection");
                exit(EXIT_FAILURE);
            }

            // Add new client to list
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = client_fd;
                    num_clients++;
                    break;
                }
            }

            // Add new client socket to select list
            FD_SET(client_fd, &read_fds);
            if (client_fd > max_fd) max_fd = client_fd;

            printf("New connection established.\n");
        }

        // Check if there is activity on any of the client sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];

            if (FD_ISSET(sd, &read_fds)) {
                valread = read(sd, buffer, BUFFER_SIZE);

                if (valread == 0) {
                    // Client has disconnected, remove from list
                    close(sd);
                    client_sockets[i] = 0;
                    num_clients--;

                    // Remove client socket from select list
                    FD_CLR(sd, &read_fds);

                    printf("Client disconnected.\n");
                } else {
                    // Broadcast message to all clients except sender
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        int fd = client_sockets[j];

                        if (fd != server_fd && fd != sd && fd != 0) {
                            send(fd, buffer, valread, 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
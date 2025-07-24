//FormAI DATASET v1.0 Category: Chat server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MESSAGE_BUFFER_SIZE 1024

int main() {
    int server_socket_fd, new_socket_fd, client_sockets_fd[MAX_CLIENTS], activity, max_sd, i, valread;
    struct sockaddr_in address;
    fd_set readfds;
    char buffer[MESSAGE_BUFFER_SIZE] = {0};
    char* message = "Hello from server";

    // Create server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket configurations (bind and listen)
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket_fd, (struct sockaddr*) &address, sizeof(address)) < 0 ) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Set all client sockets to 0
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockets_fd[i] = 0;
    }

    // Accept incoming client connections
    puts("Waiting for connections...");
    while (1) {
        // Clear file descriptor set
        FD_ZERO(&readfds);

        // Add server socket to FD set
        FD_SET(server_socket_fd, &readfds);

        max_sd = server_socket_fd;

        // Add valid client sockets to FD set
        for (i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets_fd[i];

            if (sd > 0) {
                FD_SET(sd, &readfds);
            }

            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        // Wait for activity on any of the sockets
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            printf("select error");
            exit(EXIT_FAILURE);
        }

        // Check if there is activity on server socket (incoming client connection)
        if (FD_ISSET(server_socket_fd, &readfds)) {
            if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr*) &address, (socklen_t*) &address)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            puts("New connection accepted");

            // Add new socket to client sockets array
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets_fd[i] == 0) {
                    client_sockets_fd[i] = new_socket_fd;
                    break;
                }
            }
        }

        // Check if there is activity on any of the client sockets (incoming message)
        for (i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets_fd[i];

            if (FD_ISSET(sd, &readfds)) {
                // Read incoming message
                valread = read(sd, buffer, MESSAGE_BUFFER_SIZE);

                if (valread == 0) {
                    // Client disconnected
                    printf("Client %d disconnected\n", sd);
                    close(sd);
                    client_sockets_fd[i] = 0;
                } else {
                    // Send message to all connected clients
                    for (i = 0; i < MAX_CLIENTS; i++) {
                        int client_sd = client_sockets_fd[i];

                        if (client_sd != 0 && client_sd != sd) {
                            send(client_sd, buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
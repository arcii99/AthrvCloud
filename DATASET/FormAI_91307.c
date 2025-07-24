//FormAI DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket_fd, new_socket_fd, client_socket_fds[MAX_CONNECTIONS], i;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    fd_set read_fds;

    // Create a new server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket to reuse the address and port immediately after use
    int opt_value = 1;
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_value, sizeof(opt_value))) {
        perror("Socket option setting failed");
        exit(EXIT_FAILURE);
    }

    // Set the server socket address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the designated address and port
    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the server socket for incoming connections
    if (listen(server_socket_fd, MAX_CONNECTIONS) < 0) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }

    // Set all client socket file descriptors to 0 (not connected)
    for (i = 0; i < MAX_CONNECTIONS; i++) {
        client_socket_fds[i] = 0;
    }

    // Loop continuously to accept incoming connections and handle client communication
    while (true) {
        // Set the file descriptors to read on to include the server socket and any connected client sockets
        FD_ZERO(&read_fds);
        FD_SET(server_socket_fd, &read_fds);
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (client_socket_fds[i] > 0) {
                FD_SET(client_socket_fds[i], &read_fds);
            }
        }

        // Block until there is data available to read on one of the file descriptors
        int max_fd = 0;
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (client_socket_fds[i] > max_fd) {
                max_fd = client_socket_fds[i];
            }
        }
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Socket select failed");
            exit(EXIT_FAILURE);
        }

        // If the server socket has new data to read, accept the connection and add the new client socket to the list
        if (FD_ISSET(server_socket_fd, &read_fds)) {
            int client_socket_fd_size = sizeof(client_address);
            if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, (socklen_t *) &client_socket_fd_size)) < 0) {
                perror("Socket accept failed");
                exit(EXIT_FAILURE);
            }

            // Add the new client socket to the list
            for (i = 0; i < MAX_CONNECTIONS; i++) {
                if (client_socket_fds[i] == 0) {
                    client_socket_fds[i] = new_socket_fd;
                    break;
                }
            }
        }

        // Loop through all connected client sockets to handle their communication
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            int client_socket_fd = client_socket_fds[i];
            if (FD_ISSET(client_socket_fd, &read_fds)) {
                // Read data from the client socket
                int read_size = read(client_socket_fd, buffer, BUFFER_SIZE);
                if (read_size == 0) {
                    // If the read size is 0, the client has disconnected; remove it from the list
                    close(client_socket_fd);
                    client_socket_fds[i] = 0;
                } else if (read_size < 0) {
                    perror("Socket read failed");
                } else {
                    // Process the input from the client and respond accordingly
                    if (strncmp(buffer, "firewall", 8) == 0) {
                        send(client_socket_fd, "Access denied\n", 15, 0);
                    } else {
                        send(client_socket_fd, "Access granted\n", 16, 0);
                    }
                }
            }
        }
    }

    return 0;
}
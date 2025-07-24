//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MESSAGE_LEN 256

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, client_sockets[MAX_CLIENTS], max_sockets = MAX_CLIENTS, i, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MESSAGE_LEN] = {0};
    char welcome_message[] = "Welcome to the chatroom! Enter your username: ";
    fd_set read_fds;

    // Creating server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Initialize client sockets to 0
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    // Accept incoming connections and add them to the list of client sockets
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] > 0) {
                FD_SET(client_sockets[i], &read_fds);
                if (client_sockets[i] > max_sockets) {
                    max_sockets = client_sockets[i];
                }
            }
        }

        if (select(max_sockets + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select error");
            exit(EXIT_FAILURE);
        }

        // Check if there is a new incoming connection
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept error");
                exit(EXIT_FAILURE);
            }

            // Add the new socket to the list of client sockets
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    break;
                }
            }

            // Send welcome message to the new client
            if (send(new_socket, welcome_message, strlen(welcome_message), 0) != strlen(welcome_message)) {
                perror("send error");
            }
        }

        // Check if there is data to be read from any client socket
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                memset(buffer, 0, sizeof(buffer));
                if ((valread = read(client_sockets[i], buffer, MAX_MESSAGE_LEN)) <= 0) {
                    // Client disconnected, remove from list of client sockets
                    close(client_sockets[i]);
                    client_sockets[i] = 0;
                } else {
                    printf("Client %d: %s\n", client_sockets[i], buffer);
                    // Broadcast message to all other connected clients
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (client_sockets[j] != 0 && client_sockets[j] != client_sockets[i]) {
                            send(client_sockets[j], buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
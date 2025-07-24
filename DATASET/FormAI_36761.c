//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

struct client {
    int socket_fd;
    struct sockaddr_in address;
};

struct client clients[MAX_CONNECTIONS];
int num_clients = 0;

int setup_socket() {
    int server_fd;
    struct sockaddr_in address;

    // Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    memset(address.sin_zero, '\0', sizeof(address.sin_zero));

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

void send_message(char *message, int sender_fd) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket_fd != sender_fd) {
            write(clients[i].socket_fd, message, strlen(message));
        }
    }
}

int main() {
    int server_fd = setup_socket();
    int max_fd = server_fd;
    fd_set readfds;

    while (1) {
        // Set up the file descriptor set
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        for (int i = 0; i < num_clients; i++) {
            FD_SET(clients[i].socket_fd, &readfds);
            if (clients[i].socket_fd > max_fd) {
                max_fd = clients[i].socket_fd;
            }
        }

        // Wait for activity on the sockets
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // Check for activity on the server socket
        if (FD_ISSET(server_fd, &readfds)) {
            struct sockaddr_in client_address;
            int addrlen = sizeof(client_address);
            int client_fd;
            if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            // Add the new client to the list
            struct client new_client = {.socket_fd = client_fd, .address = client_address};
            clients[num_clients] = new_client;
            num_clients++;
        }

        // Check for activity on the client sockets
        for (int i = 0; i < num_clients; i++) {
            if (FD_ISSET(clients[i].socket_fd, &readfds)) {
                char buffer[1024] = {0};
                int bytes_read;
                if ((bytes_read = read(clients[i].socket_fd, buffer, 1024)) == 0) {
                    // Client disconnected
                    close(clients[i].socket_fd);
                    memmove(&clients[i], &clients[i+1], (num_clients - i - 1) * sizeof(struct client));
                    num_clients--;
                } else {
                    // Forward the message to other clients
                    send_message(buffer, clients[i].socket_fd);
                }
            }
        }
    }

    return 0;
}
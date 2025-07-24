//FormAI DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the PORT 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    fd_set readfds;
    int max_clients = MAX_CLIENTS;
    int client_sockets[max_clients];

    for (int i = 0; i < max_clients; ++i) {
        client_sockets[i] = 0;
    }

    while (1) {
        // Clear the set
        FD_ZERO(&readfds);

        // Add server socket to the set
        FD_SET(server_fd, &readfds);

        // Add child sockets to the set
        int max_sd = server_fd;
        for (int i = 0; i < max_clients; ++i) {
            // Socket descriptor
            int client_socket = client_sockets[i];

            // If valid socket descriptor then add to read list
            if (client_socket > 0) {
                FD_SET(client_socket, &readfds);
            }

            // Highest file descriptor number, need it for select function
            if (client_socket > max_sd) {
                max_sd = client_socket;
            }
        }

        // Wait for an activity on one of the sockets
        int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // If something happened on the server socket, then it's a new connection
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                     (socklen_t *)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            // Add new socket to array of sockets
            for (int i = 0; i < max_clients; ++i) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    break;
                }
            }
        }

        // Else it's some IO operation on some other socket
        for (int i = 0; i < max_clients; ++i) {
            int client_socket = client_sockets[i];

            if (FD_ISSET(client_socket, &readfds)) {
                char buffer[1024] = {0};
                valread = read(client_socket, buffer, 1024);

                if (valread == 0) { // Disconnect event
                    close(client_socket);
                    client_sockets[i] = 0;
                } else {
                    // Send message back to client
                    send(client_socket, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}
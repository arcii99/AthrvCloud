//FormAI DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int master_socket, new_socket, activity, addrlen, max_clients = 10, i, valread, sd;
    struct sockaddr_in address;
    char message[1025];
    
    fd_set readfds;
    
    char *welcome_message = "Welcome to the brave chat server!\r\n";

    // Create the master socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow multiple connections
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&valread, sizeof(valread)) < 0) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set socket address and bind the socket to it
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on %d\n", PORT);

    // Listen for connections and limit to max_clients
    if (listen(master_socket, max_clients) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    addrlen = sizeof(address);

    // Array to hold client sockets
    int client_sockets[max_clients];

    // Set all client sockets to 0
    for (i = 0; i < max_clients; i++) {
        client_sockets[i] = 0;
    }

    while (1) {
        // Clear the socket set
        FD_ZERO(&readfds);

        // Add master socket to set
        FD_SET(master_socket, &readfds);

        // Add all client sockets to set
        for (i = 0; i < max_clients; i++) {
            sd = client_sockets[i];

            if (sd > 0) {
                FD_SET(sd, &readfds);
            }
        }

        // Wait for activity on one of the sockets
        activity = select(max_clients + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        // If activity on master socket, there is a new connection
        if (FD_ISSET(master_socket, &readfds)) {
            if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Send welcome message to new client
            send(new_socket, welcome_message, strlen(welcome_message), 0);

            printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // Add new socket to array of client sockets
            for (i = 0; i < max_clients; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    break;
                }
            }
        }

        // If activity on client socket, there is incoming message
        for (i = 0; i < max_clients; i++) {
            sd = client_sockets[i];

            if (FD_ISSET(sd, &readfds)) {
                if ((valread = read(sd, message, 1024)) == 0) {
                    // Client disconnected
                    getpeername(sd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
                    printf("Client disconnected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(sd);
                    client_sockets[i] = 0;
                } else {
                    // Send message to other clients
                    message[valread] = '\0';
                    for (i = 0; i < max_clients; i++) {
                        int client_sd = client_sockets[i];

                        if (client_sd != 0 && client_sd != sd) {
                            send(client_sd, message, strlen(message), 0);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
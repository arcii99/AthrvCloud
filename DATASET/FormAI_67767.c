//FormAI DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_clients = MAX_CLIENTS, activity, i, valread, sd, curr_client_count = 0;
    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to the specified address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        // Create a file descriptor set for all the active sockets
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);

        for (i = 0; i < max_clients; i++) {
            sd = client_socket[i];
            if (sd > 0) FD_SET(sd, &read_fds);
        }

        // Wait for activity on one of the sockets
        activity = select(max_clients + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // Handle incoming connections
        if (FD_ISSET(server_socket, &read_fds)) {
            int new_socket;
            struct sockaddr_in client_addr;
            int addr_len = sizeof(client_addr);

            if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            // Add the new client to the client list
            for (i=0; i<max_clients; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    curr_client_count += 1;
                    printf("New client connected with socket fd %d\n", new_socket);
                    break;
                }
            }
        }

        // Handle incoming messages
        for (i = 0; i < max_clients; i++) {
            sd = client_socket[i];

            if (FD_ISSET(sd, &read_fds)) {
                if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    close(sd);
                    client_socket[i] = 0;
                    curr_client_count -= 1;
                    printf("Client disconnected with socket fd %d\n", sd);
                }
                else {
                    buffer[valread] = '\0';
                    printf("Received message from client with socket fd %d: %s", sd, buffer);

                    // Send the message to all other clients
                    for (int j = 0; j < max_clients; j++) {
                        if (client_socket[j] != 0 && client_socket[j] != sd) {
                            send(client_socket[j], buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
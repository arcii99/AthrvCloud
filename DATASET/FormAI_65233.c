//FormAI DATASET v1.0 Category: Chat server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int socket;
    char name[20];
};

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    int client_sockets[MAX_CLIENTS];
    struct client clients[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];

    // Creating the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Setting up the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Binding the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not bind the socket to the address\n");
        exit(1);
    }

    // Listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error: Could not listen for incoming connections\n");
        exit(1);
    }

    printf("Chat server is running on port 9000...\n");

    // Initializing client sockets and names
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
        strcpy(clients[i].name, "Client");
    }

    while (1) {
        fd_set read_fds;
        int max_socket = server_socket;
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);

        // Adding active client sockets to the set
        for (i = 0; i < MAX_CLIENTS; i++) {
            int client_socket = client_sockets[i];
            if (client_socket > 0) {
                FD_SET(client_socket, &read_fds);
                if (client_socket > max_socket) {
                    max_socket = client_socket;
                }
            }
        }

        // Waiting for activity on the set of sockets
        if (select(max_socket + 1, &read_fds, NULL, NULL, NULL) < 0) {
            printf("Error: Could not select socket\n");
            exit(1);
        }

        // Handling activity on the server socket
        if (FD_ISSET(server_socket, &read_fds)) {
            int client_socket;
            int client_address_len = sizeof(client_address);
            client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len);

            // Adding new client to the list
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = client_socket;
                    break;
                }
            }

            // Sending welcome message to new client
            sprintf(buffer, "Welcome to the chat room, enter your name:\n");
            send(client_socket, buffer, strlen(buffer), 0);
        }

        // Handling activity on client sockets
        for (i = 0; i < MAX_CLIENTS; i++) {
            int client_socket = client_sockets[i];
            if (FD_ISSET(client_socket, &read_fds)) {
                int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
                buffer[bytes_received] = '\0';

                // If client disconnected
                if (bytes_received == 0) {
                    // Removing client from the list
                    close(client_socket);
                    client_sockets[i] = 0;
                    strcpy(clients[i].name, "Client");
                } else {
                    // Handling client message
                    if (strcmp(clients[i].name, "Client") == 0) {
                        // Setting the client name
                        strcpy(clients[i].name, buffer);
                        sprintf(buffer, "Hello, %s! You have joined the chat room.\n", clients[i].name);
                        send(client_socket, buffer, strlen(buffer), 0);
                    } else {
                        // Broadcasting the client message to all other clients
                        sprintf(buffer, "%s: %s", clients[i].name, buffer);
                        for (int j = 0; j < MAX_CLIENTS; j++) {
                            if (client_sockets[j] > 0 && j != i) {
                                send(client_sockets[j], buffer, strlen(buffer), 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
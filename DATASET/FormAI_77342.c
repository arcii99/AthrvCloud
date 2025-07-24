//FormAI DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *welcome_message = "Welcome to the chat room!\n";
    int client_sockets[MAX_CLIENTS] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Server address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on socket
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Wait for new client connections
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Send welcome message to new client
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        // Add new client socket to list
        int new_client_index = -1;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                new_client_index = i;
                break;
            }
        }

        // Create new client message buffer
        char *new_client_message = (char *) malloc(BUFFER_SIZE * sizeof(char));
        sprintf(new_client_message, "Client %d joined the chat.\n", new_client_index);

        // Send message to all clients (except the new one)
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && i != new_client_index) {
                send(client_sockets[i], new_client_message, strlen(new_client_message), 0);
            }
        }

        // Free up memory used by new client message buffer
        free(new_client_message);

        while (1) {
            // Read message from current client
            valread = read(new_socket, buffer, BUFFER_SIZE);

            // Check for client disconnection
            if (valread == 0) {
                // Create disconnection message
                char *disconnection_message = (char *) malloc(BUFFER_SIZE * sizeof(char));
                sprintf(disconnection_message, "Client %d disconnected from the chat.\n", new_client_index);

                // Send message to all clients (except the disconnected one)
                for (int i = 0; i < MAX_CLIENTS; i++) {
                    if (client_sockets[i] != 0 && i != new_client_index) {
                        send(client_sockets[i], disconnection_message, strlen(disconnection_message), 0);
                    }
                }

                // Free up memory used by disconnection message buffer
                free(disconnection_message);

                // Close current client socket and remove from list
                close(new_socket);
                client_sockets[new_client_index] = 0;

                // Exit current client loop
                break;
            }

            // Create chat message
            char *chat_message = (char *) malloc(BUFFER_SIZE * sizeof(char));
            sprintf(chat_message, "Client %d: %s", new_client_index, buffer);

            // Send message to all clients (including the sender)
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] != 0) {
                    send(client_sockets[i], chat_message, strlen(chat_message), 0);
                }
            }

            // Free up memory used by chat message buffer
            free(chat_message);

            // Clear buffer
            memset(buffer, 0, BUFFER_SIZE);
        }
    }

    return 0;
}
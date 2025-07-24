//FormAI DATASET v1.0 Category: Chat server ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Welcome to the Chat Server!\n";
    int client_sockets[MAX_CLIENTS] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the defined port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Chat server is now listening on port 8080...\n");

    while (1) {
        // Accept incoming connections from clients
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Send welcome message to the newly connected client
        send(new_socket, hello, strlen(hello), 0);

        // Add the new client socket to the list of client sockets
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                break;
            }
        }

        // Inform other clients that a new client has joined the chat
        char new_client_message[100];
        sprintf(new_client_message, "Client %d has joined the chat.\n", i+1);
        for (int j = 0; j < MAX_CLIENTS; j++) {
            if (client_sockets[j] != 0 && client_sockets[j] != new_socket) {
                send(client_sockets[j], new_client_message, strlen(new_client_message), 0);
            }
        }

        // Handle messages from clients
        while (1) {
            valread = read(new_socket, buffer, 1024);
            if (valread == 0) {
                // Client has disconnected
                // Remove its socket from the list of client sockets
                for (int j = 0; j < MAX_CLIENTS; j++) {
                    if (client_sockets[j] == new_socket) {
                        client_sockets[j] = 0;
                        break;
                    }
                }

                // Inform remaining clients that this client has left the chat
                char leave_message[100];
                sprintf(leave_message, "Client %d has left the chat.\n", i+1);
                for (int j = 0; j < MAX_CLIENTS; j++) {
                    if (client_sockets[j] != 0) {
                        send(client_sockets[j], leave_message, strlen(leave_message), 0);
                    }
                }
                break;
            } else {
                // Broadcast the message to all clients except the sender
                for (int j = 0; j < MAX_CLIENTS; j++) {
                    if (client_sockets[j] != 0 && client_sockets[j] != new_socket) {
                        send(client_sockets[j], buffer, strlen(buffer), 0);
                    }
                }
            }
            memset(buffer, 0, sizeof(buffer));
        }
    }
    return 0;
}
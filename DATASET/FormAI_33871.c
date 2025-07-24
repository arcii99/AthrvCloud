//FormAI DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int port = 8080;

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind socket to port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    int bind_result = bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    if (bind_result < 0) {
        perror("Error binding socket to port");
        return 1;
    }

    // Start listening
    int listen_result = listen(server_fd, MAX_CLIENTS);
    if (listen_result < 0) {
        perror("Error starting to listen");
        return 1;
    }
    printf("Listening on port %d...\n", port);

    // Accept and handle connections
    struct sockaddr_in client_address;
    int client_address_size = sizeof(client_address);
    int client_sockets[MAX_CLIENTS];
    int num_clients = 0;
    while (1) {
        // Accept new client connection
        int client_fd = accept(server_fd, (struct sockaddr*)&client_address, (socklen_t*)&client_address_size);
        if (client_fd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Add new client socket to array
        client_sockets[num_clients] = client_fd;
        num_clients++;

        char buffer[BUFFER_SIZE];
        while (1) {
            // Receive message from client
            int recv_result = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (recv_result < 0) {
                perror("Error receiving message from client");
                break;
            } else if (recv_result == 0) {
                printf("Connection closed by %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                break;
            }

            printf("Message from %s:%d: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

            // Send message back to client
            int send_result = send(client_fd, buffer, recv_result, 0);
            if (send_result < 0) {
                perror("Error sending message to client");
                break;
            }
        }

        // Remove client socket from array
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] == client_fd) {
                for (int j = i; j < num_clients - 1; j++) {
                    client_sockets[j] = client_sockets[j + 1];
                }
                num_clients--;
                break;
            }
        }

        // Close client socket
        close(client_fd);
    }

    // Close server socket
    close(server_fd);

    return 0;
}
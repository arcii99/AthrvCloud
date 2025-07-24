//FormAI DATASET v1.0 Category: Chat server ; Style: rigorous
/* 
 * Simple Chat Server
 * Written by [Your Name]
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
 
#define BUFFER_SIZE 1024
#define PORT 8080
#define MAX_CLIENTS 10
 
int main(int argc, char *argv[]) {
    int server_fd, new_socket, num_clients = 0;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    int client_sockets[MAX_CLIENTS] = {0};
    char buffer[BUFFER_SIZE];
     
    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
     
    // Bind the socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
     
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
     
    printf("Server is running on port %d\n", PORT);
     
    while (true) {
        // Create a copy of the client socket list to use with select()
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] > 0) {
                FD_SET(client_sockets[i], &read_fds);
            }
        }
         
        // Wait for activity on any socket
        if (select(MAX_CLIENTS + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }
         
        // Check for new client connections
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
             
            // Add the new client socket to our list
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    num_clients++;
                    break;
                }
            }
             
            printf("New client connected. Total clients: %d\n", num_clients);
        }
         
        // Check for activity on existing client sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] > 0 && FD_ISSET(client_sockets[i], &read_fds)) {
                // Read incoming message from client
                int valread = read(client_sockets[i], buffer, BUFFER_SIZE);
                if (valread == 0) {
                    // Client disconnected
                    close(client_sockets[i]);
                    client_sockets[i] = 0;
                    num_clients--;
                    printf("Client disconnected. Total clients: %d\n", num_clients);
                } else {
                    // Send message to all other clients
                    buffer[valread] = '\0';
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (client_sockets[j] > 0 && client_sockets[j] != client_sockets[i]) {
                            send(client_sockets[j], buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }
     
    return 0;
}
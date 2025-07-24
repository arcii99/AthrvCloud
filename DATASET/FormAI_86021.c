//FormAI DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];

void process_message(char* buffer, int client_socket)
{
    printf("Received message from client %d: %s", client_socket, buffer);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(client_sockets[i] != 0 && client_sockets[i] != client_socket) {
            write(client_sockets[i], buffer, strlen(buffer));
        }
    }
}

int main(int argc, char const *argv[])
{
    int server_socket, new_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Reuse the socket and bind to a port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket option");
        exit(1);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("Failed to bind to the socket");
        exit(1);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Failed to listen to the socket");
        exit(1);
    }
    
    printf("==== Retro Style Chat Server ====\n");
    printf("Listening on port %d\n", PORT);

    while(1) {
        int max_fd = server_socket;
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);

        // Add all active client sockets to the FD set
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(client_sockets[i] != 0) {
                FD_SET(client_sockets[i], &read_fds);
                if(client_sockets[i] > max_fd) {
                    max_fd = client_sockets[i];
                }
            }
        }

        // Wait for activity on any of the sockets
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Failed to wait for socket activity");
            exit(1);
        }

        // Handle incoming connections
        if (FD_ISSET(server_socket, &read_fds)) {
            if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_length))<0) {
                perror("Failed to accept the incoming connection");
                exit(1);
            }

            // Add the new client to the array
            for(int i = 0; i < MAX_CLIENTS; i++) {
                if(client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    printf("New client connected with socket id %d\n", new_socket);
                    break;
                }
            }
        }

        // Handle activity on client sockets
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(client_sockets[i] != 0 && FD_ISSET(client_sockets[i], &read_fds)) {
                int valread = read(client_sockets[i], buffer, BUFFER_SIZE);
                if (valread <= 0) {
                    // Remove the client from the array
                    printf("Client with socket id %d disconnected\n", client_sockets[i]);
                    client_sockets[i] = 0;
                } else {
                    // Process the client's message
                    process_message(buffer, client_sockets[i]);
                }
            }
        }
    }

    return 0;
}
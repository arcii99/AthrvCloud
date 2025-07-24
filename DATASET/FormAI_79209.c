//FormAI DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc , char *argv[])
{
    int socket_fd, client_sockets[MAX_CLIENTS], client_socket, num_clients = 0, activity;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create socket
    if((socket_fd = socket(AF_INET , SOCK_STREAM , 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address values
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( 8080 );

    // Binding the socket to the address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Could not listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while(1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(socket_fd, &read_fds);
        int max_socket_fd = socket_fd;
        for (int i = 0 ; i < num_clients ; i++) {
            client_socket = client_sockets[i];
            if (client_socket > 0)
                FD_SET(client_socket, &read_fds);
            if (client_socket > max_socket_fd)
                max_socket_fd = client_socket;
        }

        activity = select(max_socket_fd + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        // Incoming connection
        if (FD_ISSET(socket_fd, &read_fds)) {
            int new_socket;
            int address_length = sizeof(client_address);
            if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Add the new client socket to the array and increment the number of clients
            num_clients++;
            for (int i = 0 ; i < MAX_CLIENTS ; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    break;
                }
            }
        }

        // Incoming message from a client
        for (int i = 0 ; i < num_clients ; i++) {
            client_socket = client_sockets[i];
            if (FD_ISSET(client_socket, &read_fds)) {
                int read_size = read(client_socket, buffer, BUFFER_SIZE);
                if (read_size == 0) { // Client disconnected
                    close(client_socket);
                    client_sockets[i] = 0;
                    num_clients--;
                }
                else { // Broadcast message to all other clients
                    for (int j = 0 ; j < num_clients ; j++) {
                        int broadcast_socket = client_sockets[j];
                        if (broadcast_socket != client_socket) {
                            write(broadcast_socket, buffer, strlen(buffer));
                        }
                    }
                }
            }
        }
    }

    return 0;
}
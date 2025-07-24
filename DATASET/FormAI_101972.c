//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
// This is a unique C network Quality of Service (QoS) monitor program
// that allows users to measure the QoS of their local network 
// and all connected devices. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

// Define the port number we will be using for our QoS monitor server
#define PORT 8080

// Define the maximum length of a single message from a client
#define MAX_MSG_LENGTH 1024

// Define the maximum number of clients that can be connected to this server at once
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addr_len = sizeof(address);
    char buffer[MAX_MSG_LENGTH] = {0};
    int opt = 1;
    int client_sockets[MAX_CLIENTS], max_clients = 0;
    fd_set readfds;

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options to reuse the address and port number
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind the server socket to the address and port number
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started listening on port %d...\n", PORT);

    while (1) {
        // Clear the file descriptor set
        FD_ZERO(&readfds);

        // Add the server socket to the file descriptor set
        FD_SET(server_fd, &readfds);

        // Add all client sockets to the file descriptor set
        for (int i = 0; i < max_clients; i++) {
            if (client_sockets[i] != 0) {
                FD_SET(client_sockets[i], &readfds);
            }
        }

        // Wait for activity on any of the sockets
        int activity = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // If activity is detected on the server socket, accept the new connection
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            // Add the new client socket to the client_sockets array
            for (int i = 0; i < max_clients; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    printf("New connection, socket fd is %d, IP is : %s, port : %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    break;
                }
            }

            // Update the maximum number of clients
            if (max_clients < MAX_CLIENTS) {
                max_clients++;
            }
        }

        // Check all client sockets for activity
        for (int i = 0; i < max_clients; i++) {
            int client_socket = client_sockets[i];

            // If activity is detected on a client socket, read the incoming message
            if (FD_ISSET(client_socket, &readfds)) {
                if ((valread = read(client_socket, buffer, MAX_MSG_LENGTH)) == 0) {
                    // The client has disconnected, remove the socket from the client_sockets array
                    printf("Host disconnected, socket fd is %d , IP is : %s, port : %d\n", client_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(client_socket);
                    client_sockets[i] = 0;
                } else {
                    // We received a message from the client, do something with it...
                    printf("Received message from client on socket %d: %s\n", client_socket, buffer);
                }
            }
        }
    }

    return 0;
}
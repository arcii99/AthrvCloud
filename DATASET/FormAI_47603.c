//FormAI DATASET v1.0 Category: Socket programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080 
#define MAX_CLIENTS 10 
#define BUFFER_SIZE 1024 

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, client_sockets[MAX_CLIENTS], max_clients = MAX_CLIENTS, activity, i, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the given PORT
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Waiting for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    fd_set readfds; // file descriptor set for select()
    int max_sd; // maximum file descriptor

    // Initialize client sockets to 0
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    printf("Waiting for connections on port %d...\n", PORT);

    while (1) {
        // Clear the file descriptor set
        FD_ZERO(&readfds); 

        // Add the server socket to the file descriptor set
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        // Add all the client sockets to the file descriptor set
        for (i = 0; i < max_clients; i++) {
            int client_socket = client_sockets[i];

            // If a client socket descriptor is valid, add it to the set
            if (client_socket > 0) {
                FD_SET(client_socket, &readfds);
            }

            // Update the maximum file descriptor
            if (client_socket > max_sd) {
                max_sd = client_socket;
            }
        }

        // Wait for activity on one of the socket file descriptors
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // If the server socket has incoming connection, accept it
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            printf("New connection from %s:%d, socket fd is %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), new_socket);

            // Add the new socket to the array of client sockets
            for (i = 0; i < max_clients; i++) {
                if (client_sockets[i] == 0 ) {
                    client_sockets[i] = new_socket;
                    printf("Adding client %d to the list of clients\n", i);
                    break;
                }
            }
        }

        // Check for activity on the client sockets
        for (i = 0; i < max_clients; i++) {
            int client_socket = client_sockets[i];

            if (FD_ISSET(client_socket, &readfds)) {
                // If the client socket has been closed, remove it from the array of client sockets
                if ((valread = read(client_socket, buffer, BUFFER_SIZE)) <= 0) {
                    close(client_socket);
                    client_sockets[i] = 0;
                    printf("Client %d disconnected\n", i);
                }
                // Otherwise, echo back the message to the client
                else {
                    buffer[valread] = '\0';
                    printf("Received message from client %d: %s", i, buffer);
                    write(client_socket, buffer, strlen(buffer));
                }
            }
        }
    }
    return 0;
}
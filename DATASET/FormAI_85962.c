//FormAI DATASET v1.0 Category: Chat server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_CLIENTS 100

int main(int argc, char const *argv[]) {

    int server_fd, client_fd, sd, max_clients = MAX_CLIENTS, activity, valread;
    int max_sd;
    struct sockaddr_in address;
    char buffer[MAX_BUFFER_SIZE];
    fd_set readfds; 
    
    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an IP address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, max_clients) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addrlen = sizeof(address);
    int clients[MAX_CLIENTS];
    for (int i=0; i<max_clients; i++) {
        clients[i] = 0;
    }

    while (1) {

        // Clear the file descriptor set
        FD_ZERO(&readfds);

        // Add server socket to file descriptor set
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        // Add child sockets to fd set
        for (int i=0; i<max_clients; i++) {
            sd = clients[i];
            if (sd > 0)
                FD_SET(sd , &readfds);
            if (sd > max_sd)
                max_sd = sd;
        }

        // Wait for activity on one of the sockets
        activity = select(max_sd + 1 , &readfds , NULL , NULL , NULL);

        if (activity < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        // Handle activity on the server socket
        if (FD_ISSET(server_fd, &readfds)) {
            if ((client_fd = accept(server_fd, 
                                   (struct sockaddr *)&address,
                                   (socklen_t*)&addrlen))<0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // Display the new connection information
            char *ip = inet_ntoa(address.sin_addr);
            int port = ntohs(address.sin_port);
            printf("New connection: %s:%d\n", ip, port);

            // Add the new client to the client array
            for (int i=0; i<max_clients; i++) {
                if (clients[i] == 0) {
                    clients[i] = client_fd;
                    break;
                }
            }
        }

        // Handle activity on the client sockets
        for (int i=0; i<max_clients; i++) {
            sd = clients[i];
            if (FD_ISSET(sd, &readfds)) {

                valread = read(sd, buffer, MAX_BUFFER_SIZE);

                // Check for disconnected clients
                if (valread == 0) {
                    char *ip = inet_ntoa(address.sin_addr);
                    int port = ntohs(address.sin_port);
                    printf("Client disconnected: %s:%d\n", ip, port);
                    close(sd);
                    clients[i] = 0;
                }

                // Echo the message back to the client
                else {
                    buffer[valread] = '\0';
                    send(sd, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}
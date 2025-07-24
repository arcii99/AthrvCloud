//FormAI DATASET v1.0 Category: Networking ; Style: interoperable
/*
 *  This program demonstrates a simple client-server interprocess communication using 
 *  socket programming in C. The server waits for client connections and echoes back 
 *  whatever client sends. This program relies on the sockets `socket`, `bind`, `listen`, 
 *  `accept`, `recv` and `send` functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to handle client connections
void handle_connection(int client_sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes;

    // Read data from the client
    num_bytes = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
    if(num_bytes < 0) {
        perror("recv");
        return;
    }

    // Add null terminator at the end of the string received from client
    buffer[num_bytes] = '\0';

    // Print the data received from client
    printf("Received: %s\n", buffer);

    // Echo back the data received from client
    if(send(client_sockfd, buffer, num_bytes, 0) < 0) {
        perror("send");
        return;
    }

    // Close the client socket
    close(client_sockfd);
}

int main(int argc, char const *argv[]) {

    int server_sockfd, client_sockfd, opt = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_length;
    int max_fd, fd;
    fd_set master_set, read_set;

    // Initialize the master set and temporary read set
    FD_ZERO(&master_set);
    FD_ZERO(&read_set);

    // Create a socket for server
    if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of the address
    if(setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, 
    					(char*)&opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind the socket to the server address
    if(bind(server_sockfd, (struct sockaddr *)&server_address, 
    				sizeof(server_address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Add the server socket to the master set
    FD_SET(server_sockfd, &master_set);
    max_fd = server_sockfd;

    while(1) {
        // Copy the master set to the read set
        read_set = master_set;

        // Wait for incoming connections or data from clients
        if(select(max_fd + 1, &read_set, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // Check for new connection request from clients
        if(FD_ISSET(server_sockfd, &read_set)) {
            client_addr_length = sizeof(client_address);

            // Accept the incoming connection request from a client
            if((client_sockfd = accept(server_sockfd, 
            		(struct sockaddr *)&client_address, 
            		&client_addr_length)) < 0) {
                perror("accept");
            } else {
                // Add the client socket to the master set
                FD_SET(client_sockfd, &master_set);

                if(client_sockfd > max_fd) {
                    max_fd = client_sockfd;
                }

                printf("New client connection (fd = %d)\n", client_sockfd);
            }
        } else {
            // Check for incoming data from clients
            for(fd = 0; fd <= max_fd; fd++) {
                if(FD_ISSET(fd, &read_set)) {
                    if(fd == server_sockfd) {
                        continue;
                    } else {
                        handle_connection(fd);
                        FD_CLR(fd, &master_set);
                    }
                }
            }
        }
    }

    // Close the server socket
    close(server_sockfd);

    return 0;
}
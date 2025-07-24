//FormAI DATASET v1.0 Category: Chat server ; Style: careful
// This is a simple chat server that listens for incoming connections from clients 
// and relays messages between them. It uses the select() function to multiplex 
// multiple clients over the same file descriptor.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int socket_fd, fd_set* client_fds, int* num_clients) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    // read data from the client socket
    bytes_read = read(socket_fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    } else if (bytes_read == 0) {
        // client disconnected
        printf("Client at socket %d disconnected\n", socket_fd);
        close(socket_fd);
        FD_CLR(socket_fd, client_fds);
        (*num_clients)--;
    } else {
        // relay message to other clients
        printf("Received message from client at socket %d: %s", socket_fd, buffer);
        
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, client_fds) && i != socket_fd) {
                if (write(i, buffer, bytes_read) == -1) {
                    perror("write");
                    exit(1);
                }
            }
        }
    }
}

int main() {
    fd_set client_fds, read_fds;
    int server_fd, client_fd;
    int num_clients = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char addr_str[INET_ADDRSTRLEN];
    int max_fd;

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind server socket to address
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // initialize file descriptor sets
    FD_ZERO(&client_fds);
    FD_ZERO(&read_fds);
    FD_SET(server_fd, &client_fds);
    max_fd = server_fd;

    while (1) {
        // reset read fds to client fds
        read_fds = client_fds;

        // select() blocks until there is activity on one of the file descriptors
        if (select(max_fd+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(1);
        }

        // check for new client connections
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_len)) == -1) {
                perror("accept");
                exit(1);
            }

            // add client socket to client fds set
            FD_SET(client_fd, &client_fds);
            num_clients++;

            // find maximum file descriptor value
            if (client_fd > max_fd) {
                max_fd = client_fd;
            }

            // print client connection information
            inet_ntop(AF_INET, &client_addr.sin_addr, addr_str, INET_ADDRSTRLEN);
            printf("New client connected from %s:%d at socket %d\n", addr_str, ntohs(client_addr.sin_port), client_fd);
        }

        // check for activity on existing client sockets
        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                handle_client(i, &client_fds, &num_clients);
            }
        }
    }

    return 0;
}
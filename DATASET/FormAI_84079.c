//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_CONNECTIONS 1024
#define MAX_BUFFER_SIZE 10240
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {

    int server_fd, client_fd, max_fd;
    struct sockaddr_in server_address, client_address;

    // Initialize server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind server socket to server address
    bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_fd, MAX_CONNECTIONS);

    // Initialize file descriptor set for select()
    fd_set master_fd_set, read_fd_set;
    FD_ZERO(&master_fd_set);
    FD_SET(server_fd, &master_fd_set);
    max_fd = server_fd;

    // Loop forever
    while (1) {
        read_fd_set = master_fd_set;

        // Select and wait for incoming connections or data
        select(max_fd + 1, &read_fd_set, NULL, NULL, NULL);

        // Check for new connections
        if (FD_ISSET(server_fd, &read_fd_set)) {
            socklen_t client_address_size = sizeof(client_address);
            client_fd = accept(server_fd, (struct sockaddr *) &client_address, &client_address_size);
            FD_SET(client_fd, &master_fd_set);
            if (client_fd > max_fd) {
                max_fd = client_fd;
            }
        } else {
            // Handle data from existing client connections
            char buffer[MAX_BUFFER_SIZE];
            for (int i = server_fd + 1; i <= max_fd; i++) {
                if (FD_ISSET(i, &read_fd_set)) {
                    ssize_t n = recv(i, buffer, sizeof(buffer), 0);
                    if (n <= 0) {
                        close(i);
                        FD_CLR(i, &master_fd_set);
                    } else {
                        send(i, buffer, n, 0);
                    }
                }
            }
        }
    }

    return 0;
}
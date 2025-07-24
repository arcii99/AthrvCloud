//FormAI DATASET v1.0 Category: Socket programming ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket_fd, client_socket_fds[MAX_CLIENTS];
fd_set master_set;

void handle_new_connection(int);
void handle_client_message(int);
void cleanup_and_exit();

int main(int argc, char *argv[]) {
    int i;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket descriptor
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        cleanup_and_exit();
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    // Bind the socket to the server address
    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket to server address");
        cleanup_and_exit();
    }

    // Start listening for incoming connections
    if (listen(server_socket_fd, MAX_CLIENTS) == -1) {
        perror("Failed to start listening for incoming connections");
        cleanup_and_exit();
    }

    // Initialize the set of sockets to listen on
    FD_ZERO(&master_set);
    FD_SET(server_socket_fd, &master_set);

    while (1) {
        fd_set read_set = master_set;

        // Wait for any activity on the sockets
        if (select(FD_SETSIZE, &read_set, NULL, NULL, NULL) == -1) {
            perror("Failed to select sockets");
            cleanup_and_exit();
        }

        // Handle any incoming connections
        if (FD_ISSET(server_socket_fd, &read_set)) {
            int client_socket_fd;
            if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
                perror("Failed to accept incoming connection");
                cleanup_and_exit();
            }

            handle_new_connection(client_socket_fd);
        }

        // Handle client messages
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_socket_fds[i], &read_set)) {
                handle_client_message(client_socket_fds[i]);
            }
        }
    }

    cleanup_and_exit();
}

void handle_new_connection(int client_socket_fd) {
    int i;
    printf("New connection established: %d\n", client_socket_fd);

    // Add the new client socket to the set of sockets to listen on
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_socket_fds[i] == 0) {
            client_socket_fds[i] = client_socket_fd;
            FD_SET(client_socket_fd, &master_set);
            break;
        }
    }
}

void handle_client_message(int client_socket_fd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    if (recv(client_socket_fd, buffer, sizeof(buffer), 0) <= 0) {
        printf("Client %d disconnected\n", client_socket_fd);
        close(client_socket_fd);
        FD_CLR(client_socket_fd, &master_set);
        client_socket_fds[client_socket_fd] = 0;
    } else {
        printf("Received message from client %d: %s\n", client_socket_fd, buffer);
        // Process the message received from the client
    }
}

void cleanup_and_exit() {
    int i;

    // Close all open sockets
    close(server_socket_fd);
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_socket_fds[i] != 0) {
            close(client_socket_fds[i]);
        }
    }

    printf("Exiting...\n");
    exit(0);
}
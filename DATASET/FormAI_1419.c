//FormAI DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8080
#define MAX_CLIENTS 3
#define BUFFER_SIZE 1024

int server_fd;
int client_fds[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_fd) {

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';

        // check for exit command
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Client disconnected\n");
            num_clients--;
            break;
        } else {
            printf("Client says: %s", buffer);
        }
    }
    close(client_fd);
}

void handle_sigint(int sig) {
    printf("\nClosing server and all clients\n");
    for (int i = 0; i < num_clients; i++) {
        close(client_fds[i]);
    }
    close(server_fd);
    exit(0);
}

int main() {
    // register sigint handler
    signal(SIGINT, handle_sigint);

    // set up server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Error creating server socket\n");
        exit(1);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Error binding socket to port %d\n", PORT);
        exit(1);
    }

    // start listening for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        printf("Error starting server\n");
        exit(1);
    }

    // set up client sockets
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    printf("Server ready and waiting on port %d\n", PORT);

    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len);
        if (client_fd < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Server is full\n");
            close(client_fd);
            continue;
        }

        // add client to list of clients
        client_fds[num_clients++] = client_fd;

        printf("New client connected\n");

        // fork new process to handle client
        if (fork() == 0) {
            handle_client(client_fd);
            exit(0);
        }
    }
}
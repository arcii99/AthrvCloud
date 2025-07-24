//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define ERROR(msg) { perror(msg); exit(EXIT_FAILURE); }
#define BUFFER_SIZE 1024

void handle_client(int connection);

int main(void) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    pid_t pid;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        ERROR("Socket creation failed");

    // Bind socket to IP and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5000);
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
        ERROR("Binding failed");

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1)
        ERROR("Listening failed");

    printf("Server listening on port 5000\n");

    // Handle incoming connections
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_size)) == -1)
            ERROR("Accepting failed");

        if ((pid = fork()) == -1)
            ERROR("Forking failed");
        
        if (pid == 0) {
            // Child process
            close(server_fd);
            handle_client(client_fd);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(client_fd);
        }
    }

    return 0;
}

void handle_client(int connection) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        // Receive data from client
        memset(buffer, 0, BUFFER_SIZE);
        if ((bytes_received = recv(connection, buffer, BUFFER_SIZE, 0)) == -1)
            ERROR("Receiving failed");

        if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        }

        // Echo data back to client
        if (send(connection, buffer, bytes_received, 0) == -1)
            ERROR("Sending failed");

        printf("Received and sent back %d bytes\n", bytes_received);
    }

    close(connection);
}
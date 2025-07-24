//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 5000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main()
{
    // Create server socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1)
    {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific network interface and port
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, MAX_CLIENTS) == -1)
    {
        perror("Failed to listen on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1)
    {
        // Accept a new client connection
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);

        int client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket_fd == -1)
        {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Accepted new client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client request
        char buffer[BUFFER_SIZE] = {0};
        int num_bytes = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
        if (num_bytes == -1)
        {
            perror("Failed to receive data from client");
            close(client_socket_fd);
            continue;
        }

        printf("Received data from client: %s\n", buffer);

        // Send response back to client
        const char *response = "Hello client!";
        num_bytes = send(client_socket_fd, response, strlen(response), 0);
        if (num_bytes == -1)
        {
            perror("Failed to send response to client");
            close(client_socket_fd);
            continue;
        }

        printf("Sent response to client: %s\n", response);

        // Close connection with client socket
        close(client_socket_fd);
    }

    // Close server socket
    close(server_socket_fd);

    return 0;
}
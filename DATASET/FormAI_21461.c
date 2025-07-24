//FormAI DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to a specific IP and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("Failed to start listening for clients");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming client connections
    while (1)
    {
        socklen_t client_address_length = sizeof(client_address);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_length)) < 0)
        {
            perror("Failed to accept incoming client connection");
            exit(EXIT_FAILURE);
        }

        char client_ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip_address, INET_ADDRSTRLEN);
        printf("Client connected from %s:%d\n", client_ip_address, ntohs(client_address.sin_port));

        // Handle incoming client messages
        while (1)
        {
            ssize_t received_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (received_bytes == 0)
            {
                printf("Connection closed by client\n");
                break;
            }
            else if (received_bytes < 0)
            {
                perror("Failed to receive message from client");
                exit(EXIT_FAILURE);
            }

            printf("Received message from client: %s", buffer);

            // Echo message back to client
            ssize_t sent_bytes = send(client_fd, buffer, strlen(buffer), 0);
            if (sent_bytes < 0)
            {
                perror("Failed to send message to client");
                exit(EXIT_FAILURE);
            }

            memset(buffer, 0, BUFFER_SIZE);
        }

        close(client_fd);
    }

    return 0;
}
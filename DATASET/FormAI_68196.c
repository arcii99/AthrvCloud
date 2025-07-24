//FormAI DATASET v1.0 Category: Chat server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connections
    while (1)
    {
        int client_len = sizeof(client_addr);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Send a welcome message to the client
        char *welcome_message = "Welcome to my chat server!\n";
        send(client_fd, welcome_message, strlen(welcome_message), 0);

        // Receive messages from the client
        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received < 0)
            {
                perror("Receive failed");
                exit(EXIT_FAILURE);
            }

            if (bytes_received == 0)
            {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message: %s", buffer);

            // Echo the message back to the client
            send(client_fd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}
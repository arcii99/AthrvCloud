//FormAI DATASET v1.0 Category: Socket programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    printf("Welcome to my lively C socket programming example!\n");

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Define the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Could not bind socket to server address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 5) < 0)
    {
        perror("Could not listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080...\n");

    while (1)
    {
        // Accept incoming connection
        int client_fd = accept(socket_fd, NULL, NULL);
        if (client_fd < 0)
        {
            perror("Could not accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected!\n");

        // Read data from the client
        char buffer[1024] = {0};
        int bytes_received = read(client_fd, buffer, sizeof(buffer));
        if (bytes_received < 0)
        {
            perror("Could not read from client");
            exit(EXIT_FAILURE);
        }

        printf("Received from client: %s\n", buffer);

        // Send data to the client
        char *message = "Hello from the server!";
        int bytes_sent = send(client_fd, message, strlen(message), 0);
        if (bytes_sent < 0)
        {
            perror("Could not send data to client");
            exit(EXIT_FAILURE);
        }

        // Close the client socket
        close(client_fd);
        printf("Client disconnected.\n");
    }

    // Close the server socket
    close(socket_fd);
    printf("Server closed.\n");

    return 0;
}
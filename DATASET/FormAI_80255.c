//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Create a socket

    if (sock < 0)
    {
        perror("Socket creation error.");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any available address
    server_addr.sin_port = htons(PORT);

    // Bind the socket to an address
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Socket bind error.");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0)
    {
        perror("Socket listen error.");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d.\n", PORT);

    while (1)
    {
        int client_sock = accept(sock, NULL, NULL); // Accept incoming connections

        if (client_sock < 0)
        {
            perror("Socket accept error.");
            exit(EXIT_FAILURE);
        }

        printf("Client connected.\n");

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        // Receive data from client
        int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0)
        {
            perror("Socket receive error.");
            exit(EXIT_FAILURE);
        }

        printf("Received message from client: %s\n", buffer);

        // Send data back to client
        char message[] = "Hello from server!";
        int bytes_sent = send(client_sock, message, strlen(message), 0);

        if (bytes_sent < 0)
        {
            perror("Socket send error.");
            exit(EXIT_FAILURE);
        }

        close(client_sock); // Close the client socket
        printf("Client disconnected.\n");
    }

    close(sock); // Close the server socket

    return 0;
}
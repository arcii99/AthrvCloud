//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
/**
 * This program demonstrates a basic TCP client-server communication using 
 * socket programming in C. The client sends a message to the server and the server
 * echoes back the same message to the client.
 *
 * Author: [Your name]
 * Date: [Date]
 */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 8000

int main()
{
    // Create a socket file descriptor
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0)
    {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    printf("Socket created successfully!\n");

    // Create the server structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the server address
    if(bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Socket bind failed!");
        exit(EXIT_FAILURE);
    }

    printf("Socket binded to port %d successfully!\n", PORT);

    // Start listening for incoming connections on the socket
    if(listen(sock_fd, 3) < 0)
    {
        perror("Listen failed!");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connections and handle them
    struct sockaddr_in client_addr;
    int client_fd;
    char buffer[1024] = {0};
    int valread;

    while(1)
    {
        // Wait for incoming connections
        int addrlen = sizeof(client_addr);
        client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if(client_fd < 0)
        {
            perror("Error accepting connection!");
            continue;
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Read incoming message from the client
        valread = read(client_fd, buffer, 1024);
        printf("Received message from client: %s\n", buffer);

        // Echo message back to the client
        if(send(client_fd, buffer, strlen(buffer), 0) < 0)
        {
            perror("Error sending message");
            continue;
        }

        printf("Message echoed back to client successfully\n");

        // Close the client socket
        close(client_fd);
    }

    // Close the server socket
    close(sock_fd);

    return 0;
}
//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 5000

int main(int argc, char const *argv[])
{
    int socket_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    int client_socket_fd;
    int valread;
    socklen_t addr_len = sizeof(client_addr);

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address attributes
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket
    if (listen(socket_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connection...\n");

    // Accept incoming connections
    if ((client_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0)
    {
        perror("Connection not accepted");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted\n");

    // Send a message to the client upon successful connection
    char *message = "Welcome! You have successfully connected to the server\n";
    send(client_socket_fd, message, strlen(message), 0);

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        // Receive incoming message from client
        valread = read(client_socket_fd, buffer, 1024);

        // If the client sends an "exit" message, then close the connection
        if (strcmp(buffer, "exit\n") == 0)
        {
            printf("Client has closed the connection\n\n");
            break;
        }
        printf("Client: %s", buffer);

        // Get user input to send to the client
        printf("Enter message: ");
        fgets(buffer, 1024, stdin);

        // Send message to the client
        send(client_socket_fd, buffer, strlen(buffer), 0);
        printf("Message sent\n");
    }

    // Close the client and server sockets
    close(client_socket_fd);
    close(socket_fd);
    return 0;
}
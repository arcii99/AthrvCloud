//FormAI DATASET v1.0 Category: Socket programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int socket_fd, client_socket, valread;
    struct sockaddr_in address;

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to specified port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0)
    {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    struct sockaddr_in client_info;
    socklen_t client_info_size = sizeof(client_info);

    if ((client_socket = accept(socket_fd, (struct sockaddr *)&client_info, &client_info_size))<0)
    {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    // Send a message to the client
    char *message = "Hello from server!";
    send(client_socket, message, strlen(message), 0);
    printf("Message sent to client\n");

    // Receive response from client
    char buffer[1024] = {0};
    if ((valread = read(client_socket, buffer, 1024)) < 0)
    {
        perror("Failed to receive response from client");
        exit(EXIT_FAILURE);
    }
    printf("Received message from client: %s\n", buffer);

    // Close sockets and exit
    close(client_socket);
    close(socket_fd);
    return 0;
}
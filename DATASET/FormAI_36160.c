//FormAI DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    ssize_t bytes;
    
    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to an IP address and port number
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8888);
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Server listening on port 8888...\n");

    // Accept incoming connections
    socklen_t client_addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive data from the client
    while ((bytes = recv(client_socket, buffer, sizeof(buffer), 0)) > 0)
    {
        printf("Received: %s", buffer);

        // Send data back to the client
        send(client_socket, buffer, bytes, 0);

        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
    }

    // Close the client socket
    close(client_socket);

    // Close the server socket
    close(server_socket);

    return 0;
}
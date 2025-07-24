//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
/* Romeo and Juliet Simple Web Server */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char response_data[] = "Hello, World!\n";
    char request_buffer[1024];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1)
    {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Prepare server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Error: Could not bind socket\n");
        exit(1);
    }

    // Start listening for connections
    listen(server_socket, 5);

    printf("The server is listening on port 8080...\n");

    while (1)
    {
        // Accept connection from client
        int client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length);

        if (client_socket < 0)
        {
            printf("Error: Could not accept connection\n");
            continue;
        }

        // Read request data from client
        memset(request_buffer, 0, sizeof(request_buffer));
        long bytes_received = recv(client_socket, request_buffer, sizeof(request_buffer), 0);

        if (bytes_received < 0)
        {
            printf("Error: Could not receive data\n");
            continue;
        }

        // Send response data to client
        send(client_socket, response_data, strlen(response_data), 0);
        printf("Response sent to client: %s", response_data);

        // Close connection to client
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}
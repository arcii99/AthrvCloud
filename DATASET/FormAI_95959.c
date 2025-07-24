//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum message length
#define MAX_MESSAGE_LENGTH 1024

// Function to handle communication with clients
void handle_client(int client_socket) 
{
    char message[MAX_MESSAGE_LENGTH];
    int num_bytes_received = recv(client_socket, message, MAX_MESSAGE_LENGTH, 0);

    if (num_bytes_received < 0) 
    {
        printf("Error receiving message from client\n");
        return;
    }
    else if (num_bytes_received == 0)
    {
        printf("Client disconnected\n");
        return;
    }
    else 
    {
        // Echo back the message to the client
        if (send(client_socket, message, num_bytes_received, 0) < 0) 
        {
            printf("Error sending message to client\n");
        }
        else 
        {
            handle_client(client_socket);
        }
    }
}

int main() 
{
    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) 
    {
        printf("Error creating server socket\n");
        return 1;
    }

    // Create the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(5000);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        printf("Error binding server socket to address\n");
        return 1;
    }

    // Start listening for client connections
    if (listen(server_socket, 5) < 0) 
    {
        printf("Error listening for client connections\n");
        return 1;
    }

    printf("Server started. Listening for client connections on port 5000...\n");

    while(1) 
    {
        // Accept incoming client connections
        struct sockaddr_in client_address;
        int client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

        if (client_socket < 0) 
        {
            printf("Error accepting client connection\n");
            continue;
        }

        printf("Client connected. IP address: %s, port number: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        handle_client(client_socket);
    }

    fflush(stdout);
    close(server_socket);

    return 0;
}
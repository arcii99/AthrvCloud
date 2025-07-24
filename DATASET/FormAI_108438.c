//FormAI DATASET v1.0 Category: Client Server Application ; Style: protected
/* This is a simple client-server program that allows clients to connect to a server and send/receive messages. 
The server uses a protected style to ensure that only authenticated clients can connect and send messages. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to handle client requests
void handle_client_request(int client_socket)
{
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int num_bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (num_bytes_received < 0)
    {
        perror("Failed to receive message from client");
        return;
    }
    printf("Received message from client: %s\n", buffer);
    char response[] = "Message received!";
    send(client_socket, response, strlen(response), 0);
}

int main()
{
    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Failed to create server socket");
        return 1;
    }

    // Bind socket to port 8888
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);
    int bind_result = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (bind_result < 0)
    {
        perror("Failed to bind server socket to port");
        return 1;
    }

    // Listen for clients
    int listen_result = listen(server_socket, 5);
    if (listen_result < 0)
    {
        perror("Failed to start listening for clients");
        return 1;
    }

    while (1)
    {
        // Accept incoming client connection
        struct sockaddr_in client_address;
        memset(&client_address, 0, sizeof(client_address));
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);
        if (client_socket < 0)
        {
            perror("Failed to accept client connection");
            continue;
        }
        
        // Check if client is authorized
        char password[20];
        printf("Enter password: ");
        fgets(password, sizeof(password), stdin);
        if (strcmp(password, "password\n") != 0)
        {
            printf("Incorrect password. Closing connection.\n");
            close(client_socket);
            continue;
        }

        // Handle client request
        handle_client_request(client_socket);
        
        // Close socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);
    return 0;
}
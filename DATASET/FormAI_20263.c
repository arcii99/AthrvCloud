//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) 
    {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket created\n");

    // Prepare the sockaddr_in structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // Bind the socket to the specified IP address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    {
        printf("Bind failed\n");
        return 1;
    }
    printf("Bind done\n");

    // Start listening for incoming connections
    listen(server_socket, 3);
    printf("Waiting for incoming connections...\n");

    // Accept incoming connections and handle them
    struct sockaddr_in client_addr;
    int client_socket, client_addr_len;
    char *welcome_message = "Welcome to the server!\n";
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr_len)))
    {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // Send a welcome message to the client
        if (send(client_socket, welcome_message, strlen(welcome_message), 0) < 0)
        {
            printf("Send failed\n");
            return 1;
        }
        printf("Welcome message sent successfully\n");
        
        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);
    
    return 0;
}
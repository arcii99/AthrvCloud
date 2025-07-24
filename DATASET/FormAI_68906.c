//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    int address_len = sizeof(server_address);

    char buffer[1024] = {0};
    char *hello = "Hello from server!";
    
    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections, separate thread for each incoming connection
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections, fork new process for each incoming request
    while ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&address_len)) > 0)
    {
        if (fork() == 0) // new process
        {
            printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            
            // Read incoming message from client
            read(client_fd, buffer, 1024);
            printf("Client: %s\n", buffer);

            // Send response to client
            send(client_fd, hello, strlen(hello), 0);
            printf("Server: %s\n", hello);
            
            // Close connection with client
            close(client_fd);
            exit(EXIT_SUCCESS);
        }
        close(client_fd);
    }
    return 0;
}
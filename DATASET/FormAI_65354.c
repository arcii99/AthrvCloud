//FormAI DATASET v1.0 Category: Networking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main() 
{
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) 
    {
        printf("Socket creation failed...\n");
        exit(0);
    }
    printf("Socket successfully created..\n");

    // Prepare sockaddr_in structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if ((bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address))) != 0) 
    {
        printf("Socket bind failed...\n");
        exit(0);
    }
    printf("Socket successfully bound..\n");

    // Listen for connections
    if ((listen(sockfd, MAX_CLIENTS)) != 0) 
    {
        printf("Listen failed...\n");
        exit(0);
    }
    printf("Server listening..\n");

    // Accept a client connection
    struct sockaddr_in client_address;
    socklen_t address_len = sizeof(client_address);
    int client_sock = accept(sockfd, (struct sockaddr*)&client_address, &address_len);
    if (client_sock < 0) 
    {
        printf("Client accept failed...\n");
        exit(0);
    }
    printf("Client connected..\n");

    // Send a message to the client
    char message[] = "Hello from server!";
    send(client_sock, message, strlen(message), 0);
    printf("Message sent to client..\n");

    // Receive a message from the client
    char buffer[1024] = {0};
    while (1) 
    {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) 
        {
            printf("Client disconnected..\n");
            break;
        }
        printf("Message from client: %s\n", buffer);
    }

    // Close sockets
    close(client_sock);
    close(sockfd);
    printf("Sockets closed..\n");

    return 0;
}
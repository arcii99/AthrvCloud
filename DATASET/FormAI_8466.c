//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 9001
#define MAX_CLIENTS 5
#define MAX_DATA 1024

int main()
{
    // Set up the server socket
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);
    char data[MAX_DATA];

    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket error");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_address.sin_zero), '\0', 8);

    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1)
    {
        perror("Bind error");
        exit(1);
    }

    // Start listening for clients
    if (listen(server_sockfd, MAX_CLIENTS) == -1)
    {
        perror("Listen error");
        exit(1);
    }

    // Main loop
    while (1)
    {
        printf("Waiting for client connection...\n");

        // Accept client connection
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len)) == -1)
        {
            perror("Accept error");
            exit(1);
        }

        printf("Client connected!\n");

        // Read data from client
        int bytes_received = recv(client_sockfd, data, MAX_DATA, 0);

        if (bytes_received == -1)
        {
            perror("Receive error");
            exit(1);
        }

        printf("Received %d bytes from client\n", bytes_received);
        printf("Client sent: %s\n", data);

        // Send response to client
        char response[MAX_DATA] = "Hark! Thou hath spokeneth: ";
        strcat(response, data);

        if (send(client_sockfd, response, strlen(response), 0) == -1)
        {
            perror("Send error");
            exit(1);
        }

        printf("Response sent: %s\n", response);

        // Close client socket
        close(client_sockfd);
        printf("Client disconnected!\n");
    }

    // Close server socket
    close(server_sockfd);

    return 0;
}
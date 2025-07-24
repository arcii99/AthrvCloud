//FormAI DATASET v1.0 Category: Chat server ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8000
#define MAX_PENDING 10

int main()
{
    int sock_fd, client_sock_fd;
    struct sockaddr_in server_addr, client_addr;
    char message[100];

    // Create socket
    if ( (sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("Cannot create socket");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = htons(INADDR_ANY); 
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if ( bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 )
    {
        perror("Bind failed");
        exit(1);
    }

    // Listen for client connections
    if ( listen(sock_fd, MAX_PENDING) < 0 )
    {
        perror("Listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    // Accept client connections and handle messages
    while (1)
    {
        socklen_t client_len = sizeof(client_addr);
        if ( (client_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len)) < 0 )
        {
            perror("Failed to accept client connection");
            exit(1);
        }

        // Receive message from client
        if ( recv(client_sock_fd, message, 100, 0) < 0 )
        {
            perror("Failed to receive message from client");
            exit(1);
        }

        // Handle message
        if ( strcmp(message, "sqrt") == 0 )
        {
            // Send square root of a given number
            char number[10];
            if ( recv(client_sock_fd, number, 10, 0) < 0 )
            {
                perror("Failed to receive number from client");
                exit(1);
            }
            double result = sqrt( atoi(number) );
            char response[50];
            sprintf(response, "The square root of %s is %f", number, result);
            send(client_sock_fd, response, strlen(response), 0);
        }
        else if ( strcmp(message, "log") == 0 )
        {
            // Send natural logarithm of a given number
            char number[10];
            if ( recv(client_sock_fd, number, 10, 0) < 0 )
            {
                perror("Failed to receive number from client");
                exit(1);
            }
            double result = log( atoi(number) );
            char response[50];
            sprintf(response, "The natural logarithm of %s is %f", number, result);
            send(client_sock_fd, response, strlen(response), 0);
        }
        else
        {
            // Send error message to client
            char response[50] = "Invalid command";
            send(client_sock_fd, response, strlen(response), 0);
        }

        // Clean up client connection
        close(client_sock_fd);
    }

    // Clean up socket
    close(sock_fd);

    return 0;
}
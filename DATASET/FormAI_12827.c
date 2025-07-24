//FormAI DATASET v1.0 Category: Socket programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
    // Create server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        perror("Error creating server socket");
        exit(1);
    }

    // Set socket options
    int option = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option)))
    {
        perror("Error setting socket options");
        exit(1);
    }

    // Set server address and port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    // Bind socket to server address
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for client connections
    if (listen(serverSocket, 5) < 0)
    {
        perror("Error listening for client connections");
        exit(1);
    }

    // Accept client connection
    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Send and receive messages from client
    char buffer[1024];
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived < 0)
        {
            perror("Error receiving message from client");
            exit(1);
        }
        else if (bytesReceived == 0)
        {
            // Client disconnected
            printf("Client disconnected\n");
            break;
        }
        else
        {
            // Print message from client
            printf("Received message from client: %s", buffer);

            // Send response to client
            char response[1024] = "Hello from server!\n";
            if (send(clientSocket, response, strlen(response), 0) < 0)
            {
                perror("Error sending message to client");
                exit(1);
            }
        }
    }

    // Close server and client sockets
    close(serverSocket);
    close(clientSocket);

    return 0;
}
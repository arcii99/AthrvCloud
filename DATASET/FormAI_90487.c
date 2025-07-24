//FormAI DATASET v1.0 Category: Simple Web Server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void handleClient(int clientSocket)
{
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int bytesRead = read(clientSocket, buffer, BUFFER_SIZE - 1);
    if (bytesRead < 0)
    {
        perror("Error reading from socket");
        return;
    }

    printf("Received request: %s\n", buffer);

    char response[] = "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/plain\r\n"
                      "\r\n"
                      "Hello, this is a simple web server!\r\n";
    int bytesWritten = write(clientSocket, response, sizeof(response));
    if (bytesWritten < 0)
    {
        perror("Error writing to socket");
        return;
    }

    printf("Sent response: %s\n", response);
}

int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress, clientAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 5) < 0)
    {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d\n", PORT);

    while (1)
    {
        socklen_t clientAddressSize = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);
        if (clientSocket < 0)
        {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        handleClient(clientSocket);

        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}
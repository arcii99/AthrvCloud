//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void) {
    int serverSocket, clientSocket, statusCode, bindCode, listenCode;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressSize;
    char buffer[1024];

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address to 0's and then update values
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    bindCode = bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    if (bindCode == -1) {
        perror("Unable to bind socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    printf("Listening for connections...\n");
    listenCode = listen(serverSocket, 5);  // Allow a queue of up to 5 pending connections
    if (listenCode == -1) {
        perror("Unable to listen for connections");
        exit(EXIT_FAILURE);
    }

    // Accept connection and receive request
    clientAddressSize = sizeof(clientAddress);
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressSize);
    if (clientSocket == -1) {
        perror("Unable to accept connection");
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
    memset(buffer, '\0', sizeof(buffer));
    statusCode = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (statusCode == -1) {
        perror("Unable to receive request");
        exit(EXIT_FAILURE);
    }
    printf("Received request: %s", buffer);

    // Send response to client
    const char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to the Future</h1></body></html>";
    statusCode = send(clientSocket, response, strlen(response), 0);
    if (statusCode == -1) {
        perror("Unable to send response");
    }

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
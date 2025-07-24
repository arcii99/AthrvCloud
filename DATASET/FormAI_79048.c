//FormAI DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Choose port
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(serverAddr.sin_zero), 0, sizeof(serverAddr.sin_zero));

    int bindResult = bind(serverSocket,
        (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (bindResult < 0) {
        perror("Error binding socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listenResult = listen(serverSocket, 10); // Allow 10 connections
    if (listenResult < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and serve requests
    printf("Server running on port 8080\n");
    while (1) {
        struct sockaddr_in clientAddr;
        int clientAddrLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket,
            (struct sockaddr *)&clientAddr, (socklen_t *)&clientAddrLen);
        if (clientSocket < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Receive request
        char buffer[1024] = {0};
        int readResult = read(clientSocket, buffer, 1024);
        if (readResult < 0) {
            perror("Error receiving request");
            close(clientSocket);
            continue;
        }

        // Send response
        char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Hello, World!</h1>";
        int writeResult = write(clientSocket, response, strlen(response));
        if (writeResult < 0) {
            perror("Error sending response");
            close(clientSocket);
            continue;
        }

        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}
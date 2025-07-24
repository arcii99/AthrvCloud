//FormAI DATASET v1.0 Category: Networking ; Style: thoughtful
/* A simple "Echo Server" program in C using sockets */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[BUFFER_SIZE];
    int n;

    // Create the server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Set up the server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(9000);

    // Bind the server socket to the specified address and port
    if (bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding server socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 10) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    printf("Server started on port 9000\n");

    // Accept incoming connections
    socklen_t clientAddrLen = sizeof(clientAddr);
    clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddr, &clientAddrLen);
    if (clientSocket < 0) {
        perror("Error accepting connection");
        return 1;
    }

    printf("Client connected from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

    // Echo messages back to the client
    while ((n = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0) {
        if (send(clientSocket, buffer, n, 0) < 0) {
            perror("Error sending data to client");
            break;
        }
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
    }

    if (n < 0) {
        perror("Error receiving data from client");
    }

    printf("Client disconnected\n");

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
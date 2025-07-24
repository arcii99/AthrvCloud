//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to handle errors
void handleError(char* errorMessage) {
    perror(errorMessage);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressLength;

    // Create a socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        handleError("Failed to create socket");
    }

    // Set up server address configuration
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8888);

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        handleError("Failed to bind socket");
    }

    // Listen for incoming connections
    if (listen(serverSocket, 10) == -1) {
        handleError("Failed to listen on socket");
    }

    printf("Waiting for incoming connections...\n");

    clientAddressLength = sizeof(clientAddress);

    // Accept incoming connection
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLength);
    if (clientSocket == -1) {
        handleError("Failed to accept incoming connection");
    }

    printf("Client connected! Waiting for message...\n");

    char buffer[BUFFER_SIZE];
    int bytesRead;

    // Receive incoming message
    bytesRead = read(clientSocket, buffer, BUFFER_SIZE);
    if (bytesRead == -1) {
        handleError("Failed to receive message from client");
    }

    printf("Message received: %s\n", buffer);

    // Send response message
    char* responseMessage = "Hello from server!";
    if (send(clientSocket, responseMessage, strlen(responseMessage), 0) == -1) {
        handleError("Failed to send message to client");
    }

    printf("Response sent to client!\n");

    // Close server and client socket connections
    close(clientSocket);
    close(serverSocket);

    return 0;
}
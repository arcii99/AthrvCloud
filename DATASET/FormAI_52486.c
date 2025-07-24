//FormAI DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int serverSocket, clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize;

    // Create server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        printf("Error occurred in creating a socket\n");
        exit(1);
    }

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error occurred in binding to address\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        printf("Error occurred in listening for incoming connections\n");
        exit(1);
    }

    printf("Chat server started and listening on port 8080...\n");

    // Accept incoming connections
    addrSize = sizeof(clientAddr);
    clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddr, &addrSize);
    if (clientSocket < 0) {
        printf("Error occurred in accepting incoming connection\n");
        exit(1);
    }

    printf("Client connected\n");

    // Send and receive messages
    while (1) {
        // Receive message from client
        memset(buffer, 0, sizeof(buffer));
        if (recv(clientSocket, buffer, sizeof(buffer), 0) < 0) {
            printf("Error occurred in receiving message from client\n");
            exit(1);
        }

        printf("Client: %s\n", buffer);

        // Send message to client
        memset(buffer, 0, sizeof(buffer));
        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (send(clientSocket, buffer, strlen(buffer), 0) < 0) {
            printf("Error occurred in sending message to client\n");
            exit(1);
        }
    }

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
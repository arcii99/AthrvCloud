//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    // Create the TCP Socket
    int listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // Define the socket address
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(5000);
    
    // Bind the socket to the address
    int bindStatus = bind(listenSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
    if (bindStatus < 0) {
        printf("Error binding socket to address.\n");
        return 1;
    }
    
    // Start listening for incoming connections
    int listenStatus = listen(listenSocket, 5);
    if (listenStatus < 0) {
        printf("Error starting to listen for incoming connections.\n");
        return 1;
    }
    
    printf("Server started listening at port 5000.\n");
    
    while (1) {
        // Accept incoming connection
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocket = accept(listenSocket, (struct sockaddr*) &clientAddress, &clientAddressLength);
        if (clientSocket < 0) {
            printf("Error accepting incoming connection.\n");
            continue;
        }
        printf("Incoming connection accepted from %s:%d.\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
        
        // Receive data from client
        char buffer[MAX_BUFFER_SIZE];
        int receiveSize = recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0);
        if (receiveSize < 0) {
            printf("Error receiving data from client.\n");
            continue;
        }
        printf("Received data from client: %s\n", buffer);
        
        // Send response to client
        char* responseMessage = "Hello from server!";
        int sendSize = send(clientSocket, responseMessage, strlen(responseMessage), 0);
        if (sendSize < 0) {
            printf("Error sending response to client.\n");
            continue;
        }
        printf("Response sent to client.\n");
        
        // Close the connection
        close(clientSocket);
    }
    
    // Close the listening socket
    close(listenSocket);
    
    return 0;
}
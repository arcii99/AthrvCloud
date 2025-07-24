//FormAI DATASET v1.0 Category: Networking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    char buffer[MAX_BUFFER_SIZE] = {0};
    int addressLength = sizeof(serverAddress);

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        return -1;
    }

    memset(&serverAddress, 0, addressLength);

    // Set server address structure
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, addressLength) < 0) {
        printf("Error binding socket\n");
        return -1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        printf("Error listening on socket\n");
        return -1;
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connection
    if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t*)&addressLength)) < 0) {
        printf("Error accepting connection\n");
        return -1;
    }

    char ipAddress[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddress.sin_addr, ipAddress, INET_ADDRSTRLEN);
    printf("Client connected from %s:%d\n", ipAddress, ntohs(clientAddress.sin_port));

    while (1) {
        // Read data from client
        int bytesReceived = read(clientSocket, buffer, MAX_BUFFER_SIZE);
        if (bytesReceived < 0) {
            printf("Error reading from client\n");
            break;
        }

        if (bytesReceived == 0) {
            printf("Client disconnected\n");
            break;
        }

        // Print received data
        printf("Received %d bytes from client: %s\n", bytesReceived, buffer);

        // Send response to client
        char response[MAX_BUFFER_SIZE] = "Response received!";
        int bytesSent = send(clientSocket, response, strlen(response), 0);
        if (bytesSent < 0) {
            printf("Error sending data to client\n");
            break;
        }
    }

    // Close client socket
    close(clientSocket);

    // Close server socket
    close(serverSocket);

    return 0;
}
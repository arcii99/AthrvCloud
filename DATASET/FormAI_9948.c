//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&serverAddr, '0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind socket to address
    if (bind(serverSocket, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d\n", SERVER_PORT);

    while (1) {
        socklen_t clientAddrLen = sizeof(clientAddr);

        // Accept connection from client
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        // Read request from client
        memset(buffer, 0, BUFFER_SIZE);
        read(clientSocket, buffer, BUFFER_SIZE);
        printf("Request received:\n%s\n", buffer);

        // Modify request
        char newBuffer[BUFFER_SIZE];
        strcpy(newBuffer, buffer);
        char *pos = strstr(newBuffer, "User-Agent:");
        if (pos != NULL) {
            strcpy(pos, "User-Agent: Mozilla/5.0");
        }

        printf("Modified request:\n%s\n", newBuffer);

        // Connect to destination server
        int destSocket;
        if ((destSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        char *hostPos = strstr(buffer, "Host:");
        if (hostPos == NULL) {
            perror("Invalid request");
            exit(EXIT_FAILURE);
        }

        char *endPos = strstr(hostPos, "\r\n");
        char *host = (char *)malloc(endPos - hostPos - 6);
        strncpy(host, hostPos + 6, endPos - hostPos - 6);
        host[endPos - hostPos - 6] = '\0';

        struct sockaddr_in destAddr;
        memset(&destAddr, '0', sizeof(destAddr));
        destAddr.sin_family = AF_INET;
        destAddr.sin_port = htons(80);
        if (inet_pton(AF_INET, host, &destAddr.sin_addr) <= 0) {
            perror("Invalid address");
            exit(EXIT_FAILURE);
        }

        if (connect(destSocket, (const struct sockaddr *)&destAddr, sizeof(destAddr)) < 0) {
            perror("Connection failed");
        }

        // Send modified request to destination server
        write(destSocket, newBuffer, strlen(newBuffer));

        // Read response from destination server
        memset(buffer, 0, BUFFER_SIZE);
        while (read(destSocket, buffer, BUFFER_SIZE) > 0) {
            // Send response back to client
            write(clientSocket, buffer, strlen(buffer));
            printf("Response sent:\n%s\n", buffer);
            memset(buffer, 0, BUFFER_SIZE);
        }

        // Close sockets
        close(destSocket);
        close(clientSocket);
        free(host);
    }

    close(serverSocket);
    return 0;
}
//FormAI DATASET v1.0 Category: Simple Web Server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER 1024

typedef struct Request {
    char* method;
    char* path;
} Request;

void handleRequest(int clientSocket) {
    char* responseBuffer = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html><html><body><h1>Welcome to the Puzzling Server!</h1></body></html>";

    char requestBuffer[MAX_BUFFER];
    int readStatus = read(clientSocket, requestBuffer, MAX_BUFFER);

    if (readStatus > 0) {
        char* tokenSpace = strtok(requestBuffer, " ");
        Request request = {tokenSpace, strtok(NULL, " ")};
        printf("Received Request: %s %s\n", request.method, request.path);

        if (strcmp(request.method, "GET") == 0) {
            write(clientSocket, responseBuffer, strlen(responseBuffer));
        } else {
            char* errorResponse = "HTTP/1.1 405 Method Not Allowed\nContent-Length: 0\n\n";
            write(clientSocket, errorResponse, strlen(errorResponse));
        }
    }

    close(clientSocket);
}

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        printf("Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 3) < 0) {
        printf("Failed to start listening on socket\n");
        exit(EXIT_FAILURE);
    }
    printf("Server running at http://localhost:%d/\n", PORT);

    while (1) {
        int clientAddressLength = sizeof(clientAddress);
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t*)&clientAddressLength)) < 0) {
            printf("Failed to accept incoming connection\n");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
        handleRequest(clientSocket);
    }

    return 0;
}
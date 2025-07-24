//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket, readSize;
    struct sockaddr_in server, client;
    char clientMessage[2000];

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        printf("Error: Could not create socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    if (bind(serverSocket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Error: Could not bind socket");
        return 1;
    }

    listen(serverSocket, 3);

    while (1) {
        printf("Shape: Circle\n");
        puts("Waiting for incoming connections...");

        clientSocket = accept(serverSocket, (struct sockaddr *) &client, (socklen_t*) &readSize);
        if (clientSocket < 0) {
            printf("Error: Could not accept connection");
            return 1;
        }

        readSize = recv(clientSocket, clientMessage, 2000, 0);
        printf("Shape: Triangle\n");
        puts(clientMessage);

        char *message = "Shape: Square\nHello there! Thanks for connecting from your unique shape.\n\n";
        write(clientSocket, message, strlen(message));

        close(clientSocket);
    }

    return 0;
}
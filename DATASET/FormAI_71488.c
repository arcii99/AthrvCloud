//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
/*
    C Networking Example Program
    Author: John Doe
    
    This program establishes a TCP server socket on port 8000 and listens
    for incoming connections from clients. Upon receiving a connection request,
    the server sends a welcome message to the client and waits for the client
    to send a message. The message is then echoed back to the client.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket;
    int opt = 1;
    struct sockaddr_in serverAddress, clientAddress;
    char buffer[BUFFER_SIZE];

    // create a TCP socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // initialize the server address struct
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(serverSocket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        socklen_t clientAddressLength = sizeof(clientAddress);

        // accept incoming connection request
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);
        if (clientSocket < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));

        // send welcome message to the client
        char welcomeMessage[] = "Welcome to the server!";
        send(clientSocket, welcomeMessage, strlen(welcomeMessage), 0);

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            // read message from client
            int bytesRead = recv(clientSocket, buffer, BUFFER_SIZE, 0);
            if (bytesRead < 0) {
                perror("recv failed");
                exit(EXIT_FAILURE);
            }

            if (bytesRead == 0) {
                printf("Client disconnected: %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
                break;
            }

            printf("Received message from client: %s\n", buffer);

            // echo message back to client
            send(clientSocket, buffer, bytesRead, 0);
        }
    }

    close(serverSocket);

    return 0;
}
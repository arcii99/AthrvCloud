//FormAI DATASET v1.0 Category: Socket programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080 // Port number to listen to

void* handleConnection(void* arg) {
    int clientSocket = *(int*) arg;
    char buffer[1024] = {0};
    char* message = "Hello from Server!";
    int valRead;

    valRead = read(clientSocket, buffer, 1024);
    printf("Received Message: %s\n", buffer);
    send(clientSocket, message, strlen(message), 0);
    printf("Hello message sent.\n");

    close(clientSocket); 
    pthread_exit(NULL); 
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    pthread_t threadID;

    // Create a socket for the server
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    // Configure the server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Binding failed.");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 3) < 0) {
        perror("Listening failed.");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        unsigned int clientLength = sizeof(clientAddr);
        // Accept a connection from the client
        clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddr, &clientLength);
        if (clientSocket < 0) {
            perror("Connection accepting failed.");
            exit(EXIT_FAILURE);
        }

        printf("New connection from: %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

        if (pthread_create(&threadID, NULL, handleConnection, (void*) &clientSocket) < 0) {
            perror("Thread creation failed.");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
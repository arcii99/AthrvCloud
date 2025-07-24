//FormAI DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10

void handleConnection(int clientSocket) {
    char buffer[256];
    int bytesRead;

    while (1) {
        bzero(buffer, 256);
        bytesRead = read(clientSocket, buffer, 255);

        if (bytesRead < 0) {
            perror("Error reading from socket");
            break;
        }

        printf("Message received: %s\n", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            close(clientSocket);
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char *message = "Welcome! You have connected to the chat server.";

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Chat server is running on port %d...\n", PORT);

    while (1) {
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&address,
                                    (socklen_t*)&addrlen)) < 0) {
            perror("Error accepting new connection");
            exit(EXIT_FAILURE);
        }

        send(clientSocket, message, strlen(message), 0);

        pid_t pid = fork();

        if (pid < 0) {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            close(serverSocket);
            handleConnection(clientSocket);
            exit(0);
        } else {
            close(clientSocket);
        }
    }

    return 0;
}
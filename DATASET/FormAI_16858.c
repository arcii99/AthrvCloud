//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 5

int clients[MAX_CLIENTS]; // array to keep track of connected clients

// function to handle client requests in separate threads
void *handleClient(void *arg) {
    int clientSocket = *((int *) arg);
    char buffer[1024] = {0};
    while (1) {
        // read client request and handle it
        int valread = read(clientSocket, buffer, 1024);
        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Received message: %s", buffer);
        // send response to client
        char *response = "Server response";
        send(clientSocket, response, strlen(response), 0);
        memset(buffer, 0, 1024);
    }
    // remove client from clients array
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == clientSocket) {
            clients[i] = 0;
            break;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket, opt = 1;
    struct sockaddr_in serverAddr, clientAddr;
    pthread_t tid;

    // create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    // set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    // bind socket to port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d\n", PORT);
    // listen for client connections
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    while (1) {
        int addrlen = sizeof(clientAddr);
        // accept client connection
        if ((clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("New client connected: %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        // add client to clients array
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == 0) {
                clients[i] = clientSocket;
                break;
            }
        }
        // start new thread to handle client request
        if (pthread_create(&tid, NULL, handleClient, (void *)&clientSocket) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
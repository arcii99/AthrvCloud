//FormAI DATASET v1.0 Category: Client Server Application ; Style: creative
/*
 * This is a unique C Client Server Application example program that
 * allows multiple clients to connect to the server and send messages
 * to each other. The program uses multithreading to handle multiple
 * client connections at once.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Struct to hold client data
typedef struct {
    int socket;
    struct sockaddr_in address;
} ClientData;

// Array of client data
ClientData clients[MAX_CLIENTS];

// Mutex for accessing client data array
pthread_mutex_t clientsMutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handleClient(void *data) {
    ClientData client = *(ClientData *)data;
    char buffer[BUFFER_SIZE];
    int bytesReceived;

    // Send welcome message to the client
    char welcomeMessage[] = "Welcome to the chat room!\n";
    send(client.socket, welcomeMessage, strlen(welcomeMessage), 0);

    // Loop to receive messages from the client
    while ((bytesReceived = recv(client.socket, buffer, BUFFER_SIZE, 0)) > 0) {
        // Null-terminate the received message
        buffer[bytesReceived] = '\0';

        // Print the received message to the server console
        printf("Received message: %s\n", buffer);

        // Loop through all clients and send the message to each one
        pthread_mutex_lock(&clientsMutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0 && clients[i].socket != client.socket) {
                send(clients[i].socket, buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&clientsMutex);
    }

    // If the client disconnected or there was an error receiving data,
    // close the client socket and remove the client from the array
    pthread_mutex_lock(&clientsMutex);
    close(client.socket);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket == client.socket) {
            clients[i].socket = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clientsMutex);
    printf("Client disconnected: %s:%d\n", inet_ntoa(client.address.sin_addr), client.address.sin_port);

    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int serverSocket, clientSocket, bytesReceived;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientAddressLength = sizeof(clientAddress);
    pthread_t clientThreads[MAX_CLIENTS];
    int threadCounter = 0;

    // Create the server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Bind the server socket to a local address and port
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8888);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Loop to accept incoming connections and spawn threads to handle clients
    while (1) {
        // Accept the incoming connection
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLength);
        if (clientSocket < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Add the new client to the client data array
        pthread_mutex_lock(&clientsMutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket == 0) {
                clients[i].socket = clientSocket;
                clients[i].address = clientAddress;
                break;
            }
        }
        pthread_mutex_unlock(&clientsMutex);

        // Spawn a thread to handle the client
        if (pthread_create(&clientThreads[threadCounter++], NULL, handleClient, &clients[threadCounter-1]) != 0) {
            perror("Error creating client thread");
            exit(1);
        }

        // Check if we've reached the maximum number of clients
        if (threadCounter >= MAX_CLIENTS) {
            printf("Maximum number of clients reached, closing server socket\n");
            close(serverSocket);
            exit(0);
        }
    }

    return 0;
}
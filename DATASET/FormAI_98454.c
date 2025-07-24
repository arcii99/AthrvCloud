//FormAI DATASET v1.0 Category: Client Server Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAXCLIENTS 10
#define MAXBUFFERSIZE 1024

// Struct to hold information of each client
typedef struct {
    int socket;
    struct sockaddr_in address;
    char name[20];
} Client;

// Array to hold information of each connected client
Client clients[MAXCLIENTS];
// Counter for number of connected clients
int numClients = 0;

// Forward declarations
void* handleClient(void* clientSocket);
bool isValidName(const char* name);

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    int opt = 1;
    int addressLength;
    pthread_t threadId;

    // Creating server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    // Setting server socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    // Setting server address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(5000);
    // Binding server socket to the server address
    if (bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }
    // Listening for client connections
    if (listen(serverSocket, 3) < 0) {
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running and listening for clients...\n");

    while (true) {
        addressLength = sizeof(clientAddress);
        // Accepting client connection
        if ((clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, (socklen_t*) &addressLength)) < 0 ) {
            perror("Client connection failed");
            exit(EXIT_FAILURE);
        }
        // Checking if maximum number of clients is reached
        if (numClients == MAXCLIENTS) {
            printf("Maximum number of clients reached. Connection rejected.\n");
            close(clientSocket);
            continue;
        }
        // Creating new thread to handle client
        if (pthread_create(&threadId, NULL, handleClient, (void*) &clientSocket)) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void* handleClient(void* arg) {
    int clientSocket = *(int*) arg;
    char buffer[MAXBUFFERSIZE] = { 0 };
    char name[20] = { 0 };
    int readBytes;

    // Receiving client name
    if ((readBytes = recv(clientSocket, name, sizeof(name), 0)) < 0) {
        perror("Name receiving failed");
        close(clientSocket);
        return NULL;
    }
    name[strcspn(name, "\n")] = 0; // Removing trailing newline character
    // Validating client name
    if (!isValidName(name)) {
        printf("Client %s is invalid. Connection rejected.\n", name);
        close(clientSocket);
        return NULL;
    }
    printf("Client %s connected.\n", name);
    // Storing client information
    clients[numClients].socket = clientSocket;
    clients[numClients].address = *(struct sockaddr_in*) &arg;
    strcpy(clients[numClients].name, name);
    numClients++;

    // Sending welcome message to client
    sprintf(buffer, "Welcome to the chat room, %s!\n", name);
    send(clientSocket, buffer, strlen(buffer), 0);
    // Notifying other clients of new client joining
    sprintf(buffer, "%s has joined the chat room.\n", name);
    for (int i = 0; i < numClients; i++) {
        if (clients[i].socket != clientSocket) {
            send(clients[i].socket, buffer, strlen(buffer), 0);
        }
    }

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        // Receiving message from client
        if ((readBytes = recv(clientSocket, buffer, sizeof(buffer), 0)) < 0) {
            perror("Message receiving failed");
            close(clientSocket);
            return NULL;
        }
        // Checking if client disconnected
        if (readBytes == 0) {
            printf("Client %s disconnected.\n", name);
            // Removing client from array
            for (int i = 0; i < numClients; i++) {
                if (clients[i].socket == clientSocket) {
                    for (int j = i; j < numClients - 1; j++) {
                        clients[j] = clients[j + 1];
                    }
                    numClients--;
                    break;
                }
            }
            // Notifying other clients of client disconnection
            sprintf(buffer, "%s has left the chat room.\n", name);
            for (int i = 0; i < numClients; i++) {
                send(clients[i].socket, buffer, strlen(buffer), 0);
            }
            close(clientSocket);
            return NULL;
        }
        buffer[strcspn(buffer, "\n")] = 0; // Removing trailing newline character
        sprintf(buffer, "%s: %s\n", name, buffer);
        // Broadcasting message to all clients except sender
        for (int i = 0; i < numClients; i++) {
            if (clients[i].socket != clientSocket) {
                send(clients[i].socket, buffer, strlen(buffer), 0);
            }
        }
    }

    return NULL;
}

bool isValidName(const char* name) {
    // Checking if name is empty
    if (strlen(name) == 0) {
        return false;
    }
    // Checking if name contains only alphabetic characters and spaces
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) {
            return false;
        }
    }
    // Checking if name is already taken
    for (int i = 0; i < numClients; i++) {
        if (strcmp(clients[i].name, name) == 0) {
            return false;
        }
    }
    return true;
}
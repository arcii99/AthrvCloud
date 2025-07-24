//FormAI DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

//global variables
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

//function declarations
void handle_client_messages(int client_socket);
void broadcast_message(char* message, int sender_socket);

int main() {
    //initialize server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create server socket");
        exit(1);
    }

    //initialize server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    //bind server socket to server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket");
        exit(1);
    }

    //listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Failed to listen for incoming connections");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    //start accepting connections
    while(1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            exit(1);
        }

        //add new client to client sockets
        if (num_clients < MAX_CLIENTS) {
            client_sockets[num_clients] = client_socket;
            num_clients++;
            printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            handle_client_messages(client_socket);
        }
        else {
            printf("Maximum number of clients reached\n");
            close(client_socket);
        }
    }

    return 0;
}

void handle_client_messages(int client_socket) {
    char buffer[BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int message_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (message_size < 0) {
            perror("Failed to receive message from client");
            exit(1);
        }
        else if (message_size == 0) {
            printf("Client disconnected\n");
            close(client_socket);
            break;
        }
        printf("Received message from client: %s\n", buffer);
        broadcast_message(buffer, client_socket);
    }
}

void broadcast_message(char* message, int sender_socket) {
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == sender_socket) {
            continue;
        }
        if (send(client_sockets[i], message, strlen(message), 0) < 0) {
            perror("Failed to send message to client");
            exit(1);
        }
    }
}
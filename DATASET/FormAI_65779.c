//FormAI DATASET v1.0 Category: Chat server ; Style: energetic
// Energized Chat Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 30

int server_socket;
int clients[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *args) {
    int client_socket = *(int*) args;
    char buffer[1024] = {0};
    int read_val;
    while ((read_val = read(client_socket, buffer, 1024))) {
        buffer[read_val] = '\0';
        printf("Received Message: %s\n", buffer);
        for (int i = 0; i < num_clients; i++) {
            if (client_socket != clients[i]) {
                write(clients[i], buffer, strlen(buffer));
            }
        }
    }
    printf("Client Disconnected!\n");
    for (int i = 0; i < num_clients; i++) {
        if (clients[i] == client_socket) {
            clients[i] = -1;
        }
    }
    pthread_exit(0);
}

int main() {
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *msg = "Welcome to the Energized Chat Server!\n";

    // Create socket and bind it to port
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: Failed to create socket!\n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Error: Failed to bind to port %d\n", PORT);
        return -1;
    }

    listen(server_socket, MAX_CLIENTS);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_socket < 0) {
            printf("Error: Failed to accept client connection!\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            char *msg = "Reached maximum number of clients! Please try again later.\n";
            write(client_socket, msg, strlen(msg));
            continue;
        }
        clients[num_clients++] = client_socket;
        write(client_socket, msg, strlen(msg));

        pthread_create(&threads[num_clients-1], NULL, handle_client, &client_socket);
    } 

    return 0; 
}
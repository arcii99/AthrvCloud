//FormAI DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void* handle_client(void* arg);

int main(int argc, char* argv[]) {

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    pthread_t tid;
    int i = 0;

    // Step 1 - Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize server address struct
    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    // Step 2 - Bind the socket
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Step 3 - Listen for connections
    listen(server_socket, MAX_CLIENTS);

    printf("Server started listening on port %d\n", ntohs(server_address.sin_port));

    while(1) {
        // Step 4 - Accept the client connection
        int client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);

        // Print client details
        printf("Client %s:%d connected\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Step 5 - Create a thread to handle the client
        pthread_create(&tid, NULL, handle_client, &client_socket);

        // Detach the thread
        pthread_detach(tid);

        // Ensure that there are no more than MAX_CLIENTS clients connected
        i++;
        if(i >= MAX_CLIENTS) {
            printf("Maximum number of clients exceeded\n");
            break;
        }
    }

    // Step 6 - Close the socket
    close(server_socket);

    return 0;
}

void* handle_client(void* arg) {

    int client_socket = *((int*) arg);
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while(1) {
        // Step 7 - Receive message from client
        memset(buffer, '\0', sizeof(buffer));
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if(bytes_received == -1) {
            printf("Error receiving message\n");
            break;
        } else if(bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        }

        // Step 8 - Send message back to client
        if(send(client_socket, buffer, strlen(buffer), 0) == -1) {
            printf("Error sending message\n");
            break;
        }
    }

    // Step 9 - Close the client socket
    close(client_socket);
    pthread_exit(0);
}
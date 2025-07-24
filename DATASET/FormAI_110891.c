//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 3000 // Server port number
#define MESSAGE_SIZE 1024 // Maximum message size

int main(){
    int server_socket, client_socket; // Server and client socket file descriptors
    struct sockaddr_in server_addr, client_addr; // Server and client socket address structures
    char message[MESSAGE_SIZE]; // A buffer for incoming messages
    socklen_t sin_size; // Length of client socket address

    // Creating a socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Setting up the server socket address structure
    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Binding the server socket to the server address structure
    bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));

    // Listening to incoming connections
    listen(server_socket, 5);

    printf("Server is running on port %d...\n", SERVER_PORT);

    while(1){
        // Accepting incoming connections
        sin_size = sizeof(struct sockaddr_in);
        client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &sin_size);

        // Reading incoming messages
        while(recv(client_socket, message, MESSAGE_SIZE, 0) > 0){
            printf("Received message from %s:%d: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), message);
            
            // Sending back the same message
            send(client_socket, message, strlen(message), 0);
        
            memset(&message, '\0', sizeof(message)); // Clearing the message buffer
        }

        printf("Client disconnected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Closing the client socket
        close(client_socket);
    }

    // Closing the server socket
    close(server_socket);
    return 0;
}
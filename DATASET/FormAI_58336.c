//FormAI DATASET v1.0 Category: Client Server Application ; Style: optimized
/* This program demonstrates a client-server application using sockets */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345
#define MAX_MESSAGE_LENGTH 1024

// define message structure
typedef struct {
    char message[MAX_MESSAGE_LENGTH];
} message_t;

int main(void) {
    // declare necessary variables
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);
    message_t incoming_message = {""};
    message_t outgoing_message = {""};
    
    // create server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }
    
    // set server socket address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // bind server socket to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_sock, 1) == -1) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    // accept incoming connection
    if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr_len)) == -1) {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }
    
    // receive incoming message from client
    if (recv(client_sock, incoming_message.message, MAX_MESSAGE_LENGTH, 0) == -1) {
        perror("Failed to receive incoming message from client");
        exit(EXIT_FAILURE);
    }
    
    // print incoming message from client
    printf("Client: %s\n", incoming_message.message);

    // prepare outgoing message to client
    sprintf(outgoing_message.message, "Hello client, I received \"%s\"", incoming_message.message);
    
    // send outgoing message to client
    if (send(client_sock, outgoing_message.message, strlen(outgoing_message.message), 0) == -1) {
        perror("Failed to send outgoing message to client");
        exit(EXIT_FAILURE);
    }
    
    // close client and server sockets
    close(client_sock);
    close(server_sock);

    return 0;
}
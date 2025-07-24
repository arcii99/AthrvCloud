//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define PORT 4080
#define MAX_MSG_LENGTH 1024

int main(){

    int server_socket, new_socket, length, n;
    struct sockaddr_in server_address, client_address;
    char server_message[MAX_MSG_LENGTH], buffer[MAX_MSG_LENGTH];

    printf("\nStarting the TCP/IP server...\n");

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0){
        printf("Error creating server socket!");
        exit(1);
    }

    // Configure the server address struct
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0){
        printf("Error binding server socket!");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    length = sizeof(client_address);

    // Wait for a client to connect
    printf("Waiting for client connection...\n");
    new_socket = accept(server_socket, (struct sockaddr *) &client_address, &length);
    if (new_socket < 0){
        printf("Error accepting client connection!");
        exit(1);
    }

    // Connection established, request for message from client
    bzero(buffer, MAX_MSG_LENGTH);
    printf("Waiting for message from client...\n");
    n = read(new_socket, buffer, MAX_MSG_LENGTH);
    if (n < 0){
        printf("Error reading from socket!");
        exit(1);
    }

    // Print the received message
    printf("Received message from client: %s\n", buffer);

    // Send response to the client
    bzero(server_message, MAX_MSG_LENGTH);
    strcpy(server_message, "Server received your message!");
    n = write(new_socket, server_message, strlen(server_message));
    if (n < 0){
        printf("Error writing to socket!");
        exit(1);
    }

    // Close the sockets
    close(new_socket);
    close(server_socket);

    return 0;
}
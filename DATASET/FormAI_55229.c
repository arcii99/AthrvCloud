//FormAI DATASET v1.0 Category: Networking ; Style: innovative
/*
 * Program: ChatBot
 * Description: A simple client-server chat program in C
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFSIZE 1024
#define PORT 8080

void *receive_message(void *sockfd) {
    int client_socket = *(int*) sockfd;
    char message[BUFSIZE];
    while (1) {
        memset(message, 0, BUFSIZE);
        recv(client_socket, message, BUFSIZE, 0);
        fputs(message, stdout);
    }
}

int main(int argc, char *argv[]) {

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t tid;

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }
    printf("Server socket created\n");

    // Bind the socket to a specific IP and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }
    printf("Socket bind successful\n");

    // Start listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }
    printf("Server listening on port %d\n", PORT);

    socklen_t client_address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_len);
    if (client_socket < 0) {
        printf("Error accepting connection\n");
        return 1;
    }
    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Start a thread to receive messages from the client
    pthread_create(&tid, NULL, receive_message, &client_socket);

    char message[BUFSIZE];
    while (1) {
        memset(message, 0, BUFSIZE);
        fgets(message, BUFSIZE, stdin);
        send(client_socket, message, strlen(message), 0);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}
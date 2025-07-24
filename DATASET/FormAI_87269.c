//FormAI DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8080);

    // Bind server address to socket
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, 5);

    printf("Server is running at %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

    // Accept client connection
    socklen_t client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);

    printf("Client is connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Send welcome message to client
    char welcome_msg[100] = "Welcome to the server!";
    send(client_socket, welcome_msg, strlen(welcome_msg), 0);

    // Receive message from client
    char client_msg[100];
    recv(client_socket, client_msg, sizeof(client_msg), 0);

    printf("Client >> %s\n", client_msg);

    // Send message to client
    char server_msg[100] = "Hello client!";
    send(client_socket, server_msg, strlen(server_msg), 0);

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
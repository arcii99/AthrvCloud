//FormAI DATASET v1.0 Category: Client Server Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[256];

    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind server socket to address
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // listen for incoming connections
    listen(server_socket, 5);
    printf("Waiting for incoming connections...\n");

    // accept client connection
    socklen_t client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
    printf("Client connected\n");

    // receive message from client
    recv(client_socket, &message, sizeof(message), 0);
    printf("Received message from client: %s\n", message);

    // send message to client
    strcpy(message, "Hello from server!");
    send(client_socket, &message, sizeof(message), 0);
    printf("Sent message to client: %s\n", message);

    // close sockets
    close(client_socket);
    close(server_socket);
    return 0;
}
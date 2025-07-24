//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[1024];

    memset(&server_address, 0, sizeof(server_address));
    memset(&client_address, 0, sizeof(client_address));
    memset(&buffer, 0, sizeof(buffer));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Error setting socket to listen");
        exit(EXIT_FAILURE);
    }

    socklen_t client_address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);

    if (client_socket < 0) {
        perror("Error accepting client connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with %s:%d\n", 
        inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    ssize_t numBytes = recv(client_socket, buffer, sizeof(buffer), 0);

    if (numBytes < 0) {
        perror("Error receiving client message");
        exit(EXIT_FAILURE);
    }

    printf("Message received from client: %s\n", buffer);

    char response[] = "Message received";
    send(client_socket, response, sizeof(response), 0);

    close(client_socket);
    close(server_socket);

    return 0;
}
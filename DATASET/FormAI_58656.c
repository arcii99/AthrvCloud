//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define REQUEST_HEADER "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n"

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        fprintf(stderr, "Could not create socket. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    if (connect(client_socket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        fprintf(stderr, "Could not connect to server. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    if (send(client_socket, REQUEST_HEADER, sizeof(REQUEST_HEADER), 0) < 0) {
        fprintf(stderr, "Could not send request to server. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    char server_response[1024];
    int response_length;
    while ((response_length = recv(client_socket, &server_response, sizeof(server_response), 0)) > 0) {
        printf("%.*s", response_length, server_response);
    }

    return 0;
}
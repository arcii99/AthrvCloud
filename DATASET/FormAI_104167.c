//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("Error: invalid address\n");
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    char request[MAX_BUFFER_SIZE];
    sprintf(request, "GET /index.html HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");

    if (send(client_socket, request, strlen(request), 0) < 0) {
        printf("Error: failed to send request\n");
        exit(EXIT_FAILURE);
    }

    char response[MAX_BUFFER_SIZE];
    ssize_t response_length;

    while ((response_length = recv(client_socket, response, MAX_BUFFER_SIZE, 0)) > 0) {
        fwrite(response, 1, response_length, stdout);
    }

    close(client_socket);
    exit(EXIT_SUCCESS);
}
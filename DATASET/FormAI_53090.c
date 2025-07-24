//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        printf("Error while creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("216.58.194.174");

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    char request[256];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", "www.google.com");

    if (send(client_socket, request, strlen(request), 0) < 0) {
        printf("Failed to send data\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    bool is_body = false;

    while (true) {
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received == 0) {
            break;
        }

        for (int i = 0; i < bytes_received; ++i) {
            if (is_body) {
                printf("%c", buffer[i]);
            } else if (buffer[i] == '\r' || buffer[i] == '\n') {
                is_body = true;
            }
        }
    }

    close(client_socket);

    return 0;
}
//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 10000

int main(int argc, char *argv[]) {

    // Check if command line arguments are valid
    if (argc != 2) {
        printf("Usage: %s [url]\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Setup server address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(80); // HTTP port
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        printf("Invalid address: %s\n", argv[1]);
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Create HTTP request
    char request[MAX_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);

    // Send HTTP request to server
    int sent = send(sock, request, strlen(request), 0);
    if (sent < 0) {
        perror("send() failed");
        return 1;
    }

    // Receive HTTP response from server
    char response[MAX_SIZE];
    int received = recv(sock, response, MAX_SIZE, 0);
    if (received < 0) {
        perror("recv() failed");
        return 1;
    }

    // Print HTTP response
    printf("%.*s", received, response);

    // Close socket
    close(sock);

    return 0;
}
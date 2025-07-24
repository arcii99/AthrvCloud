//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 2048

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[MAX_SIZE], server_reply[MAX_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    // Set server details
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to server\n");

    // Construct HTTP message
    char* host = "example.com";
    char* path = "/";
    sprintf(message, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    // Send HTTP request to server
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Send failed\n");
        return 1;
    }

    // Receive HTTP response from server
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        printf("Receive failed\n");
        return 1;
    }
    printf("Server reply:\n%s\n", server_reply);

    // Close socket
    close(sock);

    return 0;
}
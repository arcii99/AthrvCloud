//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *message, server_reply[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: Failed to create socket.");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error: Failed to connect to server.");
        return 1;
    }

    // Send HTTP request
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Error: Failed to send HTTP request.");
        return 1;
    }

    // Receive HTTP response
    if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) {
        perror("Error: Failed to receive HTTP response.");
        return 1;
    }

    // Output response message
    printf("HTTP Response:\n%s\n", server_reply);

    // Close the socket
    close(sock);
    return 0;
}
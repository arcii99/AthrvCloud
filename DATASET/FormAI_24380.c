//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *message;
    char server_reply[2000];
    int bytes_received = 0;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Set server address data
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection failed");
        return 1;
    }

    // Send the HTTP request to the server
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error: Failed to send request");
        return 1;
    }

    // Receive server response
    while ((bytes_received = recv(sock, server_reply, 2000, 0)) > 0) {
        printf("%.*s", bytes_received, server_reply);
    }

    if (bytes_received < 0) {
        printf("Error: Failed to receive response");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}
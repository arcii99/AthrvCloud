//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket.\n");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Failed to connect to server.\n");
        exit(1);
    }

    char *message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Failed to send message.\n");
        exit(1);
    }

    char response[4096];
    if (recv(sock, response, sizeof(response), 0) < 0) {
        printf("Failed to receive response.\n");
        exit(1);
    }

    printf("Response received: %s\n", response);

    return 0;
}
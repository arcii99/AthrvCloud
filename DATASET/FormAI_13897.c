//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LEN 1024

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr.s_addr = inet_addr("216.58.194.174"); // Google IP

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char* message = "GET / HTTP/1.0\r\n\r\n"; // HTTP GET request
    if (write(sock, message, strlen(message)) == -1) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    char response[MAX_LEN];
    memset(response, 0, MAX_LEN);

    if (read(sock, response, MAX_LEN - 1) == -1) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", response);

    close(sock);

    exit(EXIT_SUCCESS);
}
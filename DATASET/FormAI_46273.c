//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    char *host = "www.example.com";
    int port = 80;

    // Creating socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Unable to create socket");
        exit(1);
    }

    // Creating server information
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Unable to connect to server");
        exit(1);
    }

    // Sending HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0)
    {
        perror("Unable to send HTTP request");
        exit(1);
    }

    // Receiving HTTP response
    char response[2048];
    if (recv(sock, response, sizeof(response), 0) < 0)
    {
        perror("Unable to receive HTTP response");
        exit(1);
    }

    // Printing HTTP response
    printf("HTTP Response:\n%s", response);

    // Closing socket
    close(sock);

    return 0;
}
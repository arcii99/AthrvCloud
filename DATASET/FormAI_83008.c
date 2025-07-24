//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 80
#define REQUEST_SIZE 500

int main() {
    // Create a socket for TCP connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket.\n");
        return -1;
    }

    // Specify server address and port to connect to
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to the server.\n");
        return -1;
    }

    // Send HTTP request to the server
    char request[REQUEST_SIZE];
    memset(request, 0, sizeof(request));
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Failed to send HTTP request to the server.\n");
        return -1;
    }

    // Receive HTTP response from the server
    char response[1024];
    memset(response, 0, sizeof(response));
    int response_size = 0;
    while ((response_size = recv(sockfd, response, sizeof(response), 0)) > 0) {
        printf("%s", response);
        memset(response, 0, sizeof(response));
    }
    if (response_size < 0) {
        printf("Failed to receive HTTP response from the server.\n");
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}
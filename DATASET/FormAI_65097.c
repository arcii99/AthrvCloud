//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./httpclient <ip address>\n");
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    // Get server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(80);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    // Send HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if(send(sockfd, request, strlen(request), 0) < 0) {
        printf("Failed to send HTTP request\n");
        exit(1);
    }

    // Receive HTTP response
    char response[4096];
    memset(response, 0, sizeof(response));
    if(recv(sockfd, response, sizeof(response), 0) < 0) {
        printf("Failed to receive HTTP response\n");
        exit(1);
    }

    printf("HTTP response:\n%s\n", response);

    // Close socket
    close(sockfd);

    return 0;
}
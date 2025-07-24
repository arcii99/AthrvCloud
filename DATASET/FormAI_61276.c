//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char request[MAX_BUF], response[MAX_BUF];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Build the HTTP request
    sprintf(request, "GET / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:54.0) Gecko/20100101 Firefox/54.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nConnection: close\r\n\r\n");

    // Send the request to the server
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("ERROR: Failed to send request");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    while (read(sockfd, response, MAX_BUF - 1) > 0) {
        printf("%s", response);
        memset(response, 0, MAX_BUF);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
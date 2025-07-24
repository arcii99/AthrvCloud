//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc < 3) {
        printf("Usage: http-client <server> <url>\n");
        exit(-1);
    }

    // Parse server and port from command line arguments
    char* server = argv[1];
    int port = 80;

    // Parse url from command line arguments
    char* url = argv[2];

    // Build HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", url, server);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket");
        exit(-1);
    }

    // Connect to server
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, server, &serveraddr.sin_addr.s_addr);  
    if(connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(-1);
    }

    // Send HTTP request
    if(send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(-1);
    }

    // Receive response and print to stdout
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, stdout);
    }

    // Close socket and exit
    close(sockfd);
    return 0;
}
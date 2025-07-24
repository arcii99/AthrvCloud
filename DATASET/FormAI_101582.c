//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define SERV_PORT 8080
#define MAXLINE 4096

int main(int argc, char **argv) {

    int sockfd, connfd, n;
    struct sockaddr_in servaddr, client;
    char request[MAXLINE], buffer[MAXLINE];

    // Check if URL is provided
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(0);
    }

    // Create socket for client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket\n");
        exit(0);
    }

    // Set server details
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(SERV_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("Unable to connect to server\n");
        exit(0);
    }

    // Read request from client
    n = read(sockfd, request, MAXLINE);
    if (n < 0) {
        perror("Unable to read request\n");
        exit(0);
    }

    // Add Host header to request
    char *host_header = strstr(request, "Host: ");
    if (host_header != NULL) {
        char *end = strstr(host_header+6, "\r\n");
        int len = strlen(argv[1])+6;
        char *new_header = (char*) malloc(len);
        memset(new_header, 0, len);
        sprintf(new_header, "Host: %s\r\n", argv[1]);
        memcpy(host_header, new_header, len);
        free(new_header);
    }

    // Print request
    printf("Request:\n%s\n", request);

    // Send request to server
    if (write(sockfd, request, n) < 0) {
        perror("Unable to send request");
        exit(0);
    }

    // Read response from server
    memset(buffer, 0, sizeof(buffer));
    while ((n = read(sockfd, buffer, MAXLINE)) > 0) {
        // Print response
        printf("Response:\n%s\n", buffer);
        // Send response to client
        if (write(connfd, buffer, n) < 0) {
            perror("Unable to send response");
            exit(0);
        }
        memset(buffer, 0, sizeof(buffer));
    }

    // Close sockets
    close(sockfd);
    close(connfd);

    return 0;
}
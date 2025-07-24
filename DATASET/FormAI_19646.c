//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024
#define PORT 8080

void handle_request(int connfd);

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, client_addr;
    socklen_t clientlen = sizeof(client_addr);

    // create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    // set server information
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // bind to port
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // accept connection
        connfd = accept(sockfd, (struct sockaddr*)&client_addr, &clientlen);
        if (connfd == -1) {
            perror("accept error");
            continue;
        }

        // handle request from client
        handle_request(connfd);

        // close connection
        close(connfd);
    }

    return 0;
}

void handle_request(int connfd) {
    char buffer[BUFSIZE];
    int bytes = recv(connfd, buffer, BUFSIZE, 0);

    if (bytes == -1) {
        perror("recv error");
        return;
    }

    printf("Received request:\n%s\n", buffer);

    // send response to client
    const char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html><html><body><h1>Hello, World!</h1></body></html>";
    send(connfd, response, strlen(response), 0);
}
//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096

void proxy(int connfd) {
    char buffer[MAXLINE];
    int n;
    struct sockaddr_in servaddr;

    // Create a socket for the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80); // Port 80 for HTTP

    // Connect to the server
    inet_pton(AF_INET, "www.google.com", &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // Forward client request to server
    while((n = read(connfd, buffer, MAXLINE)) > 0) {
        write(sockfd, buffer, n);
    }

    // Forward server response to client
    while((n = read(sockfd, buffer, MAXLINE)) > 0) {
        write(connfd, buffer, n);
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    // Create a socket for the proxy
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize the proxy address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    // Bind the socket to the proxy address
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // Listen for client requests
    listen(listenfd, 10);
    printf("Proxy server running on port %d...\n", ntohs(servaddr.sin_port));

    // Accept client requests and fork a child process to handle each one
    for(;;) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);

        if((childpid = fork()) == 0) {
            close(listenfd);
            proxy(connfd);
            exit(0);
        }

        close(connfd);
    }
}
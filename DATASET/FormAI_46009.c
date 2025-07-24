//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 2048
#define PROXY_PORT 8888

const char* HTTP_PREFIX = "http://";

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_BUF_SIZE];
    int n, len;
    char* endpoint;
    int ep_len;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Cannot create socket");
        return 1;
    }

    // set socket options to reuse address
    int opt_val = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val)) < 0) {
        perror("Cannot set socket option");
        return 1;
    }

    // setup server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PROXY_PORT);

    // bind server socket to address
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Cannot bind socket to address");
        return 1;
    }

    // listen for incoming connections
    if (listen(listenfd, 10) < 0) {
        perror("Cannot listen for incoming connections");
        return 1;
    }

    printf("HTTP Proxy Server is running on port %d...\n", PROXY_PORT);

    while (1) {
        bzero(&cliaddr, sizeof(cliaddr));
        len = sizeof(cliaddr);

        // accept incoming connection
        if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len)) < 0 ) {
            perror("Cannot accept incoming connection");
            continue;
        }

        printf("\n*********** Client Connected ***********\n");

        // read client request
        bzero(buffer, MAX_BUF_SIZE);
        n = read(connfd, buffer, sizeof(buffer)-1);
        if (n < 0) {
            perror("Cannot read from client socket");
            close(connfd);
            continue;
        }

        printf("[REQUEST]:\n%s", buffer);

        // parse endpoint from request
        endpoint = strstr(buffer, HTTP_PREFIX);
        ep_len = strlen(endpoint);
        int i;
        for (i = strlen(HTTP_PREFIX); i < ep_len; i++) {
            if (endpoint[i] == '/') {
                endpoint[i] = '\0';
                ep_len = i;
                break;
            }
        }

        printf("[ENDPOINT]: %s\n", endpoint);

        // create new socket to connect to endpoint
        int sockfd;
        struct sockaddr_in servaddr_ep;

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Cannot create socket to endpoint");
            close(connfd);
            continue;
        }

        bzero(&servaddr_ep, sizeof(servaddr_ep));
        servaddr_ep.sin_family = AF_INET;
        servaddr_ep.sin_port = htons(80);

        if (inet_pton(AF_INET, endpoint, &servaddr_ep.sin_addr) <= 0) {
            perror("Cannot convert endpoint IP address");
            close(connfd);
            close(sockfd);
            continue;
        }

        if (connect(sockfd, (struct sockaddr *) &servaddr_ep, sizeof(servaddr_ep)) < 0) {
            perror("Cannot connect to endpoint");
            close(connfd);
            close(sockfd);
            continue;
        }

        // forward client request to endpoint
        write(sockfd, buffer, strlen(buffer));
        printf("[FORWARDED REQUEST]:\n%s", buffer);

        // read response from endpoint
        bzero(buffer, MAX_BUF_SIZE);
        while ((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0) {
            printf("[RESPONSE]:\n%s", buffer);

            // forward response to client
            if (write(connfd, buffer, n) < 0) {
                perror("Cannot write response to client socket");
                break;
            }

            bzero(buffer, MAX_BUF_SIZE);
        }

        close(sockfd);
        close(connfd);
        printf("\n*********** Client Disconnected ***********\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PROXY_PORT 8080
#define SERVER_PORT 80
#define MAX_BUFFER_SIZE 8192

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, server_sockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in proxy_addr, server_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no target server specified\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &proxy_addr, sizeof(proxy_addr));
    portno = PROXY_PORT;

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &proxy_addr,
             sizeof(proxy_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);

    while(1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0)
            error("ERROR opening socket");

        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        if (inet_aton(argv[1], &server_addr.sin_addr)==0)
            error("ERROR invalid server IP address");

        if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
            error("ERROR connecting");

        while ((n = read(newsockfd, buffer, MAX_BUFFER_SIZE)) > 0) {
            if (write(server_sockfd, buffer, n) < 0)
                error("ERROR writing to server");
            bzero(buffer, MAX_BUFFER_SIZE);
            if (read(server_sockfd, buffer, MAX_BUFFER_SIZE) < 0)
                error("ERROR reading from server");
            if (write(newsockfd, buffer, strlen(buffer)) < 0)
                error("ERROR writing to client");
            bzero(buffer, MAX_BUFFER_SIZE);
        }

        close(newsockfd);
        close(server_sockfd);
    }

    close(sockfd);
    return 0;
}
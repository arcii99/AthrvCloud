//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, n;
    char buffer[BUFSIZE], request[BUFSIZE], response[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen = sizeof(cli_addr);

    if (argc < 2) {
        fprintf(stderr, "usage: %s <server_ip_address>\n", argv[0]);
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // setup server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid server IP address");
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting to server");
    }

    // accept incoming connections and handle requests
    while (1) {
        // accept connection
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERROR accepting connection");
        }

        // read client request
        memset(request, 0, BUFSIZE);
        n = read(newsockfd, request, BUFSIZE);
        if (n < 0) {
            fprintf(stderr, "ERROR reading from socket\n");
        }

        // forward request to server and read server response
        memset(response, 0, BUFSIZE);
        write(sockfd, request, strlen(request));
        n = read(sockfd, response, BUFSIZE);
        if (n < 0) {
            fprintf(stderr, "ERROR reading from socket\n");
        }

        // send server response to client
        write(newsockfd, response, strlen(response));

        // close client connection
        close(newsockfd);
    }

    // close server socket
    close(sockfd);

    return 0;
}
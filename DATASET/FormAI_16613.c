//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXLINE];
    char request[MAXLINE];

    if (argc < 4) {
        fprintf(stderr,"usage %s hostname port path\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    sprintf(request, "GET %s HTTP/1.0\r\nHost: %s:%s\r\n\r\n", argv[3], argv[1], argv[2]);
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    while ((n = read(sockfd, buffer, MAXLINE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, MAXLINE);
    }

    if (n < 0) {
        error("ERROR reading from socket");
    }

    close(sockfd);
    return 0;
}
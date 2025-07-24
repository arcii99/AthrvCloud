//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
//SMTP Client example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXLINE 300

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <ip-address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV;

    int status = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (status != 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, argv[1], &addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    char buf[MAXLINE];
    ssize_t n, m;

    n = sprintf(buf, "EHLO client.example.com\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "MAIL FROM: <example@client.com>\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "RCPT TO: <example@server.com>\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "DATA\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "Subject: Testing SMTP client\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "From: <example@client.com>\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "To: <example@server.com>\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "\r\nTesting SMTP client\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, ".\r\n");
    m = write(sockfd, buf, n);

    n = sprintf(buf, "QUIT\r\n");
    m = write(sockfd, buf, n);

    printf("Message sent successfully.\n");

    close(sockfd);

    return 0;
}
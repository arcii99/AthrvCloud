//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define MAXLINE 1024
#define SMTP_PORT 25

int main(int argc, char **argv) {
    int sockfd, port;
    struct hostent *he;
    struct sockaddr_in servaddr;
    char buf[MAXLINE];

    if (argc != 2) {
        printf("Usage: %s <destination_ip_address>\n", argv[0]);
        exit(1);
    }

    port = SMTP_PORT;

    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("gethostbyname() error\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        printf("socket() error\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 ) {
        printf("connect() error\n");
        exit(1);
    }

    sprintf(buf, "HELO %s\r\n", argv[1]);
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "MAIL FROM:<%s>\r\n", "sender@domain.com");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "RCPT TO:<%s>\r\n", "recipient@anotherdomain.com");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "DATA\r\n");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "Subject: Example Email\r\n");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "From: Sender Name <sender@domain.com>\r\n");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "To: Recipient Name <recipient@anotherdomain.com>\r\n");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "This is an example email.\r\n");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "\r\n.\r\n");
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "QUIT\r\n");
    send(sockfd, buf, strlen(buf), 0);

    close(sockfd);

    return 0;
}
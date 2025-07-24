//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLEN 1024

void send_email(int sockfd, char* from, char* to, char* subject, char* content)
{
    char buffer[MAXLEN];

    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAXLEN, 0);

    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAXLEN, 0);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAXLEN, 0);

    snprintf(buffer, sizeof(buffer), "From: <%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "To: <%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n", subject);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, sizeof(buffer), "%s\r\n.\r\n", content);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAXLEN, 0);

    printf("%s", buffer);
}

int main(int argc, char** argv)
{
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server> <from> <to> <subject>\n", argv[0]);
        exit(1);
    }

    char* content = "This is a test email from my SMTP client.\n";
    char buffer[MAXLEN];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    recv(sockfd, buffer, MAXLEN, 0);

    snprintf(buffer, sizeof(buffer), "EHLO myhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAXLEN, 0);

    send_email(sockfd, argv[2], argv[3], argv[4], content);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAXLEN, 0);

    close(sockfd);

    return 0;
}
//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAXLINE 4096

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: ftpclient <server ip> <user name> <password>\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    char recvline[MAXLINE] = {0};
    if (read(sockfd, recvline, MAXLINE) < 0) {
        perror("read error");
        exit(1);
    }

    printf("%s", recvline);

    char sendline[MAXLINE] = {0};
    sprintf(sendline, "USER %s\r\n", argv[2]);
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        perror("write error");
        exit(1);
    }

    memset(recvline, 0, MAXLINE);
    if (read(sockfd, recvline, MAXLINE) < 0) {
        perror("read error");
        exit(1);
    }

    printf("%s", recvline);

    memset(sendline, 0, MAXLINE);
    sprintf(sendline, "PASS %s\r\n", argv[3]);
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        perror("write error");
        exit(1);
    }

    memset(recvline, 0, MAXLINE);
    if (read(sockfd, recvline, MAXLINE) < 0) {
        perror("read error");
        exit(1);
    }

    printf("%s", recvline);

    while (1) {
        printf("ftp> ");
        fgets(sendline, MAXLINE, stdin);
        sendline[strlen(sendline)-1] = '\0';

        if (write(sockfd, sendline, strlen(sendline)) < 0) {
            perror("write error");
            exit(1);
        }

        memset(recvline, 0, MAXLINE);
        if (read(sockfd, recvline, MAXLINE) < 0) {
            perror("read error");
            exit(1);
        }

        printf("%s", recvline);

        if (strstr(recvline, "221 Goodbye") != NULL) {
            break;
        }
    }

    close(sockfd);
    exit(0);
}
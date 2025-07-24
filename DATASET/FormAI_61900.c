//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 4096
#define SERV_PORT 110

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <IPaddress>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "socket error");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(SERV_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "connect error\n");
        exit(1);
    }

    // read the welcome message from server
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    if (recvline[0] == '-' || recvline[0] == '+') {
        printf("%s\n", recvline);
    }

    // send the login credentials to server
    char user[MAXLINE], pass[MAXLINE];
    printf("Enter username: ");
    fgets(user, MAXLINE, stdin);
    printf("Enter password: ");
    fgets(pass, MAXLINE, stdin);
    snprintf(recvline, MAXLINE, "USER %s\r\n", user);
    write(sockfd, recvline, strlen(recvline));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    if (recvline[0] == '-' || recvline[0] == '+') {
        printf("%s\n", recvline);
    }

    snprintf(recvline, MAXLINE, "PASS %s\r\n", pass);
    write(sockfd, recvline, strlen(recvline));
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = 0;
    if (recvline[0] == '-' || recvline[0] == '+') {
        printf("%s\n", recvline);
    }

    // list all the emails in the inbox
    snprintf(recvline, MAXLINE, "LIST\r\n");
    write(sockfd, recvline, strlen(recvline));
    while (1) {
        n = read(sockfd, recvline, MAXLINE);
        recvline[n] = 0;
        if (strcmp(recvline, ".\r\n") == 0) {
            break;
        }
        printf("%s", recvline);
    }

    // read the first email in the inbox
    printf("Enter the index of email to read: ");
    int email_id;
    scanf("%d", &email_id);
    snprintf(recvline, MAXLINE, "RETR %d\r\n", email_id);
    write(sockfd, recvline, strlen(recvline));
    while (1) {
        n = read(sockfd, recvline, MAXLINE);
        recvline[n] = 0;
        if (strcmp(recvline, ".\r\n") == 0) {
            break;
        }
        printf("%s", recvline);
    }

    close(sockfd);
    exit(0);
}
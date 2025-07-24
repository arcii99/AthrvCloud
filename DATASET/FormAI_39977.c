//FormAI DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define MAXLINE 4096
#define SERV_PORT 9877

static void sig_alarm(int signo) {}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2) {
        printf("usage: %s <IPaddress>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("connect error\n");
        exit(1);
    }

    signal(SIGALRM, sig_alarm);
    alarm(5);

    char sendline[MAXLINE], recvline[MAXLINE];
    fd_set rset;
    int maxfdp1, n;
    struct timeval tv;

    while (1) {
        memset(sendline, 0, sizeof(sendline));
        memset(recvline, 0, sizeof(recvline));

        FD_ZERO(&rset);
        maxfdp1 = sockfd + 1;
        FD_SET(sockfd, &rset);

        tv.tv_sec = 5;
        tv.tv_usec = 0;

        if (select(maxfdp1, &rset, NULL, NULL, &tv) <= 0)
            break;

        if (FD_ISSET(sockfd, &rset)) {
            if ((n = read(sockfd, recvline, MAXLINE)) == 0) {  // server terminated prematurely
                printf("server terminated prematurely\n");
                exit(1);
            }
            printf("Message received from server: %s", recvline);
        }

        printf("Client message to server: ");
        fgets(sendline, MAXLINE, stdin);

        write(sockfd, sendline, strlen(sendline));
    }

    exit(0);
}
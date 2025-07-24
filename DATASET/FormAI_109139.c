//FormAI DATASET v1.0 Category: Simple Web Server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 4096
#define SERV_PORT 8080

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buf[MAXLINE];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("WEB SERVER STARTED LISTENING ON PORT %d\n", SERV_PORT);

    while (1) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);

        printf("CONNECTION ACCEPTED FROM IP ADDRESS %s PORT %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        if (fork() == 0) {
            close(listenfd);
            char *response = "HTTP/1.0 200 OK\r\n\r\nHello, World!\r\n";
            write(connfd, response, strlen(response));
            exit(0);
        }
        close(connfd);
    }
    return 0;
}
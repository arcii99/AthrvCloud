//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_MSG_LEN     4096

int main(int argc, char **argv)
{
    int   sockfd, n;
    char  recvline[MAX_MSG_LEN + 1];
    struct sockaddr_in servaddr;

    if (argc != 2)
    {
        printf("Usage: %s <server_address>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    char *request_data = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";

    if (write(sockfd, request_data, strlen(request_data)) != strlen(request_data))
    {
        perror("write");
        exit(1);
    }

    while ((n = read(sockfd, recvline, MAX_MSG_LEN - 1)) > 0)
    {
        recvline[n] = '\0';

        printf("%s", recvline);
    }

    if (n < 0)
    {
        perror("read");
        exit(1);
    }

    exit(0);
}
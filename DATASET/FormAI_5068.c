//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_LINE 1024
#define SERVER_NAME "example.com"
#define SERVER_PORT "80"

int main()
{
    struct addrinfo hints, *servinfo, *p;
    int status, sockfd;
    struct sockaddr_storage their_addr;
    socklen_t addr_len = sizeof(their_addr);
    char buf[MAX_LINE];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        printf("Trying to connect to %s...\n", SERVER_NAME);
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        printf("Connected to %s successfully!\n", SERVER_NAME);
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", SERVER_NAME);
        exit(1);
    }

    freeaddrinfo(servinfo);

    while (1) {
        int bytes_recv = recv(sockfd, buf, MAX_LINE - 1, 0);
        if (bytes_recv == -1) {
            perror("recv");
            break;
        }

        buf[bytes_recv] = '\0';
        printf("%s", buf);
        if (bytes_recv == 0) {
            printf("\nConnection closed by server\n");
            break;
        }

        sleep(1);
    }

    close(sockfd);
    return 0;
}
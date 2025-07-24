//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    char* target = argv[1];
    int sockfd, startport, endport, i, j;
    struct sockaddr_in target_addr;
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    printf("Starting port: ");
    scanf("%d", &startport);
    printf("Ending port: ");
    scanf("%d", &endport);

    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(0);
    target_addr.sin_addr.s_addr = inet_addr(target);

    for (i = startport; i <= endport; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
        target_addr.sin_port = htons(i);
        j = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));

        if (j == 0) {
            printf("Port %d is open.\n", i);
        }
        close(sockfd);
    }

    return 0;
}
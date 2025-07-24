//FormAI DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT 1    // timeout for connection attempt in seconds
#define MAXPORT 65535     // maximum port number to scan
#define MINPORT 1     // minimum port number to scan

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Syntax: %s <ip_address>\n", argv[0]);
        return 0;
    }

    int sockfd, ret, optval;
    struct sockaddr_in target;
    bool isopen;

    memset(&target, 0, sizeof(struct sockaddr_in));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    for (int port=MINPORT; port<=MAXPORT; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sockfd < 0) {
            printf("[Error] could not create socket!\n");
            return -1;
        }

        optval = 1;
        ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        if (ret < 0) {
            printf("[Warning] could not set socket option SO_REUSEADDR\n");
        }

        target.sin_port = htons(port);

        ret = connect(sockfd, (struct sockaddr *)&target, sizeof(struct sockaddr));
        if (ret < 0) {
            // could not connect, port is closed
            isopen = false;
        } else {
            // connection successful, port is open
            isopen = true;
            close(sockfd);
        }

        if (isopen) {
            printf("[+] %d/tcp open\n", port);
        }

        usleep(TIMEOUT * 1000000);    // sleep for specified timeout period
    }

    return 0;
}
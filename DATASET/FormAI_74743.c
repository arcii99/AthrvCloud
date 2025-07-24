//FormAI DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>

#define BUFLEN 2048 

int create_socket(char *sourceAddr, int port) {
    struct sockaddr_in local;
    int fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (fd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    memset(&local, 0, sizeof(local));
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = inet_addr(sourceAddr);
    if (bind(fd, (struct sockaddr *)&local, sizeof(local)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    return fd;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source IP address> <destination IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *srcIpAddr = argv[1];
    char *dstIpAddr = argv[2];

    int sockFd = create_socket(srcIpAddr, 0);
    struct sockaddr_in dst;
    memset(&dst, 0, sizeof(struct sockaddr_in));
    dst.sin_family = AF_INET;
    dst.sin_addr.s_addr = inet_addr(dstIpAddr);

    char buffer[BUFLEN];
    memset(buffer, 0xff, BUFLEN);

    while (1) {
        ssize_t sent = sendto(
            sockFd, buffer, sizeof(buffer), 0,
            (struct sockaddr *)&dst, sizeof(dst)
        );
        if (sent < 0) {
            perror("sendto() failed");
            exit(EXIT_FAILURE);
        }

        printf("Sent %ld bytes to %s\n", sent, dstIpAddr);
        usleep(100000);
    }

    close(sockFd);
    exit(EXIT_SUCCESS);
}
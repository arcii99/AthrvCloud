//FormAI DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SCAN_RANGE_START 1
#define SCAN_RANGE_END 65535

void scan_port(int sockfd, struct sockaddr_in *addr, int port) {
    addr->sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *) addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Port %d is closed.\n", port);
    } else {
        printf("Port %d is open!\n", port);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) == -1) {
        printf("Invalid address: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    for (int port = SCAN_RANGE_START; port <= SCAN_RANGE_END; port++) {
        scan_port(sockfd, &addr, port);
    }
    
    close(sockfd);
    return EXIT_SUCCESS;
}
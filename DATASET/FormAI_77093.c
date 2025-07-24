//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip>\n", argv[0]);
        exit(1);
    }
    
    printf("Starting port scan on %s...\n", argv[1]);
    
    uint16_t port;
    struct sockaddr_in sa;
    
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        exit(1);
    }
    
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(argv[1]);
    
    for (port = 1; port <= 65535; port++) {
        sa.sin_port = htons(port);
        int result = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
        if (result == 0) {
            printf("Port %d is open.\n", port);
        }
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sockfd == -1) {
            printf("socket() failed: %s\n", strerror(errno));
            exit(1);
        }
    }
    
    printf("Scan complete!\n");
    
    return 0;
}
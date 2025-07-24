//FormAI DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define NUM_PORTS 65535  // maximum number of ports to scan
#define NUM_PROBES 3     // number of probe packets to send per port

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target IP>\n", argv[0]);
        return -1;
    }

    int sockfd, i, j, k;
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    for (i = 1; i <= NUM_PORTS; i++) {
        target.sin_port = htons(i);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            return -1;
        }
        // set timeout for socket
        struct timeval tv;
        tv.tv_sec = 1;  // 1 second timeout
        tv.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
            perror("setsockopt");
            return -1;
        }
        // connect to target on port i
        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) >= 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
        close(sockfd);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int start_port = 1;
    int end_port = 65535;

    printf("Scanning ports on %s\n", host);

    int sockfd;
    struct sockaddr_in addr;

    // loop over all possible ports and try to connect to them
    for (int port = start_port; port <= end_port; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("socket()");
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(host);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open.\n", port);
        }

        close(sockfd);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535
#define TIMEOUT 3

int main(int argc, char *argv[]) {
    int port, sockfd, status;
    char *target;

    if (argc != 2) {
        printf("Usage: %s <target>\n", argv[0]);
        return 1;
    }

    // Set target from command-line argument
    target = argv[1];

    // Create IPv4 TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    status = inet_pton(AF_INET, target, &(sa.sin_addr));
    if (status < 0) {
        perror("inet_pton");
        return 1;
    } else if (status == 0) {
        printf("Invalid address format\n");
        return 1;
    }

    memset(&(sa.sin_zero), 0, 8);

    // Attempt to connect to each port
    for (port = 1; port <= MAX_PORT; port++) {
        sa.sin_port = htons(port);
        status = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

        if (status == 0) {
            printf("%d/tcp open\n", port);
        } else {
            printf("%d/tcp closed\n", port);
        }
        sleep(TIMEOUT);
    }

    // Close socket
    close(sockfd);

    return 0;
}
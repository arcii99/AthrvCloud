//FormAI DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PORT 65535

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [IP Address]\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    printf("Scanning ports for %s...\n", argv[1]);

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(argv[1]);

    for (int i = 1; i <= MAX_PORT; i++) {
        address.sin_port = htons(i);

        if (connect(sockfd, (struct sockaddr*) &address, sizeof(address)) >= 0) {
            printf("Port %d is open.\n", i);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
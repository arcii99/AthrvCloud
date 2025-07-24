//FormAI DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

int main(int argc, char **argv) {
    int sockfd;
    int result;
    char *hostname;
    struct sockaddr_in target;

    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    printf("Scanning %s...\n", hostname);

    // Clear target address structure
    memset(&target, 0, sizeof(struct sockaddr_in));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(hostname);

    // Scan ports
    for (int port = 1; port <= MAX_PORT; port++) {
        target.sin_port = htons(port);

        // Attempt to connect to port
        result = connect(sockfd, (struct sockaddr *) &target, sizeof(struct sockaddr_in));
        if (result == 0) {
            printf("Port %d open\n", port);
        }

        // Reset socket for next attempt
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket() error");
            exit(EXIT_FAILURE);
        }
    }

    printf("Scan complete\n");

    return EXIT_SUCCESS;
}
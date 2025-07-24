//FormAI DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <start-port> <end-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning %s from port %d to %d...\n", hostname, start_port, end_port);

    struct hostent *he;
    struct sockaddr_in addr;

    if ((he = gethostbyname(hostname)) == NULL) {
        printf("Could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    for (int port = start_port; port <= end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = *((struct in_addr*) he->h_addr);

        if (connect(sockfd, (struct sockaddr*) &addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        }

        close(sockfd);
    }

    return 0;
}
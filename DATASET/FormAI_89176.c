//FormAI DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Returns true if connection is successful
bool test_port(char* ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return false;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (!inet_pton(AF_INET, ip, &serv_addr.sin_addr)) {
        close(sockfd);
        return false;
    }

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == 0) {
        close(sockfd);
        return true;
    } else {
        close(sockfd);
        return false;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning for open ports on %s...\n", argv[1]);
    printf("---------------------------------------------------------\n");
    printf("| Port\t\t| Status\t\t|\n");
    printf("---------------------------------------------------------\n");

    for (int port = 1; port < 65536; port++) {
        if (test_port(argv[1], port)) {
            printf("| %d\t\t| Open\t\t|\n", port);
        } else {
            printf("| %d\t\t| Closed\t\t|\n", port);
        }
    }

    printf("---------------------------------------------------------\n");

    return EXIT_SUCCESS;
}
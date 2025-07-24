//FormAI DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s [ip address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Scanning %s...\n", argv[1]);

    for(int port = 1; port <= MAX_PORTS; port++) {
        target.sin_port = htons(port);

        if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open.\n", port);
        }

        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1) {
            perror("socket() error");
            exit(EXIT_FAILURE);
        }
    }

    printf("Scan complete.\n");

    return 0;
}
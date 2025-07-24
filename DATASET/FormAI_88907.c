//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port;
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);

    printf("Scanning %s...\n", ip_address);

    for (port = 1; port <= MAX_PORTS; port++) {
        target.sin_port = htons(port);
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket");
            exit(1);
        }

        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d open!\n", port);
        }

        close(sock);
    }

    printf("Scan complete!\n");

    return 0;
}
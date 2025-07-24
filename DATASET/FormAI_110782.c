//FormAI DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define START_PORT 1
#define END_PORT 65535

bool scan_port(char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);
    target.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        close(sock);
        return true;
    } else {
        close(sock);
        return false;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [ip address]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    printf("Scanning open ports on %s\n", ip_address);
    printf("-----------------------------\n");

    for (int port = START_PORT; port <= END_PORT; port++) {
        if (scan_port(ip_address, port)) {
            printf("Port %d: Open\n", port);
        }
    }

    printf("-----------------------------\n");
    printf("Scan complete\n");

    return EXIT_SUCCESS;
}
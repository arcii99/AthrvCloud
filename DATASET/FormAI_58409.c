//FormAI DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

void scan_port(const char *ip, unsigned int port) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed!");
        return;
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) == 0) {
        printf("Port %u is open\n", port);
    } else {
        perror("connect() failed");
    }
    close(sock);
}

void banner() {
    printf("=============================\n");
    printf("     C Port Scanner Example    \n");
    printf("  Scan ports between 1 and 65535 \n");
    printf("=============================\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    banner();
    const char *ip = argv[1];
    printf("Scanning ports for ip %s ... \n\n", ip);

    for (unsigned int port = 1; port <= 65535; port++) {
        scan_port(ip, port);
    }
    return EXIT_SUCCESS;
}
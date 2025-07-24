//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 1024

void scan_port(const char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) >= 0) {
        printf("Port %d is open.\n", port);
    }

    close(sock);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    const char *ip = argv[1];

    for(int port = 1; port <= MAX_PORTS; port++) {
        scan_port(ip, port);
    }

    printf("Scan complete.\n");

    return 0;
}
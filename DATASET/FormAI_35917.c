//FormAI DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void scan_port(char* ip_addr, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    target_addr.sin_addr.s_addr = inet_addr(ip_addr);

    if (connect(sock, (struct sockaddr*) &target_addr, sizeof(target_addr)) == 0) {
        printf("Port %d is open.\n", port);
    } else {
        printf("Port %d is closed.\n", port);
    }

    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    char* ip_addr = argv[1];
    int ports[] = { 21, 22, 23, 80, 443, 3389 };

    for (int i=0; i < sizeof(ports)/sizeof(ports[0]); i++) {
        scan_port(ip_addr, ports[i]);
    }

    return 0;
}
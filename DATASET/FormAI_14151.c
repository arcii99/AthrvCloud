//FormAI DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

void scan_ports(char *ip, int start_port, int end_port) {
    int sock, i, j, port, count = 0;
    struct sockaddr_in target;

    for (i = start_port; i <= end_port; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(ip);
        target.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d - Open\n", i);
            count++;
        }
        close(sock);
    }
    printf("\nScan complete!\n%d open port(s) found.\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <ip address> <starting port> <ending port>\n", argv[0]);
        exit(1);
    }
    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 0 || end_port > MAX_PORTS) {
        printf("Invalid port range.\n");
        exit(1);
    }

    printf("Starting port scan on %s:%d-%d...\n", ip, start_port, end_port);
    scan_ports(ip, start_port, end_port);

    return 0;
}
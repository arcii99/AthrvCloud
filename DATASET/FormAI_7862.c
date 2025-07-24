//FormAI DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void scan_ports(char *ip_address) {
    //create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(ip_address);

    //scan all ports from 1 to 10000
    for (int port = 1; port <= 10000; port++) {
        sa.sin_port = htons(port);
        int result = connect(sock, (struct sockaddr *)&sa, sizeof(sa));
        if (result < 0) {
            //port closed
            printf("Port %d: Closed\n", port);
        } else {
            //port open
            printf("Port %d: Open\n", port);
        }
    }

    close(sock);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./portscanner <ip address>\n");
        exit(1);
    }

    printf("Scanning ports for %s...\n", argv[1]);
    scan_ports(argv[1]);

    return 0;
}
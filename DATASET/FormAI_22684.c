//FormAI DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535     // Maximum number of ports to scan
#define TIMEOUT 2000        // Timeout for each port in milliseconds

void scan_port(char *ip, int port);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: portscanner <ip>\n");
        return 1;
    }

    char *ip = argv[1];

    printf("Scanning %s...\n", ip);

    // Scan all ports from 1 to 65535
    for(int port=1; port<=MAX_PORTS; port++) {
        scan_port(ip, port);
    }

    printf("Scan complete!\n");

    return 0;
}

void scan_port(char *ip, int port) {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket");
        return;
    }

    // Set socket options
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT / 1000;
    timeout.tv_usec = (TIMEOUT % 1000) * 1000;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

    // Create sockaddr_in structure with target IP and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to target
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sock);
        return;
    }

    // Print open port
    printf("Port %d is open!\n", port);

    close(sock);
}
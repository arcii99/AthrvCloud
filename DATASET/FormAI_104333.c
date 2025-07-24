//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in scanner_addr;
    char *ip_addr = argv[1];

    if(argc != 2) {
        printf("Usage: ./mapper <IP address>\n");
        return 1;
    }

    // Create socket for IPv4, UDP protocol
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = 3;
    tv.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        printf("setsockopt(SO_RCVTIMEO) failed\n");
        return 1;
    }

    // Set endpoint address
    memset(&scanner_addr, 0, sizeof(scanner_addr));
    scanner_addr.sin_family = AF_INET;
    scanner_addr.sin_addr.s_addr = inet_addr(ip_addr);
    scanner_addr.sin_port = htons(1);

    // Scan port 1 to 65535
    printf("Scanning ports...\n");
    for(int port=1; port <= 65535; port++) {
        // Set endpoint port
        scanner_addr.sin_port = htons(port);

        // Send empty packet to endpoint
        if(sendto(sock, NULL, 0, 0, (struct sockaddr *)&scanner_addr, sizeof(scanner_addr)) == -1) {
            printf("Port %d is closed.\n", port);
        } else {
            printf("Port %d is open.\n", port);
        }
    }

    close(sock);
    return 0;
}
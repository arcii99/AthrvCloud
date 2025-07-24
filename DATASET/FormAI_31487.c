//FormAI DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define NUM_PORTS 1024

void port_scanner(char *ip) {
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(80); /* default port to check */

    int sockfd = -1;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Socket");
        exit(1);
    }
    if (inet_pton(AF_INET, ip, &target_addr.sin_addr) <= 0) {
        printf("Invalid address or Address not supported\n");
        exit(1);
    }
    printf("\nScanning %s for open ports...\n", ip);
    printf("----------------------------------------\n");
    for (int port = 1; port <= NUM_PORTS; port++) {
        target_addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("[+]\tPort %d open\n", port);
        }
    }
    close(sockfd);
    printf("----------------------------------------\n");
    printf("Scan finished.\n\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }
    port_scanner(argv[1]);
    return 0;
}
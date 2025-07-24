//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        return 1;
    }

    char *ip_addr_str = argv[1];
    char *subnet_mask_str = argv[2];

    // Convert IP and subnet mask from string to binary
    in_addr_t ip_addr = inet_addr(ip_addr_str);
    in_addr_t subnet_mask = inet_addr(subnet_mask_str);

    // Calculate network address from IP address and subnet mask
    in_addr_t network_addr = ip_addr & subnet_mask;

    // Translate binary addresses to printable strings
    char ip_addr_printable[MAX_BUFFER];
    char subnet_mask_printable[MAX_BUFFER];
    char network_addr_printable[MAX_BUFFER];

    inet_ntop(AF_INET, &ip_addr, ip_addr_printable, sizeof(ip_addr_printable));
    inet_ntop(AF_INET, &subnet_mask, subnet_mask_printable, sizeof(subnet_mask_printable));
    inet_ntop(AF_INET, &network_addr, network_addr_printable, sizeof(network_addr_printable));

    printf("Input IP address: %s\n", ip_addr_printable);
    printf("Input subnet mask: %s\n", subnet_mask_printable);
    printf("Output network address: %s\n", network_addr_printable);

    // Scan network for active hosts
    printf("\nScanning network for active hosts...\n\n");

    struct in_addr host_addr;
    char host_addr_str[MAX_BUFFER];

    int sockfd;
    struct sockaddr_in sockaddr;

    // Iterate through each possible host in network
    for (in_addr_t i = network_addr + 1; i < network_addr + (~subnet_mask); i++) {
        // Convert host address from binary to printable string
        host_addr.s_addr = i;
        inet_ntop(AF_INET, &host_addr, host_addr_str, sizeof(host_addr_str));

        // Open socket and connect to host
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        memset(&sockaddr, 0, sizeof(sockaddr));
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_port = htons(80);
        inet_pton(AF_INET, host_addr_str, &sockaddr.sin_addr);

        int result = connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
        if (result == 0) {
            printf("Host %s is active!\n", host_addr_str);
        }

        close(sockfd);
    }

    printf("\nScan complete.\n");

    return 0;
}
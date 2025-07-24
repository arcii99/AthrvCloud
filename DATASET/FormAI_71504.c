//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_binary(unsigned int num, int digits) {
    for (int i = digits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    char ip[16];
    int prefix;

    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter prefix length: ");
    scanf("%d", &prefix);

    unsigned int ip_addr = 0;
    char *ip_part = strtok(ip, ".");
    while (ip_part != NULL) {
        ip_addr = (ip_addr << 8) | strtol(ip_part, NULL, 10);
        ip_part = strtok(NULL, ".");
    }

    unsigned int subnet_mask = (~0) << (32 - prefix);
    unsigned int network_addr = ip_addr & subnet_mask;
    unsigned int broadcast_addr = network_addr | ~subnet_mask;

    printf("\nIPv4 address: %s\n", ip);
    printf("Prefix length: %d\n", prefix);
    printf("Subnet mask: ");
    print_binary(subnet_mask, 32);
    printf("\nNetwork address: ");
    print_binary(network_addr, 32);
    printf("\nBroadcast address: ");
    print_binary(broadcast_addr, 32);
    printf("\n\n");

    return 0;
}
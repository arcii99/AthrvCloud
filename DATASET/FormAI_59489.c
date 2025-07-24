//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subnetMask(int prefix, char *subnet_mask) {
    memset(subnet_mask, '\0', 16);
    int i, j;
    for (i = 0; i < prefix; i++) {
        j = i % 8;
        subnet_mask[i / 8] += 1 << (7 - j);
    }
}

int main() {
    printf("Welcome to the C Subnet Calculator!\n\n");
    unsigned int IP, prefix;
    printf("Enter the IP address in decimal format: ");
    scanf("%d", &IP);
    printf("Enter the subnet prefix: ");
    scanf("%u", &prefix);
    char subnet_mask[16];
    subnetMask(prefix, subnet_mask);
    unsigned int subnet = IP & *((unsigned int *) subnet_mask);
    unsigned int broadcast = subnet | ~*((unsigned int *) subnet_mask);
    unsigned int host_min = subnet + 1;
    unsigned int host_max = broadcast - 1;
    unsigned int host_count = host_max - host_min + 1;

    printf("\nSubnet mask: %s\n", subnet_mask);
    printf("Subnet address: %d.%d.%d.%d\n", (subnet >> 24) & 0xff, (subnet >> 16) & 0xff, (subnet >> 8) & 0xff, subnet & 0xff);
    printf("Broadcast address: %d.%d.%d.%d\n", (broadcast >> 24) & 0xff, (broadcast >> 16) & 0xff, (broadcast >> 8) & 0xff, broadcast & 0xff);
    printf("Minimum host IP address: %d.%d.%d.%d\n", (host_min >> 24) & 0xff, (host_min >> 16) & 0xff, (host_min >> 8) & 0xff, host_min & 0xff);
    printf("Maximum host IP address: %d.%d.%d.%d\n", (host_max >> 24) & 0xff, (host_max >> 16) & 0xff, (host_max >> 8) & 0xff, host_max & 0xff);
    printf("Number of hosts in the subnet: %u\n", host_count);

    return 0;
}
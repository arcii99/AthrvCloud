//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OCTET_MAX 256

int convertSubnetMaskToCIDR(char *subnetMask) {
    int cidr = 0;
    char *octet = strtok(subnetMask, ".");
    while (octet != NULL) {
        int byte = atoi(octet);
        while (byte > 0) {
            cidr++;
            byte >>= 1;
        }
        octet = strtok(NULL, ".");
    }
    return cidr;
}

int main() {
    char ipAddress[16], subnetMask[16];
    printf("Enter IP Address: ");
    scanf("%s", ipAddress);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnetMask);

    int cidr = convertSubnetMaskToCIDR(subnetMask);
    int totalSubnets = 1 << (32 - cidr);
    int hostBits = 32 - cidr;
    int totalHosts = (1 << hostBits) - 2;

    printf("\nResults\n");
    printf("Network Address: %s\n", ipAddress);
    printf("Subnet Mask: %s (%d)\n", subnetMask, cidr);
    printf("Total Subnets: %d\n", totalSubnets);
    printf("Total Hosts: %d\n", totalHosts);

    return 0;
}
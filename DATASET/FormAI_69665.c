//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long ipAddr, mask;
    int octets[4];
    int maskOctets[4];
    int subnetSize;
    int subnetBits;

    printf("Enter IP address (in the format xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

    printf("Enter subnet mask (in the format xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &maskOctets[0], &maskOctets[1], &maskOctets[2], &maskOctets[3]);

    printf("Enter subnet size: ");
    scanf("%d", &subnetSize);

    // Convert IP address to a single integer
    ipAddr = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];

    // Convert subnet mask to a single integer
    mask = (maskOctets[0] << 24) | (maskOctets[1] << 16) | (maskOctets[2] << 8) | maskOctets[3];

    // Calculate number of subnet bits
    subnetBits = 32 - subnetSize;

    // Calculate number of subnets
    unsigned long numSubnets = 1 << subnetSize;

    // Calculate number of hosts per subnet
    unsigned long numHostsPerSubnet = (1 << subnetBits) - 2;

    // Perform bitwise AND to get network address
    unsigned long network = ipAddr & mask;

    // Perform bitwise OR to get broadcast address
    unsigned long broadcast = network | ~mask;

    // Print results
    printf("Network address: %d.%d.%d.%d\n", (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, network & 0xFF);
    printf("Broadcast address: %d.%d.%d.%d\n", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);
    printf("Number of subnets: %lu\n", numSubnets);
    printf("Number of hosts per subnet: %lu\n", numHostsPerSubnet);

    return 0;
}
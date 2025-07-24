//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip[16];
    char subnet[16];
    int subnetBits;
    int subnetMask;
    int numHosts;
    int bitsRemaining;
    int hostsRemaining;

    printf("Enter IP address in the following format (XXX.XXX.XXX.XXX): ");
    fgets(ip, sizeof(ip), stdin);
    printf("Enter subnet in the following format (XXX.XXX.XXX.XXX): ");
    fgets(subnet, sizeof(subnet), stdin);
    printf("Enter number of subnet bits: ");
    scanf("%d", &subnetBits);

    subnetMask = 0xffffffff << (32 - subnetBits);
    numHosts = 0xffffffff >> subnetBits;
    bitsRemaining = 32 - subnetBits;
    hostsRemaining = numHosts;

    printf("\nCalculating subnet information:\n");

    printf("IP address: %s", ip);
    printf("Subnet mask: %d.%d.%d.%d\n", (subnetMask >> 24) & 0xff, (subnetMask >> 16) & 0xff, (subnetMask >> 8) & 0xff, subnetMask & 0xff);
    printf("Number of subnet bits: %d\n", subnetBits);
    printf("Number of host bits: %d\n", bitsRemaining);
    printf("Number of subnets: %d\n", (0xffffffff / (numHosts + 1)) + 1);
    printf("Number of hosts per subnet: %d\n\n", numHosts);

    printf("Calculating addresses for the first 10 subnets:\n");

    int i;
    for (i = 0; i < 10; i++) {
        int subnetAddress = ((subnetMask & *(unsigned int *)ip) | (i << bitsRemaining)) & 0xffffffff;
        int broadcastAddress = subnetAddress | numHosts;
        printf("Subnet %d address: %d.%d.%d.%d\n", i + 1, (subnetAddress >> 24) & 0xff, (subnetAddress >> 16) & 0xff, (subnetAddress >> 8) & 0xff, subnetAddress & 0xff);
        printf("Subnet %d broadcast address: %d.%d.%d.%d\n", i + 1, (broadcastAddress >> 24) & 0xff, (broadcastAddress >> 16) & 0xff, (broadcastAddress >> 8) & 0xff, broadcastAddress & 0xff);
        printf("Number of hosts in subnet %d: %d\n\n", i + 1, hostsRemaining);
        hostsRemaining -= numHosts + 2;
    }

    return 0;
}
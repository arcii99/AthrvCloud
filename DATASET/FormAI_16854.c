//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int IPAddress, subnetMask;
    unsigned int networkAddress, hostAddress;
    unsigned int wildcardMask, broadcastAddress;

    printf("Enter IP address: ");
    scanf("%u", &IPAddress);

    printf("Enter subnet mask: ");
    scanf("%u", &subnetMask);

    networkAddress = IPAddress & subnetMask;
    wildcardMask = subnetMask ^ 0xFFFFFFFF;
    broadcastAddress = networkAddress | wildcardMask;
    hostAddress = IPAddress & wildcardMask;

    printf("Network Address: %u\n", networkAddress);
    printf("Wildcard Mask: %u\n", wildcardMask);
    printf("Broadcast Address: %u\n", broadcastAddress);
    printf("Host Address: %u\n", hostAddress);

    return 0;
}
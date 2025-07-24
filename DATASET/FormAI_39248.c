//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBNET_MASK 0xFFFFFFFF
#define BYTE_MAX 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP Address> <Subnet Mask>\n", argv[0]);
        return 1;
    }
    
    unsigned int ipAddress, subnetMask;
    if (inet_aton(argv[1], (struct in_addr*) &ipAddress) == 0) {
        printf("Invalid IP address!\n");
        return 1;
    }
    if (inet_aton(argv[2], (struct in_addr*) &subnetMask) == 0) {
        printf("Invalid subnet mask!\n");
        return 1;
    }
    
    unsigned int netAddress = ipAddress & subnetMask;
    unsigned int hostAddress = ipAddress & ~subnetMask;
    unsigned int wildcardMask = ~subnetMask;
    unsigned int broadcastAddress = netAddress | wildcardMask;
    unsigned int numberOfHosts = BYTE_MAX - wildcardMask - 1;
    
    printf("IP Address: %s\n", argv[1]);
    printf("Subnet Mask: %s\n", argv[2]);
    printf("Network Address: %d.%d.%d.%d\n", (netAddress >> 24) & 0xFF, (netAddress >> 16) & 0xFF, (netAddress >> 8) & 0xFF, netAddress & 0xFF);
    printf("Host Address: %d.%d.%d.%d\n", (hostAddress >> 24) & 0xFF, (hostAddress >> 16) & 0xFF, (hostAddress >> 8) & 0xFF, hostAddress & 0xFF);
    printf("Wildcard Mask: %d.%d.%d.%d\n", (wildcardMask >> 24) & 0xFF, (wildcardMask >> 16) & 0xFF, (wildcardMask >> 8) & 0xFF, wildcardMask & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcastAddress >> 24) & 0xFF, (broadcastAddress >> 16) & 0xFF, (broadcastAddress >> 8) & 0xFF, broadcastAddress & 0xFF);
    printf("Number of Hosts: %d\n", numberOfHosts);
    
    return 0;
}
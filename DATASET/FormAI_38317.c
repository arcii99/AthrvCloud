//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char ip[20], subnet[20];
    int mask[4], ipAddr[4], subnetMask[4], networkAddr[4], broadcastAddr[4], i;
    unsigned long int subnetMaskBits = 0, hosts = 0;
    
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", subnet);
    
    sscanf(ip, "%d.%d.%d.%d", &ipAddr[0], &ipAddr[1], &ipAddr[2], &ipAddr[3]);
    sscanf(subnet, "%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);
    
    for (i = 0; i < 4; i++)
    {
        mask[i] = 255 - subnetMask[i];
        networkAddr[i] = (ipAddr[i] & subnetMask[i]);
        broadcastAddr[i] = networkAddr[i] | mask[i];
        subnetMaskBits += subnetMask[i] << ((3 - i) * 8);
    }
    
    hosts = pow(2, 32 - subnetMaskBits) - 2;
    
    printf("Network Address: %d.%d.%d.%d\n", networkAddr[0], networkAddr[1], networkAddr[2], networkAddr[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    printf("Number of Hosts: %ld\n", hosts);
    
    return 0;
}
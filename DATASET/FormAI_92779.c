//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>

int main() {
    unsigned int ipAddress;
    int subnetMask;
    unsigned int networkAddress;
    unsigned int broadcastAddress;
    unsigned int subnetSize;
    unsigned int hosts;

    printf("Enter IP address in decimal format: ");
    scanf("%u", &ipAddress);
    printf("Enter subnet mask in decimal format: ");
    scanf("%d", &subnetMask);

    networkAddress = ipAddress & (0xffffffff << (32-subnetMask));
    broadcastAddress = networkAddress | ~(0xffffffff << (32-subnetMask));
    subnetSize = 1 << (32-subnetMask);
    hosts = subnetSize - 2;

    printf("\nNetwork Address:\t%u.%u.%u.%u", (networkAddress>>24),(networkAddress>>16)&0xff,(networkAddress>>8)&0xff,networkAddress&0xff);
    printf("\nBroadcast Address:\t%u.%u.%u.%u", (broadcastAddress>>24),(broadcastAddress>>16)&0xff,(broadcastAddress>>8)&0xff,broadcastAddress&0xff);
    printf("\nSubnet Size:\t\t%d", subnetSize);
    printf("\nUsable Hosts:\t\t%d", hosts);

    return 0;
}
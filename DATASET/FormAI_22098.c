//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void calcSubnet(unsigned long ipAddr, int subnetBits) {
    unsigned long subnetMask = 0xFFFFFFFF << (32 - subnetBits);
    unsigned long networkAddr = ipAddr & subnetMask;
    unsigned long broadcastAddr = networkAddr | ~subnetMask;
    printf("Subnet mask: %d.%d.%d.%d\n", (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, (subnetMask >> 8) & 0xFF,
           subnetMask & 0xFF);
    printf("Network Address: %d.%d.%d.%d\n", (networkAddr >> 24) & 0xFF, (networkAddr >> 16) & 0xFF, (networkAddr >> 8) & 0xFF,
           networkAddr & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcastAddr >> 24) & 0xFF, (broadcastAddr >> 16) & 0xFF, (broadcastAddr >> 8) & 0xFF,
           broadcastAddr & 0xFF);
}

int main() {
    unsigned long ipAddr;
    int subnetBits;
    printf("Enter the IP Address (in decimal format): ");
    scanf("%ld", &ipAddr);
    printf("Enter the number of Subnet Bits: ");
    scanf("%d", &subnetBits);
    calcSubnet(ipAddr, subnetBits);
    return 0;
}
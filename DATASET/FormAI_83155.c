//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: peaceful
#include <stdio.h>

int main() {
    int subnetMask, bits, i, octet, maskOctet, netAddress, broadcastAddress;
    int totalHosts, totalSubnets, subnetBits, hostBits;

    printf("Please enter the subnet mask (enter the number of bits): ");
    scanf("%d", &subnetMask);

    bits = 32 - subnetMask;
    totalSubnets = 1 << bits;
    subnetBits = bits;

    hostBits = subnetMask - 24;
    totalHosts = 1 << hostBits;

    maskOctet = 256 - (1 << (8 - (subnetMask % 8)));
    octet = subnetMask / 8;

    for (i = 0; i < octet; i++) {
        printf("255");
        if (i < 3) printf(".");
    }

    printf("%d", maskOctet);
    octet++;

    for (i = octet; i < 4; i++) {
        printf(".0");
    }

    printf("\n");

    netAddress = maskOctet + 1;
    broadcastAddress = netAddress + totalHosts - 1;

    printf("The network address is: %d.%d.%d.%d\n", 192, 168, 1, netAddress);
    printf("The broadcast address is: %d.%d.%d.%d\n", 192, 168, 1, broadcastAddress);
    printf("The total number of subnets is: %d\n", totalSubnets);
    printf("The total number of hosts per subnet is: %d\n", totalHosts);

    return 0;
}
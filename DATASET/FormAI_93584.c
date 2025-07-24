//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int prefixLength, subnetMask, numberOfSubnets, numberOfHostsPerSubnet, hostBits;
    unsigned long int subnetAddress, lastPossibleAddress;
    double totalAddresses, bits;

    printf("Enter the prefix length: ");
    scanf("%d", &prefixLength);

    bits = 32 - prefixLength;
    numberOfSubnets = pow(2, bits);
    subnetMask = 256 - numberOfSubnets;
    hostBits = prefixLength - 24;
    numberOfHostsPerSubnet = pow(2, hostBits);
    totalAddresses = numberOfSubnets * numberOfHostsPerSubnet;
    subnetAddress = 192 << 24 | 168 << 16 | 0 << 8 | 0;
    lastPossibleAddress = (subnetAddress + totalAddresses) - 1;

    printf("\nSubnet Mask\t\t: %d.%d.%d.%d\n", 255, 255, 255, subnetMask);
    printf("Subnet Address\t\t: %d.%d.%d.%d\n", (subnetAddress >> 24) & 0xFF, (subnetAddress >> 16) & 0xFF, (subnetAddress >> 8) & 0xFF, subnetAddress & 0xFF);
    printf("Number of Subnets\t: %d\n", numberOfSubnets);
    printf("Number of Hosts/Network\t: %d\n", numberOfHostsPerSubnet);
    printf("Total number of Addresses: %.0f\n", totalAddresses);
    printf("Broadcast Address\t: %d.%d.%d.%d\n", (lastPossibleAddress >> 24) & 0xFF, (lastPossibleAddress >> 16) & 0xFF, (lastPossibleAddress >> 8) & 0xFF, lastPossibleAddress & 0xFF);

    return 0;
}
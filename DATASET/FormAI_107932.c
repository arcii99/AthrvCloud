//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>

int main() {
    unsigned int subnetMask;
    printf("Enter the subnet mask (in CIDR notation): ");
    scanf("%u", &subnetMask);

    unsigned int numAddresses = 1 << (32 - subnetMask);
    printf("Number of addresses: %u\n", numAddresses);

    unsigned int numSubnets = 1 << subnetMask;
    printf("Number of subnets: %u\n", numSubnets);

    unsigned int subnetBits = subnetMask - 24;
    unsigned int numVLSMAddresses = 1 << subnetBits;
    printf("Number of VLSM addresses per subnet: %u\n", numVLSMAddresses);

    unsigned int numVLSMSubnets = numSubnets / numVLSMAddresses;
    printf("Number of VLSM subnets: %u\n", numVLSMSubnets);

    return 0;
}
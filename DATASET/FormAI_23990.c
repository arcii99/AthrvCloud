//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>

int subnetMaskToCIDR(unsigned int subnetMask) {
    int cidr = 0;
    while (subnetMask) {
        cidr += subnetMask & 1;
        subnetMask >>= 1;
    }
    return cidr;
}

int main() {

    printf("Welcome to the cheerful C Subnet Calculator! Let's get started!\n\n");

    printf("Please enter the IP address: ");
    unsigned int ipAddress = 0;
    scanf("%u", &ipAddress);

    printf("Please enter the subnet mask: ");
    unsigned int subnetMask = 0;
    scanf("%u", &subnetMask);

    int cidr = subnetMaskToCIDR(subnetMask);

    unsigned int networkAddress = ipAddress & subnetMask;
    unsigned int broadcastAddress = networkAddress | (~subnetMask);

    printf("\n Results \n");
    printf("IP address: %u\n", ipAddress);
    printf("Subnet Mask: %u\n", subnetMask);
    printf("CIDR notation: /%d\n", cidr);
    printf("Network Address: %u\n", networkAddress);
    printf("Broadcast Address: %u\n", broadcastAddress);

    printf("\n Thanks for using the C Subnet Calculator, hope you have a cheerful day ahead!\n");
    return 0;
}
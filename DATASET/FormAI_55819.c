//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <math.h>

int main() {
    unsigned int prefixLength, subnetMask, ipAddress;
    unsigned int subnetSize, totalSubnets, usableHosts, networkAddress, broadcastAddress;
    
    //Prompt the user for the IP Address and prefix length
    printf("Enter IP Address: ");
    scanf("%u", &ipAddress);

    printf("Enter Prefix Length: ");
    scanf("%u", &prefixLength);

    //Validate prefix length
    if (prefixLength > 32) {
        printf("Invalid Prefix Length\n");
        return 1;
    }

    //Calculate subnet mask from prefix length
    subnetMask = pow(2, 32 - prefixLength) - 1;

    //Calculate subnet size and total subnets
    subnetSize = pow(2, 32 - prefixLength);
    totalSubnets = pow(2, prefixLength);

    //Calculate network address
    networkAddress = ipAddress & (~subnetMask);

    //Calculate broadcast address
    broadcastAddress = networkAddress + subnetSize - 1;

    //Calculate usable hosts per subnet
    usableHosts = subnetSize - 2;

    printf("\nSubnet Size: %u\n", subnetSize);
    printf("Total Subnets: %u\n", totalSubnets);
    printf("Usable Hosts per Subnet: %u\n", usableHosts);
    printf("Network Address: %u\n", networkAddress);
    printf("Broadcast Address: %u\n\n", broadcastAddress);

    return 0;
}
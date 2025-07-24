//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <math.h>

int main()
{
    int subnetMask, numSubnets, numHosts, hostBits, power;
    printf("Enter the subnet mask in bits (ex: 24 for 255.255.255.0): ");
    scanf("%d", &subnetMask);
    numSubnets = pow(2, (subnetMask - 24));
    printf("Number of subnets: %d\n", numSubnets);
    printf("Enter the number of hosts needed per subnet: ");
    scanf("%d", &numHosts);
    hostBits = log2(numHosts + 2);
    power = subnetMask - (24 + hostBits);
    printf("Total number of available hosts per subnet: %d\n", (int)pow(2, hostBits) - 2);
    printf("Number of available host bits: %d\n", hostBits);
    printf("Number of available network bits: %d\n", power);
    printf("Subnet mask: 255.255.255.%d\n", (int)pow(2, power) - 1);
    return 0;
}
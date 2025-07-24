//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <math.h>

int main() {
    int subnetMask;
    int numOfHosts;
    int numSubnets;

    printf("Enter the subnet mask in CIDR notation: ");
    scanf("%d", &subnetMask);

    numOfHosts = pow(2,(32-subnetMask))-2;
    numSubnets = pow(2,subnetMask);

    printf("\nNumber of possible hosts: %d", numOfHosts);
    printf("\nNumber of possible subnets: %d", numSubnets);

    return 0;
}
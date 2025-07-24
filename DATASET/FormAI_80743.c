//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, d, subnetBits, numSubnets, hostsPerSubnet;
    printf("Input IP address in decimal form (e.g. 192.168.1.1):\n");
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    printf("\nInput number of subnet bits:\n");
    scanf("%d", &subnetBits);

    numSubnets = pow(2, subnetBits);
    hostsPerSubnet = pow(2, 32 - subnetBits) - 2;

    printf("\n#########################################################################\n");
    printf("You have entered the IP address: %d.%d.%d.%d\n", a, b, c, d);
    printf("With %d subnet bits, you will get %d subnets and %d hosts per subnet.\n", subnetBits, numSubnets, hostsPerSubnet);
    printf("#########################################################################\n");

    return 0;
}
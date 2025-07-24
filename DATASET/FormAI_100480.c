//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int octet1, octet2, octet3, octet4, netmaskBits, subnetBits, subnetPower, subnets, hosts, bitsLeft, x;
    int subnetOctets[4], wildcardOctets[4], broadcastOctets[4];

    printf("Enter IP address with dot notation: ");
    scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    printf("Enter the number of network mask bits: ");
    scanf("%d", &netmaskBits);

    subnetBits = 32 - netmaskBits;
    subnetPower = pow(2, subnetBits);
    subnets = 256 / subnetPower;
    bitsLeft = 32 - netmaskBits - subnetBits;
    hosts = pow(2, bitsLeft) - 2;

    printf("\nIP address: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
    printf("Network mask (CIDR): /%d\n", netmaskBits);

    subnetOctets[0] = octet1;
    subnetOctets[1] = octet2;
    subnetOctets[2] = octet3;
    subnetOctets[3] = 0;

    wildcardOctets[0] = 255 - (subnetOctets[0] & 255);
    wildcardOctets[1] = 255 - (subnetOctets[1] & 255);
    wildcardOctets[2] = 255 - (subnetOctets[2] & 255);
    wildcardOctets[3] = 255;

    broadcastOctets[0] = subnetOctets[0] | wildcardOctets[0];
    broadcastOctets[1] = subnetOctets[1] | wildcardOctets[1];
    broadcastOctets[2] = subnetOctets[2] | wildcardOctets[2];
    broadcastOctets[3] = wildcardOctets[3];

    printf("Subnet address: %d.%d.%d.%d\n", subnetOctets[0], subnetOctets[1], subnetOctets[2], subnetOctets[3]);
    printf("Wildcard mask: %d.%d.%d.%d\n", wildcardOctets[0], wildcardOctets[1], wildcardOctets[2], wildcardOctets[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcastOctets[0], broadcastOctets[1], broadcastOctets[2], broadcastOctets[3]);
    printf("Number of subnets: %d\n", subnets);
    printf("Number of hosts per subnet: %d\n", hosts);

    printf("\nSubnet IP addresses:\n");

    for (x = 0; x < subnets; x++) {
        if (x > 0 && x % 8 == 0) {
            printf("\n");
        }
        printf("%d.%d.%d.%d", subnetOctets[0], subnetOctets[1], subnetOctets[2], subnetOctets[3]);
        printf("/%d", netmaskBits + subnetBits);
        printf("\t");
        subnetOctets[3] += subnetPower;
        if (subnetOctets[3] > 255) {
            subnetOctets[3] = 0;
            subnetOctets[2] += 1;
        }
    }

    printf("\n");

    return 0;
}
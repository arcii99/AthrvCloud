//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void calculateSubnet(int subnet, int mask) {
    // Base Case
    if(mask == 0) {
        printf("%d.",subnet);
        return;
    }
    int octet = 256 - (1 << mask);
    int firstOctet = subnet & octet;
    printf("%d.",firstOctet);
    calculateSubnet(subnet - firstOctet, mask - 8);
}

int main() {
    int subnet, mask;
    printf("Enter a subnet address in decimal format: ");
    scanf("%d", &subnet);
    printf("Enter a subnet mask in bits: ");
    scanf("%d", &mask);

    if(mask % 8 != 0 || mask > 32) {
        printf("Invalid subnet mask\n");
        return 1;
    }
    calculateSubnet(subnet, mask);
    printf("\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>

int main() {
    int oct1, oct2, oct3, oct4, subnetBits, subnetMask;

    printf("Enter the IP address in the format X.X.X.X: ");
    scanf("%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4);

    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnetBits);

    subnetMask = 0xffffffff << (32 - subnetBits);

    printf("\nSubnet mask is: %d.%d.%d.%d\n", (subnetMask >> 24) & 0xff, (subnetMask >> 16) & 0xff, (subnetMask >> 8) & 0xff, subnetMask & 0xff);

    return 0;
}
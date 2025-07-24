//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>

int main() {
    unsigned int subnetMask;
    printf("Enter the subnet mask (integer value between 0 and 32):\n");
    scanf("%u", &subnetMask);
    if (subnetMask < 0 || subnetMask > 32) {
        printf("Invalid input. Subnet mask should be an integer between 0 and 32.\n");
        return 0;
    }
    unsigned int numAddresses = 1 << (32 - subnetMask);
    unsigned int numUsableAddresses = (numAddresses > 2 ? numAddresses - 2 : numAddresses);
    unsigned int wildcardMask = (1 << (32 - subnetMask)) - 1;
    unsigned int firstAddress = 0;
    unsigned int lastAddress = 0;
    printf("Number of addresses: %u\n", numAddresses);
    printf("Number of usable addresses: %u\n", numUsableAddresses);
    printf("Wildcard mask: %u.%u.%u.%u\n", (wildcardMask & 0xff000000) >> 24, (wildcardMask & 0x00ff0000) >> 16, (wildcardMask & 0x0000ff00) >> 8, (wildcardMask & 0x000000ff));
    printf("First IP address: %u.%u.%u.%u\n", (firstAddress & 0xff000000) >> 24, (firstAddress & 0x00ff0000) >> 16, (firstAddress & 0x0000ff00) >> 8, (firstAddress & 0x000000ff));
    printf("Last IP address: %u.%u.%u.%u\n", (lastAddress & 0xff000000) >> 24, (lastAddress & 0x00ff0000) >> 16, (lastAddress & 0x0000ff00) >> 8, (lastAddress & 0x000000ff));
    return 0;
}
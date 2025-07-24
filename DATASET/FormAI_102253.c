//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    // Input IP address
    unsigned int ip_address;
    printf("Enter IP address (in decimal): ");
    scanf("%u", &ip_address);

    // Calculate subnet masks
    unsigned int subnet_masks[32];
    unsigned int mask;
    for (int i = 0; i < 32; i++) {
        mask = (~0) << (32 - i);
        subnet_masks[i] = mask;
    }

    // Print subnet masks and network addresses
    printf("\nSubnet Masks:\n");
    printf("------------------\n");
    for (int i = 0; i < 32; i++) {
        printf("%d: %u.%u.%u.%u\n", i, (subnet_masks[i] >> 24) & 0xff, 
                                    (subnet_masks[i] >> 16) & 0xff, 
                                    (subnet_masks[i] >> 8) & 0xff, 
                                    subnet_masks[i] & 0xff);
        printf("Network Address: %u.%u.%u.%u\n", (subnet_masks[i] & ip_address) >> 24, 
                                                 (subnet_masks[i] & ip_address) >> 16, 
                                                 (subnet_masks[i] & ip_address) >> 8, 
                                                 subnet_masks[i] & ip_address);
        printf("------------------\n");
    }

    return 0;
}
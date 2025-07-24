//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int subnet_bits;
    unsigned long int subnet_mask, subnet;
    unsigned char octet1, octet2, octet3, octet4;

    printf("Enter the subnet bits (between 1 and 30): ");
    scanf("%d", &subnet_bits);

    if(subnet_bits < 1 || subnet_bits > 30) {
        printf("Oops! Something is not fishy. Please enter a valid number of subnet bits.\n");
        exit(0);
    }

    subnet_mask = ~((1 << (32 - subnet_bits)) - 1);

    printf("Enter the IP address (format 192.168.1.1): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &octet1, &octet2, &octet3, &octet4);

    subnet = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;

    printf("\nCalculating subnet...\n");

    printf("\nSubnet mask: %hhu.%hhu.%hhu.%hhu", (unsigned char)(subnet_mask >> 24), (unsigned char)(subnet_mask >> 16), (unsigned char)(subnet_mask >> 8), (unsigned char)subnet_mask);

    printf("\nNetwork address: %hhu.%hhu.%hhu.%hhu", (unsigned char)(subnet & subnet_mask) >> 24, (unsigned char)(subnet & subnet_mask) >> 16, (unsigned char)(subnet & subnet_mask) >> 8, (unsigned char)subnet & subnet_mask);

    printf("\nBroadcast address: %hhu.%hhu.%hhu.%hhu", (unsigned char)((subnet & subnet_mask) | ~subnet_mask) >> 24, (unsigned char)((subnet & subnet_mask) | ~subnet_mask) >> 16, (unsigned char)((subnet & subnet_mask) | ~subnet_mask) >> 8, (unsigned char)(subnet & subnet_mask) | ~subnet_mask);

    printf("\nMask bits: %d", subnet_bits);

    printf("\n\nDone! Yay!\n");

    return 0;
}
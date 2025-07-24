//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>

// a function to calculate the subnet mask
void subnet_mask(int mask, int *result) {
    int i, j, k, decimal_value;
    for (i = 0; i < 4; i++) {
        decimal_value = 0;
        for (j = 0; j < 8; j++) {
            if (mask > 0) {
                decimal_value += 1 << (7 - j);
                mask--;
            }
        }
        result[i] = decimal_value;
    }
}

int main() {
    int subnet_bits, subnet_mask_decimal[4];
    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnet_bits);

    // check if the input is valid
    if (subnet_bits < 1 || subnet_bits > 30) {
        printf("Invalid input!\n");
        return 1;
    }

    subnet_mask(subnet_bits, subnet_mask_decimal);

    printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask_decimal[0], subnet_mask_decimal[1], subnet_mask_decimal[2], subnet_mask_decimal[3]);

    // calculate the number of subnets and hosts
    int subnets = 1 << subnet_bits;
    int hosts = (1 << (32 - subnet_bits)) - 2;

    printf("Number of subnets: %d\n", subnets);
    printf("Number of hosts: %d\n", hosts);

    return 0;
}
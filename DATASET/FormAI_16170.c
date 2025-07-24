//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <math.h>

int main() {
    int subnet_mask_length, n_subnet_bits, n_host_bits;
    printf("Enter the subnet mask length (between 1 and 32): ");
    scanf("%d", &subnet_mask_length);
    if (subnet_mask_length < 1 || subnet_mask_length > 32) {
        printf("Invalid subnet mask length.\n");
        return 1;
    }
    n_subnet_bits = subnet_mask_length;
    n_host_bits = 32 - subnet_mask_length;
    printf("Number of subnet bits: %d\n", n_subnet_bits);
    printf("Number of host bits: %d\n", n_host_bits);
    printf("Number of possible subnets: %d\n", pow(2, n_subnet_bits));
    printf("Number of possible hosts per subnet: %d\n", pow(2, n_host_bits) - 2);
    return 0;
}
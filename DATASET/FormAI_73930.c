//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subnet_calc(int subnet_mask) {
    int host_bits = 32 - subnet_mask;
    int num_hosts = 1 << host_bits;
    int num_subnets = 1 << (subnet_mask - 24);

    printf("\n");
    printf("Subnet Mask: %d bits\n", subnet_mask);
    printf("Number of subnets: %d\n", num_subnets);
    printf("Number of hosts per subnet: %d\n", num_hosts);
    printf("\n");

    return;
}

int main() {
    char input[16];
    int subnet_mask;

    printf("Enter the subnet mask in CIDR notation (e.g., 24): ");
    fgets(input, 16, stdin);

    if(sscanf(input, "%d", &subnet_mask) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if(subnet_mask < 24 || subnet_mask > 30) {
        printf("Invalid subnet mask (must be between 24 and 30)\n");
        return 1;
    }

    subnet_calc(subnet_mask);

    return 0;
}
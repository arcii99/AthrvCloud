//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
/* The Subnet Calculator Program */

#include <stdio.h>

/* Function to count the number of ones in a binary number */
int count_ones(int num) {
    int count = 0;
    while(num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

/* The main function */
int main() {
    int subnet_bits;
    int mask = 0xFFFFFFFF;

    /* Prompt the user to enter the number of subnet bits */
    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnet_bits);

    /* Calculate the subnet mask */
    mask <<= (32 - subnet_bits);

    /* Output the subnet mask */
    printf("The subnet mask is %d.%d.%d.%d\n",
        mask >> 24 & 0xFF,
        mask >> 16 & 0xFF,
        mask >> 8 & 0xFF,
        mask & 0xFF);

    /* Determine the number of subnets */
    int num_subnets = 1 << subnet_bits;

    /* Output the number of subnets */
    printf("The number of subnets is %d\n", num_subnets);

    /* Determine the number of hosts per subnet */
    int num_hosts = 32 - count_ones(mask);

    /* Output the number of hosts per subnet */
    printf("The number of hosts per subnet is %d\n", 1 << num_hosts);

    return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    int subnet_mask_length;
    printf("Enter the subnet mask length between 1-32 (inclusive):\n");
    scanf("%d", &subnet_mask_length);

    // Validating input
    if(subnet_mask_length < 1 || subnet_mask_length > 32)
    {
        printf("Invalid input! Subnet mask length should be between 1-32.\n");
        return 0;
    }

    // Number of hosts
    int num_of_hosts = pow(2, 32 - subnet_mask_length) - 2;

    // Calculating network bits and host bits
    int network_bits = 32 - subnet_mask_length;
    int host_bits = subnet_mask_length;

    // Displaying results
    printf("Number of hosts: %d\n", num_of_hosts);
    printf("Network bits: %d\n", network_bits);
    printf("Host bits: %d\n", host_bits);

    return 0;
}
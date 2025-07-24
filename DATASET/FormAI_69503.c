//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the curious C Subnet Calculator!\n");
    
    int subnet_mask = 0;
    printf("Please enter the subnet mask (from 0 to 32): ");
    scanf("%d", &subnet_mask);
    
    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid subnet mask! Please enter a number between 0 and 32.\n");
        return 1;
    }
    
    printf("Calculating subnet range...\n");
    int subnet_bits = 32 - subnet_mask;
    int num_subnets = 1 << subnet_bits;
    int num_hosts = (1 << subnet_mask) - 2;
    
    printf("Subnet mask: /%d\n", subnet_mask);
    printf("Number of subnets: %d\n", num_subnets);
    printf("Number of hosts per subnet: %d\n", num_hosts);
    
    printf("Subnet range: ");
    for (int i = 0; i < num_subnets; i++) {
        printf("%d.%d.%d.%d - %d.%d.%d.%d\n", i, i, i, 1, i, i, i, num_hosts);
    }
    
    printf("Thank you for using the curious C Subnet Calculator!\n");
    return 0;
}
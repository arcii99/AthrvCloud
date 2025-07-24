//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("Welcome to the curious Subnet Calculator!\n");
    
    int num_bits, num_hosts, num_subnets;
    unsigned long address, subnet_mask;
    
    printf("Enter IP address (must be in decimal format): ");
    scanf("%lu", &address);
    
    printf("Enter number of subnet bits: ");
    scanf("%d", &num_bits);
    
    num_subnets = 1 << num_bits;
    
    subnet_mask = ((unsigned long)1 << 32) - 1;
    subnet_mask = subnet_mask << (32 - num_bits);
    
    num_hosts = subnet_mask == 0 ? 0 : (1 << (32 - num_bits)) - 2;
    
    printf("\n");
    printf("IP Address: %lu\n", address);
    printf("Subnet Mask: %lu\n", subnet_mask);
    printf("Number of Subnets: %d\n", num_subnets);
    printf("Number of Hosts per Subnet: %d\n", num_hosts);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <string.h>

unsigned long get_subnet_mask(unsigned int bits) {
    unsigned long mask = 0;
    unsigned int i;
    
    for (i = 0; i < bits; ++i) {
        mask |= 1UL << (32 - i - 1);
    }
    
    return mask;
}

int main() {
    char ip_address[16];
    unsigned int subnet_bits;
    unsigned long subnet_mask;
    
    printf("Welcome to the C Subnet Calculator!\n");
    
    // Get user input for IP address and subnet bits
    printf("Please enter the IP address: ");
    scanf("%s", ip_address);
    printf("Please enter the number of subnet bits: ");
    scanf("%u", &subnet_bits);
    
    // Calculate the subnet mask
    subnet_mask = get_subnet_mask(subnet_bits);
    
    // Print out the results
    printf("\nIP address: %s\n", ip_address);
    printf("Subnet bits: %u\n", subnet_bits);
    printf("Subnet mask: %d.%d.%d.%d\n", 
           (subnet_mask >> 24) & 0xFF,
           (subnet_mask >> 16) & 0xFF,
           (subnet_mask >> 8) & 0xFF,
           subnet_mask & 0xFF);
    
    return 0;
}
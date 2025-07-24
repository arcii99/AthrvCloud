//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t ip_addr, subnet_mask;
    int bits_set;
    
    printf("Enter IP address (in hex, without 0x prefix): ");
    scanf("%x", &ip_addr);
    
    printf("Enter subnet mask (in hex, without 0x prefix): ");
    scanf("%x", &subnet_mask);
    
    // Count number of bits set in the subnet mask
    bits_set = 0;
    uint32_t bit = 1;
    for (int i = 0; i < 32; i++) {
        if ((subnet_mask & bit) != 0) {
            bits_set++;
        }
        bit <<= 1;
    }
    
    // Calculate network and host addresses
    uint32_t network_addr = ip_addr & subnet_mask;
    uint32_t host_addr = ip_addr & ~subnet_mask;
    
    // Calculate number of hosts in the subnet
    uint32_t num_hosts = 1 << (32 - bits_set) - 2;  // Subtract 2 for network and broadcast addresses
    
    // Print results
    printf("\n");
    printf("IP address: %08x\n", ip_addr);
    printf("Subnet mask: %08x\n", subnet_mask);
    printf("\n");
    printf("Network address: %08x\n", network_addr);
    printf("Host address: %08x\n", host_addr);
    printf("\n");
    printf("Number of bits set in subnet mask: %d\n", bits_set);
    printf("Number of hosts in subnet: %u\n", num_hosts);
    
    return 0;
}
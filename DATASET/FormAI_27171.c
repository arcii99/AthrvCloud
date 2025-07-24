//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int oct1, oct2, oct3, oct4, prefix, subnet, hosts, subnet_bits, total_hosts;
    printf("Enter the IP address (in the format X.X.X.X): ");
    scanf("%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4);
    printf("Enter the prefix length (number of bits used for the network): ");
    scanf("%d", &prefix);
    
    // Error checking
    if (prefix > 32 || prefix < 0) {
        printf("ERROR: Prefix length must be between 0 and 32.\n");
        exit(EXIT_FAILURE);
    }
    
    // Calculate subnet bits and subnet mask
    subnet_bits = 32 - prefix;
    subnet = pow(2, subnet_bits) - 1;
    
    // Calculate total number of hosts
    total_hosts = pow(2, 32 - prefix);
    
    // Calculate number of hosts per subnet
    hosts = total_hosts / (subnet + 1);
    
    // Print subnet calculator results
    printf("\nIP Address: %d.%d.%d.%d\n", oct1, oct2, oct3, oct4);
    printf("Prefix Length: %d\n", prefix);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet, subnet, subnet, subnet);
    printf("Number of Hosts Per Subnet: %d\n", hosts);
    printf("Total Number of Hosts: %d\n", total_hosts);
    
    return 0;
}
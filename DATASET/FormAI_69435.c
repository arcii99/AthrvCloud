//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>

int main() {

    unsigned int network_address, subnet_mask, cidr_notation, node_bits;
    unsigned int max_possible_hosts, max_possible_subnets;

    // Get input from user
    printf("Enter the Network Address (in decimal notation): ");
    scanf("%u", &network_address);

    printf("Enter the Subnet Mask (in decimal notation): ");
    scanf("%u", &subnet_mask);

    printf("Enter the CIDR Notation: ");
    scanf("%u", &cidr_notation);

    // Calculate the number of node bits
    node_bits = 32 - cidr_notation;

    // Calculate the number of maximum possible hosts
    max_possible_hosts = (1 << node_bits) - 2;

    // Calculate the number of maximum possible subnets
    max_possible_subnets = 1 << cidr_notation;

    // Print the result
    printf("\nNetwork Address: %u", network_address);
    printf("\nSubnet Mask: %u", subnet_mask);
    printf("\nCIDR Notation: %u", cidr_notation);
    printf("\nNumber of Node Bits: %u", node_bits);
    printf("\nMaximum Possible Hosts: %u", max_possible_hosts);
    printf("\nMaximum Possible Subnets: %u", max_possible_subnets);

    return 0;
}
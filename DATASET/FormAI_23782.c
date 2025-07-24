//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int subnet_mask, num_hosts, cidr, subnets, hosts;
    long int total_hosts, net_bits, num_subnets, num_addresses;
    printf("\nEnter the subnet mask (/number): ");
    scanf("%d",&subnet_mask);
    printf("\nEnter the number of hosts: ");
    scanf("%d",&num_hosts);
    cidr = 32 - subnet_mask;
    subnets = pow(2, cidr);
    hosts = pow(2, 32 - subnet_mask) - 2;

    if (num_hosts > hosts) {
        printf("\nError: Not enough hosts.");
        exit(0);
    }

    total_hosts = num_hosts + 2;
    num_addresses = pow(2, subnet_mask);
    net_bits = log(num_hosts + 2) / log(2);
    num_subnets = pow(2, subnet_mask - net_bits);
    
    printf("\nThe subnet mask: /%d", subnet_mask);
    printf("\nThe CIDR notation: %d", cidr);
    printf("\nThe number of subnets: %ld", num_subnets);
    printf("\nThe number of hosts per subnet: %ld", total_hosts);
    printf("\nThe total number of addresses: %ld", num_addresses);
    
    return 0;
}
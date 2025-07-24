//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: statistical
// C Program to Calculate Subnet Masks and Network Addresses
// using bitwise operations and statistical analysis

#include <stdio.h>

int main() {

    int network_address, subnet_mask, host_bits, max_hosts, network_bits;
    int total_subnets, subnets_available, hosts_available;
    float network_utilization;

    // Prompt the user to enter the network address and subnet mask
    printf("Enter the Network Address: ");
    scanf("%d", &network_address);
    printf("Enter the Subnet Mask: ");
    scanf("%d", &subnet_mask);

    // Calculate the number of host bits, network bits, and maximum hosts
    host_bits = 32 - subnet_mask;
    network_bits = subnet_mask;
    max_hosts = (1 << host_bits) - 2;

    // Display the network and subnet information
    printf("\nNetwork Address: %d.%d.%d.%d\n", (network_address >> 24) & 0xff, (network_address >> 16) & 0xff, (network_address >> 8) & 0xff, network_address & 0xff);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnet_mask >> 24) & 0xff, (subnet_mask >> 16) & 0xff, (subnet_mask >> 8) & 0xff, subnet_mask & 0xff);
    printf("Host Bits: %d | Network Bits: %d | Max Hosts: %d\n", host_bits, network_bits, max_hosts);

    // Calculate the total number of subnets
    total_subnets = 1 << network_bits;

    // Display the total number of subnets available
    printf("\nTotal Subnets Available: %d\n", total_subnets);

    // Prompt the user to enter the desired number of subnets
    printf("Enter the Number of Subnets Required: ");
    scanf("%d", &subnets_available);

    // Calculate the hosts available per subnet
    hosts_available = max_hosts / subnets_available;

    // Calculate the network utilization
    network_utilization = ((float)hosts_available / (float)max_hosts) * 100.0;

    // Display the subnet and host information
    printf("\nSubnets Required: %d | Hosts per Subnet: %d | Network Utilization: %.2f\n", subnets_available, hosts_available, network_utilization);

    return 0;
}
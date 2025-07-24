//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include<stdio.h>
#include<math.h>

int main()
{
    unsigned int ip, subnet_mask, network_address, broadcast_address, first_address, last_address, num_host_bits, num_hosts;

    printf("Enter IP Address: ");
    scanf("%u", &ip);

    printf("Enter Subnet Mask: ");
    scanf("%u", &subnet_mask);

    // Calculate Network Address
    network_address = ip & subnet_mask;

    // Calculate Broadcast Address
    broadcast_address = network_address | ~subnet_mask;

    // Calculate Number of Host Bits
    num_host_bits = 32 - log2(subnet_mask);

    // Calculate Number of Hosts
    num_hosts = pow(2, num_host_bits) - 2;

    // Calculate First Address
    first_address = network_address + 1;

    // Calculate Last Address
    last_address = broadcast_address - 1;

    // Print Subnet Details
    printf("\nNetwork Address: %u.%u.%u.%u\n", (network_address >> 24) & 0xff, (network_address >> 16) & 0xff, (network_address >> 8) & 0xff, network_address & 0xff);
    printf("Broadcast Address: %u.%u.%u.%u\n", (broadcast_address >> 24) & 0xff, (broadcast_address >> 16) & 0xff, (broadcast_address >> 8) & 0xff, broadcast_address & 0xff);
    printf("First Usable Address: %u.%u.%u.%u\n", (first_address >> 24) & 0xff, (first_address >> 16) & 0xff, (first_address >> 8) & 0xff, first_address & 0xff);
    printf("Last Usable Address: %u.%u.%u.%u\n", (last_address >> 24) & 0xff, (last_address >> 16) & 0xff, (last_address >> 8) & 0xff, last_address & 0xff);
    printf("Number of Hosts: %u\n", num_hosts);

    return 0;
}
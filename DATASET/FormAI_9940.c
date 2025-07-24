//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int subnet_mask;  // to store the user-provided subnet mask
    unsigned int num_hosts;  // to store the number of hosts per subnet

    printf("Enter the subnet mask (in CIDR notation): ");
    scanf("%u", &subnet_mask);

    num_hosts = (1 << (32 - subnet_mask)) - 2;  // calculate the number of hosts per subnet

    printf("\n--------------------------------------------------------\n");
    printf("                   Subnet Calculator                      \n");
    printf("--------------------------------------------------------\n");
    printf("Subnet Mask: /%u\n", subnet_mask);
    printf("Number of Hosts per Subnet: %u\n", num_hosts);
    
    // calculate the subnet address
    printf("Enter the IP address in dotted-decimal format: ");
    unsigned int ip_address[4];  // to store the user-provided IP address
    scanf("%u.%u.%u.%u", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);

    // calculate the network address by ANDing the IP address with the subnet mask
    unsigned int network_address[4];
    network_address[0] = ip_address[0] & (255 << (24 - subnet_mask));
    network_address[1] = ip_address[1] & (255 << (16 - subnet_mask)) >> 8;
    network_address[2] = ip_address[2] & (255 << (8 - subnet_mask)) >> 16;
    network_address[3] = ip_address[3] & (255 << (0 - subnet_mask)) >> 24;

    printf("Network Address: %u.%u.%u.%u\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("--------------------------------------------------------\n");

    return 0;
}
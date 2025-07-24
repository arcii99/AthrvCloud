//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int ip;
    int prefix;

    printf("Enter IP address in decimal notation (eg. 192.168.1.1): ");
    scanf("%u", &ip);

    printf("Enter prefix length: ");
    scanf("%d", &prefix);

    int subnet_bits = 32 - prefix;
    unsigned int subnet_mask = pow(2, subnet_bits) - 1;
    subnet_mask <<= prefix;

    unsigned int subnet_id = ip & subnet_mask;
    unsigned int broadcast_addr = subnet_id | (~subnet_mask);

    unsigned int total_addresses = pow(2, subnet_bits);
    unsigned int usable_addresses = total_addresses - 2;

    printf("\n");
    printf("Subnet ID: %u.%u.%u.%u\n", (subnet_id >> 24) & 0xff, (subnet_id >> 16) & 0xff, (subnet_id >> 8) & 0xff, subnet_id & 0xff);
    printf("Broadcast Address: %u.%u.%u.%u\n", (broadcast_addr >> 24) & 0xff, (broadcast_addr >> 16) & 0xff, (broadcast_addr >> 8) & 0xff, broadcast_addr & 0xff);
    printf("Total Addresses: %u\n", total_addresses);
    printf("Usable Addresses: %u\n", usable_addresses);

    return 0;
}
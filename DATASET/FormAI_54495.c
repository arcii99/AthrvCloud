//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    unsigned int subnet_mask, mask_bits, num_subnets, num_hosts;
    unsigned int octet1, octet2, octet3, octet4;
    unsigned int net_id1, net_id2, net_id3, net_id4;
    unsigned int broadcast_addr1, broadcast_addr2, broadcast_addr3, broadcast_addr4;
    unsigned int range_start1, range_start2, range_start3, range_start4;
    unsigned int range_end1, range_end2, range_end3, range_end4;

    printf("Enter IP address in octets (XXX.XXX.XXX.XXX): ");
    scanf("%u.%u.%u.%u", &octet1, &octet2, &octet3, &octet4);

    printf("\nEnter subnet mask in decimal notation (e.g. 255.255.255.0 = 24): ");
    scanf("%u", &mask_bits);

    subnet_mask = (0xFFFFFFFF << (32 - mask_bits)) & 0xFFFFFFFF;

    num_subnets = pow(2, mask_bits - 24);
    num_hosts = pow(2, 32 - mask_bits) - 2;

    net_id1 = subnet_mask & octet1;
    net_id2 = subnet_mask & octet2;
    net_id3 = subnet_mask & octet3;
    net_id4 = subnet_mask & octet4;

    broadcast_addr1 = net_id1 | (~subnet_mask & 0xFF);
    broadcast_addr2 = net_id2 | (~subnet_mask & 0xFF00) >> 8;
    broadcast_addr3 = net_id3 | (~subnet_mask & 0xFF0000) >> 16;
    broadcast_addr4 = net_id4 | (~subnet_mask & 0xFF000000) >> 24;

    range_start1 = net_id1;
    range_start2 = net_id2;
    range_start3 = net_id3;
    range_start4 = net_id4 + 1;

    range_end1 = broadcast_addr1;
    range_end2 = broadcast_addr2;
    range_end3 = broadcast_addr3;
    range_end4 = broadcast_addr4 - 1;

    printf("\n====================================================\n");
    printf("                    SUMMARY                         \n");
    printf("====================================================\n\n");
    printf("IP Address: %u.%u.%u.%u\n", octet1, octet2, octet3, octet4);
    printf("Subnet Mask: %u.%u.%u.%u\n", subnet_mask >> 24,
        (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);
    printf("Number of Subnets: %u\n", num_subnets);
    printf("Number of Hosts per Subnet: %u\n", num_hosts);
    printf("\n----------------------------------------------------\n");
    printf("                NETWORK INFORMATION                  \n");
    printf("----------------------------------------------------\n\n");
    printf("Network ID: %u.%u.%u.%u\n", net_id1, net_id2, net_id3, net_id4);
    printf("Broadcast Address: %u.%u.%u.%u\n", broadcast_addr1, broadcast_addr2, broadcast_addr3, broadcast_addr4);
    printf("Range of Usable IP Addresses: %u.%u.%u.%u - %u.%u.%u.%u\n", range_start1, range_start2, range_start3, range_start4,
        range_end1, range_end2, range_end3, range_end4);

    return 0;
}
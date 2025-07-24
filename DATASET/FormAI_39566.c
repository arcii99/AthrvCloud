//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int subnet_bits = 0;
    int octet_values[4] = {0};
    int octets[4] = {0};
    int subnet_octet = 0, subnet_mask = 0;
    int i, s;
    int network_address[4] = {0};
    int broadcast_address[4] = {0};
    int total_hosts = 0;

    printf("Enter Subnet Bits: ");
    scanf("%d", &subnet_bits);
    printf("Enter IP Address in dotted decimal notation: ");
    scanf("%d.%d.%d.%d", &octet_values[0], &octet_values[1], &octet_values[2], &octet_values[3]);

    // calculate total number of subnets and hosts per subnet
    int total_subnets = pow(2, subnet_bits);
    total_hosts = pow(2, (32 - subnet_bits)) - 2;
    printf("Total Subnets: %d\n", total_subnets);
    printf("Total Hosts: %d\n", total_hosts);

    // calculate subnet mask and subnet octet
    for(i = 0; i < 4; i++) {
        s = (subnet_bits >= 8) ? 8 : subnet_bits;
        subnet_bits -= s;
        subnet_mask = 256 - pow(2, (8 - s));
        subnet_octet = octet_values[i] & subnet_mask;
        octets[i] = subnet_octet;
    }

    printf("\nSubnet Mask: %d.%d.%d.%d\n", subnet_mask, subnet_mask, subnet_mask, subnet_mask);
    printf("Subnet Octet: %d.%d.%d.%d\n", octets[0], octets[1], octets[2], octets[3]);

    // calculate network address and broadcast address
    for(i = 0; i < 4; i++) {
        network_address[i] = octets[i] & octet_values[i];
        broadcast_address[i] = (octets[i] | (~subnet_mask)) & octet_values[i];
    }

    printf("\nNetwork Address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);

    return 0;
}
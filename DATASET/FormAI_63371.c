//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_binary(unsigned int num, int len) {
    for (int i = len-1; i >= 0; i--) {
        if (num & (1u << i)) printf("1");
        else printf("0");
    }
}

int main() {
    unsigned int address, subnet_mask;
    printf("Enter the IP address in decimal notation: ");
    scanf("%u", &address);

    printf("Enter the subnet mask in decimal notation: ");
    scanf("%u", &subnet_mask);

    int cidr = 0;
    for (int i = 31; i >= 0; i--) {
        if (subnet_mask & (1u << i)) cidr++;
        else break;
    }

    int host_bits = 32-cidr;
    unsigned int network_address = address & subnet_mask;
    unsigned int total_hosts = pow(2, host_bits)-2;

    printf("\n");
    printf("Subnet Mask: ");
    print_binary(subnet_mask, 32);
    printf("\n");

    printf("CIDR Notation: /%d\n", cidr);

    printf("Network Address: %u\n", network_address);

    printf("Number of Hosts: %u\n", total_hosts);

    printf("First Host: %u\n", network_address+1);

    printf("Last Host: %u\n", network_address+total_hosts);

    printf("Broadcast Address: %u\n", network_address+total_hosts+1);

    return 0;
}
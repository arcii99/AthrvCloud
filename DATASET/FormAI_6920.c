//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int MAX_IPV4_LENGTH = 16;

unsigned long get_IPv4_decimal(const char *ipv4_address);

unsigned int get_subnet_mask_decimal(int subnet_mask);

char *get_IPv4_from_decimal(unsigned long decimal);

void print_subnet_summary(const char *ipv4_address, int mask_bits, unsigned int subnet_mask);

void print_all_subnets(const char *ipv4_address, int mask_bits, unsigned int subnet_mask);

int main() {
    char ipv4_address[MAX_IPV4_LENGTH];
    int mask_bits;

    printf("Enter IPv4 address: ");
    scanf("%s", ipv4_address);

    printf("Enter subnet mask bits: ");
    scanf("%d", &mask_bits);

    unsigned int subnet_mask_decimal = get_subnet_mask_decimal(mask_bits);

    print_subnet_summary(ipv4_address, mask_bits, subnet_mask_decimal);

    printf("\n%s subnets:\n", ipv4_address);
    print_all_subnets(ipv4_address, mask_bits, subnet_mask_decimal);

    return 0;
}

unsigned long get_IPv4_decimal(const char *ipv4_address) {
    int p1, p2, p3, p4;
    sscanf(ipv4_address, "%d.%d.%d.%d", &p1, &p2, &p3, &p4);
    unsigned long decimal = (p1 << 24) | (p2 << 16) | (p3 << 8) | p4;
    return decimal;
}

unsigned int get_subnet_mask_decimal(int subnet_mask) {
    unsigned int decimal = (unsigned int) pow(2, subnet_mask) - 1;
    decimal <<= (32 - subnet_mask);
    return decimal;
}

char *get_IPv4_from_decimal(unsigned long decimal) {
    char *ipv4_address = (char *) malloc(MAX_IPV4_LENGTH * sizeof(char));
    unsigned char bytes[4];
    bytes[0] = decimal >> 24;
    bytes[1] = (decimal >> 16) & 0xFF;
    bytes[2] = (decimal >> 8) & 0xFF;
    bytes[3] = decimal & 0xFF;
    sprintf(ipv4_address, "%d.%d.%d.%d", bytes[0], bytes[1], bytes[2], bytes[3]);
    return ipv4_address;
}

void print_subnet_summary(const char *ipv4_address, int mask_bits, unsigned int subnet_mask) {
    printf("\nSubnet addresses summary for %s/%d:\n", ipv4_address, mask_bits);

    unsigned long decimal = get_IPv4_decimal(ipv4_address);
    unsigned long network_address = decimal & subnet_mask;
    unsigned long broadcast_address = network_address | ~subnet_mask;

    printf("Network address: %s\n", get_IPv4_from_decimal(network_address));
    printf("Broadcast address: %s\n", get_IPv4_from_decimal(broadcast_address));
    printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask >> 24, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);
}

void print_all_subnets(const char *ipv4_address, int mask_bits, unsigned int subnet_mask) {
    unsigned long decimal = get_IPv4_decimal(ipv4_address);
    int host_bits = 32 - mask_bits;
    unsigned long num_hosts = (unsigned long) pow(2, host_bits) - 2;

    unsigned long network_address = decimal & subnet_mask;
    unsigned long host_bits_mask = (unsigned long) pow(2, host_bits) - 1;

    int num_subnets = pow(2, host_bits);
    unsigned long subnet_size = pow(2, host_bits);

    for (int i = 0; i < num_subnets; i++) {
        unsigned long subnet_network_address = network_address + (i * subnet_size);
        unsigned long subnet_broadcast_address = subnet_network_address | ~host_bits_mask;

        printf("%s/%d subnet %d:\n", ipv4_address, mask_bits, i+1);
        printf("Network address: %s\n", get_IPv4_from_decimal(subnet_network_address));
        printf("Broadcast address: %s\n", get_IPv4_from_decimal(subnet_broadcast_address));
        printf("Number of hosts: %lu\n", num_hosts);
        printf("\n");
    }
}
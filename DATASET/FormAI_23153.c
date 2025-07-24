//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {

    // Input validation
    if(argc != 3) {
        printf("Usage: ./subnet_calculator <IP/CIDR> <subnets>\n");
        return 1;
    }

    char *ip_cidr = argv[1];
    int subnets = atoi(argv[2]);
    int cidr;

    // Parse IP/CIDR
    char *ip;
    char *cidr_str;
    ip = strtok(ip_cidr, "/");
    cidr_str = strtok(NULL, "/");
    cidr = atoi(cidr_str);

    // Validate IP address
    struct in_addr addr;
    int success = inet_pton(AF_INET, ip, &addr);

    if(success == 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Calculate subnet mask and network bits
    int network_bits = 32 - cidr;
    unsigned long subnet_mask = (1 << cidr) - 1;

    // Check if subnets are valid
    if(subnets > (int) pow(2, network_bits)) {
        printf("Too many subnets requested, %d is the maximum\n", (int) pow(2, network_bits));
        return 1;
    }

    // Calculate new subnet mask
    unsigned long new_subnet_mask = (subnet_mask >> network_bits) << network_bits;

    // Calculate new network mask
    unsigned long new_network_mask = ~subnet_mask;

    // Calculate subnet size
    int subnet_size = (int) pow(2, network_bits);

    // Calculate total number of addresses in network
    int total_addresses = (int) pow(2, cidr);

    // Calculate number of addresses per subnet
    int addresses_per_subnet = total_addresses / subnets;

    // Calculate CIDR for subnets
    int new_cidr = cidr + network_bits;

    // Print network information
    printf("IP Address: %s/%d\n", ip, cidr);
    printf("Subnets requested: %d\n", subnets);
    printf("Subnet mask: %lu.%lu.%lu.%lu\n", (subnet_mask >> 24) & 0xff , (subnet_mask >> 16) & 0xff, (subnet_mask >> 8) & 0xff, subnet_mask & 0xff);
    printf("New subnet mask: %lu.%lu.%lu.%lu\n", (new_subnet_mask >> 24) & 0xff , (new_subnet_mask >> 16) & 0xff, (new_subnet_mask >> 8) & 0xff, new_subnet_mask & 0xff);
    printf("Network mask: %lu.%lu.%lu.%lu\n", (new_network_mask >> 24) & 0xff , (new_network_mask >> 16) & 0xff, (new_network_mask >> 8) & 0xff, new_network_mask & 0xff);
    printf("Subnet size: %d\n", subnet_size);
    printf("Total number of addresses in network: %d\n", total_addresses);
    printf("Number of addresses per subnet: %d\n", addresses_per_subnet);
    printf("CIDR for subnets: %d\n", new_cidr);

    return 0;
}
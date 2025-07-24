//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Subnet {
    int subnet_num;
    char subnet_address[16];
    int mask_bits;
    char mask_address[16];
    char broadcast_address[16];
    char first_host_address[16];
    char last_host_address[16];
    int num_hosts;
};

void print_subnet_table(struct Subnet *subnet, int num_subnets) {
    printf("----------------------------------------------------------------\n");
    printf("| Subnet # | Subnet Address | Mask Bits | Mask Address | Broadcast Address | First Host Address | Last Host Address | # of Hosts |\n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("|%10d|%16s|%11d|%14s|%20s|%20s|%19s|%11d|\n", subnet[i].subnet_num, subnet[i].subnet_address, subnet[i].mask_bits, subnet[i].mask_address, subnet[i].broadcast_address, subnet[i].first_host_address, subnet[i].last_host_address, subnet[i].num_hosts);
    }
    printf("----------------------------------------------------------------\n");
}

int main() {
    unsigned int ip_address, mask_bits;
    struct Subnet *network = NULL;
    int num_subnets;

    printf("Enter IP Address: ");
    scanf("%u", &ip_address);
    printf("Enter number of Subnets: ");
    scanf("%d", &num_subnets);

    network = malloc(num_subnets * sizeof(struct Subnet));
    if (network == NULL) {
        printf("Error: Failed to allocate network memory\n");
        return -1;
    }

    printf("IP Address: %u\n", ip_address);
    printf("Number of Subnets: %d\n", num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("\nSubnet %d:\n", i+1);
        printf("Enter Mask Bits: ");
        scanf("%d", &mask_bits);

        int num_hosts = pow(2, 32-mask_bits)-2;
        int subnet_mask = pow(2, mask_bits)-1;
        int subnet_id = ((ip_address >> mask_bits) << mask_bits);
        int broadcast_id = subnet_id + subnet_mask;

        // Subnet Address
        sprintf(network[i].subnet_address, "%d.%d.%d.%d", (subnet_id >> 24) & 0xFF, (subnet_id >> 16) & 0xFF, (subnet_id >> 8) & 0xFF, subnet_id & 0xFF);

        // Mask Address
        sprintf(network[i].mask_address, "%d.%d.%d.%d", (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);

        // Broadcast Address
        sprintf(network[i].broadcast_address, "%d.%d.%d.%d", (broadcast_id >> 24) & 0xFF, (broadcast_id >> 16) & 0xFF, (broadcast_id >> 8) & 0xFF, broadcast_id & 0xFF);

        // First Host Address
        sprintf(network[i].first_host_address, "%d.%d.%d.%d", ((subnet_id >> 24) & 0xFF), ((subnet_id >> 16) & 0xFF), ((subnet_id >> 8) & 0xFF), (subnet_id & 0xFF) + 1);

        // Last Host Address
        sprintf(network[i].last_host_address, "%d.%d.%d.%d", ((broadcast_id >> 24) & 0xFF), ((broadcast_id >> 16) & 0xFF), ((broadcast_id >> 8) & 0xFF), (broadcast_id & 0xFF) - 1);

        // Number of Hosts
        network[i].num_hosts = num_hosts;
        network[i].subnet_num = i+1;
    }

    printf("\n\nSubnet Table:\n\n");
    print_subnet_table(network, num_subnets);

    free(network);
    return 0;
}
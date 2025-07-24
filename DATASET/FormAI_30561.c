//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
// Retro Style C Subnet Calculator

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 16 // Maximum length of IP Address string

int main() {
    char ip[MAX_IP_LENGTH];
    int subnet_mask, n_subnet_bits, n_host_bits, n_subnets, n_hosts;

    printf("+-------------------------------+\n");
    printf("| Retro Style Subnet Calculator |\n");
    printf("+-------------------------------+\n");

    printf("\nEnter an IP Address: ");
    scanf("%s", ip);
    printf("Enter Subnet Mask (CIDR): ");
    scanf("%d", &subnet_mask);

    // Split IP Address into octets
    int ip_octets[4];
    sscanf(ip, "%d.%d.%d.%d", &ip_octets[0], &ip_octets[1], &ip_octets[2], &ip_octets[3]);

    // Calculate subnet and host bits
    n_subnet_bits = subnet_mask / 8;
    n_host_bits = 8 - (subnet_mask % 8);

    // Calculate number of subnets and hosts per subnet
    n_subnets = pow(2, 8-n_host_bits);
    n_hosts = pow(2, n_host_bits) - 2;

    // Print Subnet Details
    printf("\n+----------------------+\n");
    printf("| Subnet Information   |\n");
    printf("+----------------------+\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %d\n", subnet_mask);
    printf("Subnet Bits: %d\n", n_subnet_bits);
    printf("Host Bits: %d\n", n_host_bits);
    printf("Number of Subnets: %d\n", n_subnets);
    printf("Number of Hosts per Subnet: %d\n", n_hosts);

    return 0;
}
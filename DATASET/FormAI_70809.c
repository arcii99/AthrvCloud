//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the Happy Subnet Calculator!\n");
    printf("This program will help you calculate subnets within a Class C IP address range.\n");
    printf("\nEnter a valid Class C IP address in the format xxx.xxx.xxx (e.g. 192.168.0): ");

    char ip[20];
    fgets(ip, sizeof(ip), stdin);

    char first_octet[4], second_octet[4], third_octet[4]; 
    sscanf(ip, "%[^.]%*c%[^.]%*c%s", first_octet, second_octet, third_octet);

    int num_subnets, num_hosts;
    printf("\nHow many subnets do you need? ");
    scanf("%d", &num_subnets);
    printf("How many hosts per subnet? ");
    scanf("%d", &num_hosts);

    int subnet_bits = 0, host_bits = 0;
    for (int i = 1; i < num_subnets; i *= 2) {
        subnet_bits++;
    }
    for (int i = 1; i < num_hosts + 2; i *= 2) {
        host_bits++;
    }
    if (subnet_bits + host_bits > 24 - strlen(ip)) {
        printf("\nSorry, there are not enough bits left to create that many subnets and hosts.\n");
        return 1;
    }

    int bits_remaining = 24 - strlen(ip) - subnet_bits - host_bits;
    int network_bits = strlen(ip) * 8 + subnet_bits;
    int total_hosts = num_hosts + 2;
    int total_subnets = num_subnets;

    printf("\nCalculating results...\n");
    printf("\nUsing a Class C IP address of %s with %d subnet(s) and %d host(s) per subnet...\n", ip, num_subnets, num_hosts);
    printf("The subnet mask is %d.%d.%d.%d\n", 255, 255, 255, (256 - (1 << (8 - bits_remaining))));
    printf("The network address is %s.0\n", ip);
    printf("The broadcast address is %s.%d\n", ip, (256 - (1 << host_bits)) - 1);
    printf("The total number of hosts is %d\n", total_hosts * total_subnets);
    printf("There are %d bits of network address and %d bits of host address\n", network_bits, bits_remaining);

    return 0;
}
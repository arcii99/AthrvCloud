//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_MASK 30

unsigned int get_subnet_mask(int);

int main()
{
    char ip_addr[MAX_IP_LEN];
    int subnet_mask;
    unsigned int network_addr, broadcast_addr, first_host_addr, last_host_addr;

    printf("Enter IP address in dotted decimal notation: ");
    scanf("%s", ip_addr);

    printf("Enter subnet mask (0 - %d): ", MAX_SUBNET_MASK);
    scanf("%d", &subnet_mask);

    if (subnet_mask < 0 || subnet_mask > MAX_SUBNET_MASK)
    {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    network_addr = htonl(ntohl(inet_addr(ip_addr)) & get_subnet_mask(subnet_mask));
    broadcast_addr = network_addr | ~get_subnet_mask(subnet_mask);
    first_host_addr = network_addr + 1;
    last_host_addr = broadcast_addr - 1;

    printf("\nNetwork Address: %d.%d.%d.%d\n", (network_addr >> 24) & 0xff, (network_addr >> 16) & 0xff, (network_addr >> 8) & 0xff, network_addr & 0xff);
    printf("Subnet Mask: %d.%d.%d.%d\n", (get_subnet_mask(subnet_mask) >> 24) & 0xff, (get_subnet_mask(subnet_mask) >> 16) & 0xff, (get_subnet_mask(subnet_mask) >> 8) & 0xff, get_subnet_mask(subnet_mask) & 0xff);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcast_addr >> 24) & 0xff, (broadcast_addr >> 16) & 0xff, (broadcast_addr >> 8) & 0xff, broadcast_addr & 0xff);
    printf("First Host Address: %d.%d.%d.%d\n", (first_host_addr >> 24) & 0xff, (first_host_addr >> 16) & 0xff, (first_host_addr >> 8) & 0xff, first_host_addr & 0xff);
    printf("Last Host Address: %d.%d.%d.%d\n", (last_host_addr >> 24) & 0xff, (last_host_addr >> 16) & 0xff, (last_host_addr >> 8) & 0xff, last_host_addr & 0xff);

    return 0;
}

unsigned int get_subnet_mask(int subnet_mask)
{
    int i;
    unsigned int res = 0;

    for (i = 0; i < subnet_mask; i++)
    {
        res |= (1 << (31 - i));
    }

    return htonl(res);
}
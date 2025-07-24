//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    unsigned long int ip, subnet_mask;
    int netbits, hostbits, num_hosts;
    int i;
    
    printf("Enter IP address in decimal format (Example: 192.168.1.5): ");
    scanf("%lu", &ip);
    printf("Enter subnet mask in decimal format (Example: 255.255.255.0): ");
    scanf("%lu", &subnet_mask);

    netbits = 0;
    for (i = 0; i < 32; i++) {
        if ((subnet_mask << i) & 0x80000000) netbits++;
        else break;
    }

    hostbits = 32 - netbits;
    num_hosts = pow(2, hostbits) - 2;

    printf("\n\n");
    printf("IP Address         : %lu.%lu.%lu.%lu\n", (ip >> 24) & 0xff, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
    printf("Subnet Mask        : %lu.%lu.%lu.%lu\n", (subnet_mask >> 24) & 0xff, (subnet_mask >> 16) & 0xff, (subnet_mask >> 8) & 0xff, subnet_mask & 0xff);
    printf("Network Mask (CIDR): %d\n", netbits);
    printf("Number of Hosts    : %d\n", num_hosts);

    return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[20];
    int mask, subnet_bits, num_hosts, subnet_id;
    int a, b, c, d; // IP address octets
    int subnet_mask;

    printf("Enter IP address (e.g. 192.168.0.1): ");
    scanf("%s", ip);
    printf("Enter subnet mask (e.g. 24): ");
    scanf("%d", &mask);

    // Convert IP address from string to integers
    sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);

    // Calculate subnet mask bits
    subnet_bits = 32 - mask;

    // Calculate number of hosts
    num_hosts = (1 << subnet_bits) - 2;

    // Calculate subnet ID
    subnet_id = (d >> subnet_bits) + (c >> subnet_bits << 8) + (b >> subnet_bits << 16) + (a >> subnet_bits << 24);

    // Calculate subnet mask
    subnet_mask = ((1 << mask) - 1) << subnet_bits;

    printf("\nSubnet Calculator\n");
    printf("-----------------\n");
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %d.%d.%d.%d\n", (subnet_mask >> 24) & 0xff, (subnet_mask >> 16) & 0xff, (subnet_mask >> 8) & 0xff, subnet_mask & 0xff);
    printf("Subnet ID: %d\n", subnet_id);
    printf("Number of Hosts: %d\n", num_hosts);
    
    // Secure style implementation, clear sensitive data from memory
    memset(ip, 0, sizeof(ip));
    mask = 0;
    a = b = c = d = 0;
    subnet_bits = num_hosts = subnet_id = subnet_mask = 0;

    return 0;
}
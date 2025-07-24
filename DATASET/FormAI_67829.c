//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Subnet Calculator in a Post-Apocalyptic World!\n\n");
    printf("Enter the IP address: ");

    int ip1, ip2, ip3, ip4;
    scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);

    if (ip1 > 255 || ip2 > 255 || ip3 > 255 || ip4 > 255) {
        printf("\nInvalid IP address entered.\n");
        exit(1);
    }

    printf("\nEnter the subnet mask (in bits, e.g., 24): ");

    int mask_bits;
    scanf("%d", &mask_bits);

    if (mask_bits > 32) {
        printf("\nInvalid subnet mask entered.\n");
        exit(1);
    }

    int subnet_octet = mask_bits / 8;
    int subnet_mask = (1 << (8 - (mask_bits % 8))) - 1;
    subnet_mask = 255 - subnet_mask;

    printf("\nThe subnet mask is: %d.%d.%d.%d\n", subnet_octet > 0 ? 255 : subnet_mask, subnet_octet > 1 ? 255 : subnet_octet == 1 ? subnet_mask : 0, subnet_octet > 2 ? 255 : subnet_octet == 2 ? subnet_mask : 0, subnet_octet > 3 ? 255 : subnet_octet == 3 ? subnet_mask : 0);

    int network_addr = (ip1 & 0xff) << 24 | (ip2 & 0xff) << 16 | (ip3 & 0xff) << 8 | (ip4 & 0xff);
    network_addr &= (subnet_octet > 0 ? 0 : subnet_mask) | (subnet_octet > 1 ? 0 : subnet_mask << 8) | (subnet_octet > 2 ? 0 : subnet_mask << 16) | (subnet_octet > 3 ? 0 : subnet_mask << 24);

    printf("The network address is: %d.%d.%d.%d\n", (network_addr >> 24) & 0xff, (network_addr >> 16) & 0xff, (network_addr >> 8) & 0xff, network_addr & 0xff);

    int host_addr = (ip1 & 0xff) << 24 | (ip2 & 0xff) << 16 | (ip3 & 0xff) << 8 | (ip4 & 0xff);
    host_addr &= ~(subnet_octet > 0 ? subnet_mask : 0) & ~(subnet_octet > 1 ? subnet_mask << 8 : 0) & ~(subnet_octet > 2 ? subnet_mask << 16 : 0) & ~(subnet_octet > 3 ? subnet_mask << 24 : 0);

    printf("The host address is: %d.%d.%d.%d\n", (host_addr >> 24) & 0xff, (host_addr >> 16) & 0xff, (host_addr >> 8) & 0xff, host_addr & 0xff);

    int num_hosts = (1 << (32 - mask_bits)) - 2;

    printf("The number of hosts on the subnet is: %d\n", num_hosts);

    return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char ip_address[16];
    int subnet_mask;
    int octet[4];
    int subnet_octet[4];

    printf("Enter IP Address (e.g. 192.168.0.1): ");
    scanf("%s", ip_address);

    printf("Enter Subnet Mask (e.g. 24): ");
    scanf("%d", &subnet_mask);

    // Split IP address into octet array
    sscanf(ip_address, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);

    // Calculate subnet mask octets
    memset(subnet_octet, 0, sizeof(subnet_octet));
    for (int i = 0; i < subnet_mask; i++) {
        subnet_octet[i / 8] |= (1 << (7 - i % 8));
    }

    // Calculate network address
    int network_address[4];
    for (int i = 0; i < 4; i++) {
        network_address[i] = octet[i] & subnet_octet[i];
    }

    // Calculate broadcast address
    int broadcast_address[4];
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = network_address[i] | (~subnet_octet[i] & 0xFF);
    }

    // Print results
    printf("\nIP Address: %s\n", ip_address);
    printf("Subnet Mask: %d\n", subnet_mask);
    printf("Network Address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);

    return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: genious
#include <stdio.h>
#include <math.h>

int main() {
    int cidr, subnet_bits, host_bits, total_hosts, i, j;
    char ip_address[15];

    printf("Enter IP address (xxx.xxx.xxx.xxx): ");
    scanf("%s", ip_address);
    printf("Enter CIDR notation (0-32): ");
    scanf("%d", &cidr);

    subnet_bits = cidr;
    host_bits = 32 - subnet_bits;
    total_hosts = pow(2, host_bits) - 2;

    int decimal_ip[4];
    sscanf(ip_address, "%d.%d.%d.%d", &decimal_ip[0], &decimal_ip[1], &decimal_ip[2], &decimal_ip[3]);
    printf("\n");

    // Calculate subnet mask
    int subnet_mask[4];
    for (i = 0; i < 4; i++) {
        if (subnet_bits >= 8) {
            subnet_mask[i] = 255;
            subnet_bits -= 8;
        }
        else {
            subnet_mask[i] = pow(2, 8 - subnet_bits) - 1;
            subnet_bits = 0;
        }
    }

    // Print subnet mask
    printf("Subnet Mask: ");
    for (i = 0; i < 4; i++) {
        printf("%d", subnet_mask[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n\n");

    // Calculate network address
    int network_address[4];
    for (i = 0; i < 4; i++) {
        network_address[i] = decimal_ip[i] & subnet_mask[i];
    }

    // Print network address
    printf("Network Address: ");
    for (i = 0; i < 4; i++) {
        printf("%d", network_address[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n\n");

    // Calculate broadcast address
    int broadcast_address[4];
    for (i = 0; i < 4; i++) {
        if (subnet_mask[i] != 255) {
            broadcast_address[i] = network_address[i] + pow(2, 8 - subnet_bits) - 1;
            subnet_bits = 0;
        }
        else {
            broadcast_address[i] = network_address[i];
        }
    }

    // Print broadcast address
    printf("Broadcast Address: ");
    for (i = 0; i < 4; i++) {
        printf("%d", broadcast_address[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n\n");

    // Print host range
    printf("Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n\n", network_address[0], network_address[1], network_address[2], network_address[3],
           broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);

    // Print total number of hosts
    printf("Total Number of Hosts: %d\n\n", total_hosts);

    // Print binary representation of IP address
    char binary_ip[33];
    int binary_place_value = 128;
    int binary_ip_segment[4];
    for (i = 0; i < 4; i++) {
        binary_place_value = 128;
        for (j = 0; j < 8; j++) {
            binary_ip_segment[j] = (decimal_ip[i] & binary_place_value) ? 1 : 0;
            binary_ip[i * 8 + j] = binary_ip_segment[j] + '0';
            binary_place_value /= 2;
        }
        binary_ip[i * 8 + j] = ' ';
    }
    binary_ip[32] = '\0';
    printf("Binary IP Address: %s\n\n", binary_ip);

    return 0;
}
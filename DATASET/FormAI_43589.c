//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char ip[16];
    int cidr, subnet_bits, n = 0, i = 0;
    int subnet_mask[4] = {0};

    printf("Enter IP address in decimal notation (ex. 192.168.0.1): ");
    scanf("%15[^\n]%*c", ip);

    printf("Enter CIDR notation (ex. /24): ");
    scanf("%d", &cidr);

    subnet_bits = cidr % 8;
    n = cidr / 8;

    if (subnet_bits > 0) {
        subnet_mask[n] |= (int)(pow(2, subnet_bits) - 1);
    }

    for (i = 0; i < n; i++) {
        subnet_mask[i] = 255;
    }

    printf("\nIP Address: %s\n", ip);

    char* token = strtok(ip, ".");
    i = 0;
    while (token != NULL) {
        printf("Octet %d: %s\n", i + 1, token);
        subnet_mask[i] &= atoi(token);
        token = strtok(NULL, ".");
        i++;
    }

    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

    printf("\nNumber of Hosts: %d", (int)(pow(2, (32 - cidr)) - 2));
    printf("\nSubnet ID: %d.%d.%d.%d", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3] & (int)(pow(2, (8 - subnet_bits)) - 1));
    printf("\nBroadcast Address: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2] | (int)(pow(2, (8 - subnet_bits)) - 1), (int)(pow(2, (8 - subnet_bits)) - 1));

    return 0;
}
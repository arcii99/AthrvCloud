//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
/* A minimalist subnet calculator program in C */

#include <stdio.h>
#include <math.h>

struct subnet {
    int address[4];  // IP address in octet
    int mask;        // subnet mask in CIDR notation
};

int main() {
    struct subnet s;

    printf("Enter IP address in the format X.X.X.X: ");
    scanf("%d.%d.%d.%d", &s.address[0], &s.address[1], &s.address[2], &s.address[3]);

    printf("Enter subnet mask in CIDR notation: ");
    scanf("%d", &s.mask);

    // Calculate the number of hosts in the subnet
    int num_hosts = pow(2, 32 - s.mask) - 2;

    // Calculate the network address
    int network[4];
    for (int i = 0; i < 4; i++) {
        network[i] = s.address[i] & (255 << (3-i)*8);
    }

    // Calculate the broadcast address
    int broadcast[4];
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] + (255 >> (i*8)) - (s.address[i] & (255 >> (i*8)));
    }

    // Print the results
    printf("\nNetwork address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of hosts: %d\n", num_hosts);

    return 0;
}
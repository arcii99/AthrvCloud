//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <string.h>

int main() {
    char ip[16], mask[16];
    int network[4], host[4], m[4], i;

    // Get input from user
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", mask);

    // Parse IP address into its components
    sscanf(ip, "%d.%d.%d.%d", &network[0], &network[1], &network[2], &network[3]);

    // Parse subnet mask into its components
    sscanf(mask, "%d.%d.%d.%d", &m[0], &m[1], &m[2], &m[3]);

    // Calculate network address and host address
    for (i = 0; i < 4; i++) {
        host[i] = network[i] & (~m[i] & 0xff);
        network[i] = network[i] & m[i];
    }

    // Print results
    printf("\nNetwork Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Host Address: %d.%d.%d.%d\n", host[0], host[1], host[2], host[3]);

    return 0;
}
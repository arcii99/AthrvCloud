//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16], subnet[16];

    /* Read user inputs */
    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter Subnet mask: ");
    scanf("%s", subnet);

    /* Calculate network address */
    char *ip_tokens[4], *subnet_tokens[4];
    int i, network[4];
    for (i = 0; i < 4; i++) {
        ip_tokens[i] = strtok(i == 0 ? ip : NULL, ".");
        subnet_tokens[i] = strtok(i == 0 ? subnet : NULL, ".");
        network[i] = atoi(ip_tokens[i]) & atoi(subnet_tokens[i]);
    }

    /* Calculate broadcast address */
    int broadcast[4];
    for (i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (255 - atoi(subnet_tokens[i]));
    }

    /* Print results */
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    return 0;
}
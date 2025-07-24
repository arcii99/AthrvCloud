//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* ip_address = (char*)malloc(sizeof(char) * 16);
    printf("Enter IP address in the format (x.x.x.x): ");
    scanf("%s", ip_address);

    int subnet_mask;
    printf("Enter subnet mask: ");
    scanf("%d", &subnet_mask);

    // Split the IP address into octets
    char* octet = strtok(ip_address, ".");

    int ip[4];
    ip[0] = atoi(octet);
    for (int i = 1; i < 4; i++) {
        octet = strtok(NULL, ".");
        ip[i] = atoi(octet);
    }

    // Calculate the network and broadcast addresses
    int network_address[4];
    int broadcast_address[4];
    for (int i = 0; i < 4; i++) {
        network_address[i] = ip[i] & (255 << (24 - subnet_mask + 8 * i));
        broadcast_address[i] = network_address[i] + (255 >> (subnet_mask - 8 * i));
    }

    // Print the results
    printf("\n");
    printf("Network address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);

    free(ip_address);
    return 0;
}
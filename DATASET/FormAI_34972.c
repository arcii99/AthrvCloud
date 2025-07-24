//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Introduction
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter your IP address in dotted decimal notation:\n");

    // Variables
    char ipAddr[16];
    int oct1, oct2, oct3, oct4, cidr, mask;
    int subnet, hosts, nwAddr, bcastAddr;

    // Input validation loop
    do {
        printf("> ");
        scanf("%15s", ipAddr);
        if (sscanf(ipAddr, "%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4) != 4) {
            printf("Invalid input. Please try again.\n");
        } else if (oct1 < 0 || oct1 > 255 || oct2 < 0 || oct2 > 255 || oct3 < 0 || oct3 > 255 || oct4 < 0 || oct4 > 255) {
            printf("Invalid IP address. Please try again.\n");
        } else {
            break;
        }
    } while (1);

    // CIDR notation input validation loop
    do {
        printf("Enter the CIDR notation (e.g. /24):\n> ");
        scanf("%d", &cidr);
        if (cidr < 0 || cidr > 32) {
            printf("Invalid CIDR notation. Please try again.\n");
        } else {
            break;
        }
    } while (1);

    // Subnet mask calculation
    mask = pow(2, 32 - cidr) - 1;
    mask = ~mask;

    // Subnet calculation
    subnet = ((oct1 & (mask >> 24)) << 24) | ((oct2 & (mask >> 16)) << 16) | ((oct3 & (mask >> 8)) << 8) | (oct4 & mask);

    // Number of hosts calculation
    hosts = pow(2, 32 - cidr) - 2;

    // Network address calculation
    nwAddr = subnet + 1;

    // Broadcast address calculation
    bcastAddr = subnet | ~mask;

    // Output
    printf("\nResults:\n");
    printf("Subnet mask: %d.%d.%d.%d\n", (mask >> 24) & 0xff, (mask >> 16) & 0xff, (mask >> 8) & 0xff, mask & 0xff);
    printf("Subnet address: %d.%d.%d.%d\n", subnet >> 24, (subnet >> 16) & 0xff, (subnet >> 8) & 0xff, subnet & 0xff);
    printf("Number of hosts: %d\n", hosts);
    printf("Network address: %d.%d.%d.%d\n", nwAddr >> 24, (nwAddr >> 16) & 0xff, (nwAddr >> 8) & 0xff, nwAddr & 0xff);
    printf("Broadcast address: %d.%d.%d.%d\n", bcastAddr >> 24, (bcastAddr >> 16) & 0xff, (bcastAddr >> 8) & 0xff, bcastAddr & 0xff);

    return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char address[17];
    char netmask[17];
    unsigned int addr[4], mask[4], subnet[4], wildcard[4], network[4], broadcast[4];
    int i;

    printf("Enter IP Address: ");
    scanf("%s", address);
    printf("Enter Netmask: ");
    scanf("%s", netmask);

    sscanf(address, "%d.%d.%d.%d", &addr[0], &addr[1], &addr[2], &addr[3]);
    sscanf(netmask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    for(i=0; i<4; i++) {
        subnet[i] = (addr[i] & mask[i]);
        wildcard[i] = (~(mask[i]) & 0xFF);
        network[i] = subnet[i];
        broadcast[i] = (subnet[i] | wildcard[i]);
    }

    printf("\n*************************************************************************************************\n");
    printf("%10s %10s %10s %10s %20s %20s\n", "Address", "Netmask", "Wildcard", "Subnet", "Network", "Broadcast");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("%10d.%-10d.%-10d.%-10d ", addr[0], addr[1], addr[2], addr[3]);
    printf("%10d.%-10d.%-10d.%-10d ", mask[0], mask[1], mask[2], mask[3]);
    printf("%10d.%-10d.%-10d.%-10d ", wildcard[0], wildcard[1], wildcard[2], wildcard[3]);
    printf("%10d.%-10d.%-10d.%-10d ", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("%10d.%-10d.%-10d.%-10d ", network[0], network[1], network[2], (network[3]+1));
    printf("%10d.%-10d.%-10d.%-10d\n", broadcast[0], broadcast[1], broadcast[2], (broadcast[3]-1));
    printf("*************************************************************************************************\n");

    return 0;
}
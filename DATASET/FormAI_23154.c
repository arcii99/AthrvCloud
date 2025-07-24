//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include<stdio.h>

int main() {
    printf("*** Welcome to the Cheery Subnet Calculator! ***\n\n");
    printf("Enter your IP address (in the format x.x.x.x): ");
    int ip[4];
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("Enter your subnet mask (in the format x.x.x.x): ");
    int mask[4];
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Calculate the network address
    int network[4];
    for(int i = 0; i < 4; i++) {
        network[i] = (ip[i] & mask[i]);
    }

    // Calculate the broadcast address
    int broadcast[4];
    for(int i = 0; i < 4; i++) {
        broadcast[i] = (network[i] | (~mask[i] & 0xff));
    }

    // Calculate the number of usable hosts
    int hosts = 0;
    for(int i = 0; i < 4; i++) {
        hosts += ((~mask[i] & 0xff) + 1);
    }
    hosts -= 2; // Subtract network and broadcast addresses

    printf("\nCheery Results:\n");
    printf("Network address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of usable hosts: %d\n\n", hosts);
    printf("Thanks for using the Cheery Subnet Calculator!\n");

    return 0;
}
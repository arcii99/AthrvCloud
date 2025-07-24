//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h> 

int main () 
{
    // declare variables
    int subnet[4];
    int mask, ip[4], network[4], broadcast[4];
    int hostBits, networkBits;
    int i;
    
    // take user input
    printf("Enter IP address (format: xxx.xxx.xxx.xxx):\n");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    
    printf("Enter subnet mask (CIDR notation): \n");
    scanf("%d", &mask);
    
    // calculate subnet
    for (i = 0; i < 4; i++) 
    {
        subnet[i] = (mask >= 8) ? 255 : (mask == 0) ? 0 : (1 << 8 - mask) - 1 << (i * 8 - mask);
        mask -= 8;
        network[i] = ip[i] & subnet[i];
        broadcast[i] = network[i] | ~subnet[i];
    }

    // calculate number of host bits and network bits
    hostBits = 32 - mask;
    networkBits = 32 - hostBits;
    
    // print output
    printf("\nIP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of Host Bits: %d\n", hostBits);
    printf("Number of Network Bits: %d\n", networkBits);
    
    return 0;
}
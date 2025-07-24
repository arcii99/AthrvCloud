//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int mask;
    unsigned int ip;
    unsigned int subnet;
    unsigned int network;
    unsigned int broadcast;
    
    printf("Enter IP address (in hex format): ");
    scanf("%x", &ip);
    
    printf("Enter subnet mask (in hex format): ");
    scanf("%x", &mask);
    
    subnet = mask;
    network = ip & mask;
    broadcast = network | ~mask;
    
    printf("\nSubnet mask         : %08x", subnet);
    printf("\nNetwork address     : %08x", network);
    printf("\nBroadcast address   : %08x\n", broadcast);
    
    return 0;
}
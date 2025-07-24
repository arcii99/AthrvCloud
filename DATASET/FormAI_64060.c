//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[16];
    char mask[16];
    char *temp;
    int num;
    int subnetMask[4];
    int networkAddr[4];
    int broadcastAddr[4];
    int wildcard[4];
    
    printf("Welcome to the C Subnet Calculator!\n\n");
    printf("Enter an IPv4 address: ");
    fgets(ip, sizeof(ip), stdin);
    strtok(ip, "\n");
    
    temp = strtok(ip, ".");
    num = 0;
    while(temp != NULL) {
        subnetMask[num++] = atoi(temp);
        temp = strtok(NULL, ".");
    }
    
    printf("\nEnter a subnet mask: ");
    fgets(mask, sizeof(mask), stdin);
    strtok(mask, "\n");
    
    temp = strtok(mask, ".");
    num = 0;
    while(temp != NULL) {
        networkAddr[num] = subnetMask[num] & atoi(temp);
        wildcard[num] = 255 - atoi(temp);
        broadcastAddr[num++] = networkAddr[num-1] + wildcard[num-1];
        temp = strtok(NULL, ".");
    }
    
    printf("\nNetwork Address: %d.%d.%d.%d\n", networkAddr[0], networkAddr[1], networkAddr[2], networkAddr[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    printf("Wildcard Mask: %d.%d.%d.%d\n\n", wildcard[0], wildcard[1], wildcard[2], wildcard[3]);
    
    return 0;
}
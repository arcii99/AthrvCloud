//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Fun Subnet Calculator!\n"); 
    printf("Let me grab my goggles and start calculating!\n");
    printf("\nEnter the IP address: ");
    char ip[25];
    scanf("%s", ip);
    int subnetMask[4]={0,0,0,0};
    int cidr;
    printf("Enter CIDR notation: ");
    scanf("%d", &cidr);
    int shift = 32 - cidr;
    int i;
    for(i = 0; i < 4; i++) {
        subnetMask[i] = ((cidr >= 8) ? 255 : (256 - (1 << shift))) & 0xFF;
        cidr -= 8;
        if(cidr < 1) {
            break;
        } 
        shift -= 8;
    }
    printf("\nIP address: %s\n", ip);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Network Address: ");
    int network[4];
    for(i = 0; i < 4; i++) {
        network[i] = (subnetMask[i] & ip[i] & 0xFF);
        printf("%d", network[i]);
        if(i < 3) {
            printf(".");
        }
    }
    printf("\n");
    printf("Host Address Range: %d.%d.%d.%d - ", network[0], network[1], network[2], (network[3] + 1));
    for(i = 0; i < shift-1; i++) {
        network[3] = network[3] | (1 << i);
    }
    printf("%d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Number of Hosts: %d\n", (1 << shift) - 2);
    printf("Oh what fun it is to calculate subnets all day! \n");

    return 0;
}
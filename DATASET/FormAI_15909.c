//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char address[16] = "";
    int mask = 0;
    char subnet[16] = "";

    // User input
    printf("Enter IP Address: ");
    scanf("%s", address);
    printf("Enter Subnet Mask: ");
    scanf("%d", &mask);

    // Subnet calculation
    int subnet_octets = mask / 8;
    int subnet_bits = mask % 8;
    int subnet_value = 255 << (8 - subnet_bits);
    sprintf(subnet, "%d.%d.%d.%d", 
            ((int)inet_addr(address) & subnet_value) >> (24 - mask), 
            ((int)inet_addr(address) & subnet_value) >> (16 - mask) & 255, 
            ((int)inet_addr(address) & subnet_value) >> (8 - mask) & 255, 
            ((int)inet_addr(address) & subnet_value) >> mask & 255);

    // Output
    printf("IP Address: %s\n", address);
    printf("Subnet Mask: %d\n", mask);
    printf("Subnet: %s/%d\n", subnet, mask);
    printf("Network Address: %d.%d.%d.%d\n", 
            ((int)inet_addr(address) & subnet_value) >> (24 - mask), 
            ((int)inet_addr(address) & subnet_value) >> (16 - mask) & 255, 
            ((int)inet_addr(address) & subnet_value) >> (8 - mask) & 255, 
            ((int)inet_addr(address) & subnet_value) >> mask & 255);
    printf("Broadcast Address: %d.%d.%d.%d\n", 
            ((int)inet_addr(address) | ~subnet_value) >> (24 - mask), 
            ((int)inet_addr(address) | ~subnet_value) >> (16 - mask) & 255, 
            ((int)inet_addr(address) | ~subnet_value) >> (8 - mask) & 255, 
            ((int)inet_addr(address) | ~subnet_value) >> mask & 255);

    return 0;
}
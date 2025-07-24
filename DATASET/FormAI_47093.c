//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BITS 32

typedef struct {
    unsigned long address;
    unsigned int prefix_length;
    unsigned long subnet_mask;
    unsigned long network_address;
    unsigned long broadcast_address;
} subnet_t;

int main() {
    subnet_t subnet;

    printf("Enter IP address: ");
    scanf("%lu", &subnet.address);

    printf("Enter prefix length: ");
    scanf("%u", &subnet.prefix_length);

    subnet.subnet_mask = pow(2, subnet.prefix_length) - 1;
    subnet.subnet_mask <<= (MAX_BITS - subnet.prefix_length);

    subnet.network_address = subnet.address & subnet.subnet_mask;
    subnet.broadcast_address = subnet.network_address | ~subnet.subnet_mask;

    printf("\n\nSubnet mask: %lu.%lu.%lu.%lu\n",
           (subnet.subnet_mask >> 24) & 0xFF,
           (subnet.subnet_mask >> 16) & 0xFF,
           (subnet.subnet_mask >> 8) & 0xFF,
           (subnet.subnet_mask) & 0xFF);
    
    printf("Network Address: %lu.%lu.%lu.%lu\n",
           (subnet.network_address >> 24) & 0xFF,
           (subnet.network_address >> 16) & 0xFF,
           (subnet.network_address >> 8) & 0xFF,
           (subnet.network_address) & 0xFF);

    printf("Broadcast Address: %lu.%lu.%lu.%lu\n",
           (subnet.broadcast_address >> 24) & 0xFF,
           (subnet.broadcast_address >> 16) & 0xFF,
           (subnet.broadcast_address >> 8) & 0xFF,
           (subnet.broadcast_address) & 0xFF);

    return 0;
}
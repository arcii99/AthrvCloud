//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    // variables for input and output
    char network_address[15];
    int prefix_length;
    long int binary_address = 0;
    char subnet_mask[15];
    long int binary_mask = 0;
    char broadcast_address[15];
    long int binary_broadcast = 0;

    // get input from user
    printf("Enter network address: ");
    scanf("%s", network_address);

    printf("Enter prefix length: ");
    scanf("%d", &prefix_length);

    // calculate binary address
    char *token;
    token = strtok(network_address, ".");
    while (token != NULL) {
        int octet = atoi(token);
        binary_address += octet * pow(2, 24) + octet * pow(2, 16) + octet * pow(2, 8) + octet;
        token = strtok(NULL, ".");
    }

    // calculate binary mask
    int num_ones = prefix_length;
    int num_zeros = 32 - prefix_length;
    for (int i = 0; i < num_ones; i++) {
        binary_mask += pow(2, 31 - i);
    }

    // calculate binary broadcast address
    binary_broadcast = binary_address | (~binary_mask);

    // convert binary values to dotted decimal format
    sprintf(subnet_mask, "%d.%d.%d.%d", (binary_mask >> 24) & 0xff, (binary_mask >> 16) & 0xff,
            (binary_mask >> 8) & 0xff, binary_mask & 0xff);
    sprintf(broadcast_address, "%d.%d.%d.%d", (binary_broadcast >> 24) & 0xff, (binary_broadcast >> 16) & 0xff,
            (binary_broadcast >> 8) & 0xff, binary_broadcast & 0xff);

    // print results
    printf("Network Address: %s\n", network_address);
    printf("Prefix Length: %d\n", prefix_length);
    printf("Binary Address: %ld\n", binary_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Binary Mask: %ld\n", binary_mask);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Binary Broadcast: %ld\n", binary_broadcast);

    return 0;
}
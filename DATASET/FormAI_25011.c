//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the subnet mask
void calculate_subnet_mask(int cidr, int *subnet_mask) {
    for (int i = 0; i < 4; i++) {
        if (cidr >= 8) {
            subnet_mask[i] = 255;
            cidr -= 8;
        }
        else {
            subnet_mask[i] = pow(2, 8 - cidr) - 1;
            cidr = 0;
        }
    }
}

int main() {
    // Variables to store IP address and CIDR
    char ip_address[16];
    int cidr;

    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    printf("Enter CIDR: ");
    scanf("%d", &cidr);

    // Splitting IP address into octets
    char *token = strtok(ip_address, ".");
    int octets[4];
    int i = 0;

    while (token != NULL) {
        octets[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Calculate Subnet Mask
    int subnet_mask[4] = {0};
    calculate_subnet_mask(cidr, subnet_mask);

    printf("\nSubnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

    return 0;
}
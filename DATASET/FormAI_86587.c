//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <math.h>

int main() {
    unsigned long ip_address_input;
    int subnet_input;
    int subnet_mask[4] = {0, 0, 0, 0};

    // Get IP address input
    printf("Enter IP address: ");
    scanf("%lu", &ip_address_input);

    // Get subnet input
    printf("Enter Subnet: ");
    scanf("%d", &subnet_input);

    // Calculate subnet mask
    for (int i = 0; i < 4; i++) {
        int val = 0;
        for (int j = 0; j < 8; j++) {
            if (subnet_input > 0) {
                val += pow(2, 7 - j);
                subnet_input--;
            }
        }
        subnet_mask[i] = val;
    }

    // Calculate network address
    unsigned long network_address = (ip_address_input & (subnet_mask[0] << 24 | subnet_mask[1] << 16 | subnet_mask[2] << 8 | subnet_mask[3]));

    // Print results
    printf("IP Address: %lu\n", ip_address_input);
    printf("Subnet Mask: /%d\n", subnet_input);
    printf("Network Address: %lu.%lu.%lu.%lu\n", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);

    return 0;
}
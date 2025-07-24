//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char ip_address[16];
    int net_mask, octet[4], binary_mask[32], i;
    printf("Enter the IP address in dotted decimal notation: ");
    scanf("%s", ip_address);
    printf("Enter the subnet mask in CIDR notation: ");
    scanf("%d", &net_mask);

    // Convert IP address from dotted decimal to binary
    sscanf(ip_address, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);
    for(i = 0; i < 4; i++) {
        int j, k = 128;
        for(j = 0; j < 8; j++) {
            if(octet[i] >= k) {
                octet[i] -= k;
                binary_mask[i*8+j] = 1;
            }
            else {
                binary_mask[i*8+j] = 0;
            }
            k /= 2;
        }
    }

    // Calculate the subnet mask in binary
    for(i = 0; i < net_mask; i++) {
        binary_mask[i] = 1;
    }

    // Print the output
    printf("\nThe IP address %s is in the subnet:\n", ip_address);
    for(i = 0; i < 32; i += 8) {
        int j, k = 128, subnet_octet = 0;
        for(j = 0; j < 8; j++) {
            if(binary_mask[i+j] == 1) {
                subnet_octet += k;
            }
            k /= 2;
        }
        printf("%d.", subnet_octet);
    }
    printf("\n");

    return 0;
}
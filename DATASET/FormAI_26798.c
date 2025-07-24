//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>

int main() {
    int ip_address[4], prefix_length;
    printf("Enter IP address in decimal notation (e.g. 192.168.0.1):\n");
    scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);

    printf("Enter prefix length (number of bits for network portion):\n");
    scanf("%d", &prefix_length);

    // Calculate subnet mask
    int subnet_mask[4];
    for (int i = 0; i < 4; i++) {
        if (prefix_length >= 8) {
            subnet_mask[i] = 255;
            prefix_length -= 8;
        } else if (prefix_length > 0) {
            subnet_mask[i] = 255 - (1 << (8 - prefix_length));
            prefix_length = 0;
        } else {
            subnet_mask[i] = 0;
        }
    }

    // Calculate network address
    int network_address[4];
    for (int i = 0; i < 4; i++) {
        network_address[i] = ip_address[i] & subnet_mask[i];
    }

    // Calculate broadcast address
    int broadcast_address[4];
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = ip_address[i] | (255 - subnet_mask[i]);
    }

    // Print results
    printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Network address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    return 0;
}
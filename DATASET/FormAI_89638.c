//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <math.h>

// Function to calculate the subnet mask
void calculateSubnetMask(int prefix, int *subnet_mask) {
    int n = prefix / 8;
    int r = prefix % 8;
    for (int i = 0; i < n; i++) {
        subnet_mask[i] = 255;
    }
    subnet_mask[n] = pow(2, r) - 1;

    for (int i = n+1; i < 4; i++) {
        subnet_mask[i] = 0;
    }
}

int main() {
    int ip_addr[4];
    int prefix;
    int subnet_mask[4];

    printf("Enter IP address (e.g. 192.168.1.10): ");
    scanf("%d.%d.%d.%d", &ip_addr[0], &ip_addr[1], &ip_addr[2], &ip_addr[3]);

    while (prefix < 1 || prefix > 32) {
        printf("Enter prefix length (1-32): ");
        scanf("%d", &prefix);
    }

    calculateSubnetMask(prefix, subnet_mask);

    printf("IP Address: %d.%d.%d.%d\n", ip_addr[0], ip_addr[1], ip_addr[2], ip_addr[3]);
    printf("Prefix Length: %d\n", prefix);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

    return 0;
}
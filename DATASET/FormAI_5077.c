//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>

int calculate_subnet(int ip_address) {
    int subnet_mask = 0;

    // Base case: return 32 when ip_address is 0
    if (ip_address == 0) {
        return 32;
    }

    // Recursive case: keep dividing by 2 until we find the first 0 bit
    subnet_mask = calculate_subnet(ip_address / 2);

    if (ip_address % 2 == 0) {
        subnet_mask--;
    }

    return subnet_mask;
}

int main() {
    int ip_address = 0;
    int subnet_mask = 0;

    printf("Enter an IP address in decimal form (e.g. 192.168.0.1): ");
    scanf("%d", &ip_address);

    // Call the calculate_subnet function to find the subnet mask
    subnet_mask = calculate_subnet(ip_address);

    printf("The subnet mask for %d is /%d\n", ip_address, subnet_mask);

    return 0;
}
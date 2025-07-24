//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>

int main() {

    int ip_address[4];
    int subnet_mask;
    int subnet_count = 0;

    printf("\nHello there! Let's calculate your C class IP subnet!\n");

    printf("\nPlease enter your IP address in the format 'x.x.x.x':\n");
    scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);

    printf("\nGreat! Now enter your subnet mask (in bits):\n");
    scanf("%d", &subnet_mask);

    subnet_count = (1 << (32 - subnet_mask));

    printf("\nYou have %d subnets with %d hosts in each subnet.\n", subnet_count, (256 - subnet_count));

    printf("\nThank you for using our subnet calculator! Have a good day!\n");

    return 0;
}
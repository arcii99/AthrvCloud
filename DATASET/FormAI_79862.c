//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>

// This program is a subnet calculator, dear Watson.

int main() {

    printf("Good day Watson, I have just finished my latest program to calculate subnets!\n\n");

    int address[4], mask[4], bits, subnets, hosts;

    printf("Please provide me with the IP address you are working with (in the format xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &address[0], &address[1], &address[2], &address[3]);

    printf("\nAnd the subnet mask (in the format xxx.xxx.xxx.xxx): ");
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    printf("\nBrilliant, now please tell me how many bits I should use for subnetting: ");
    scanf("%d", &bits);

    subnets = (1 << bits);
    hosts = (1 << (32 - bits)) - 2;

    printf("\nSo that gives us %d Subnets with %d Hosts per subnet!\n\n", subnets, hosts);

    printf("Here are all of the subnets:\n");
    for (int i = 0; i < subnets; i++) {
        printf("%d.%d.%d.%d\n", address[0] & ((-1) << (32 - bits)) | i, address[1], address[2], address[3]);
    }

    printf("\n\nFantastic Watson, our programming skills never cease to amaze me!\n");
    return 0;
}
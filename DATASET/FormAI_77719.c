//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main()
{
    int network[4], mask[4];
    char input[16];
    int subnet_bits;

    printf("Enter IP address: ");
    scanf("%d.%d.%d.%d", &network[0], &network[1], &network[2], &network[3]);
    printf("Enter subnet mask: ");
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    int i;
    for (i = 0; i < 4; i++) {
        network[i] = network[i] & mask[i];
    }

    subnet_bits = 0;
    for (i = 0; i < 4; i++) {
        char binary[9];
        int num = mask[i];
        int j;
        for (j = 0; j < 8; j++) {
            binary[j] = num % 2 + '0';
            num /= 2;
        }
        binary[8] = '\0';
        subnet_bits += strlen(strchr(binary, '0'));
    }

    printf("Subnet bits: %d\n", subnet_bits);
    printf("Number of subnets: %d\n", 1 << (subnet_bits - 1));
    printf("Number of hosts per subnet: %d\n", (1 << (32 - subnet_bits)) - 2);

    return 0;
}
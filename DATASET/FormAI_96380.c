//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char subnet[16];
    printf("Enter the subnet in CIDR notation (e.g. 192.168.0.0/24): ");
    scanf("%s", subnet);

    char ip[16], slash[3];
    int cidr;
    strtok(subnet, "/");
    strcpy(ip, subnet);
    strtok(NULL, "/");
    cidr = atoi(strtok(NULL, "/"));

    int octet1, octet2, octet3, octet4;
    sscanf(ip, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    int i, mask[4];
    for (i = 0; i < 4; i++) {
        if (cidr >= 8) {
            mask[i] = 255;
            cidr -= 8;
        } else {
            mask[i] = 256 - (1 << (8 - cidr));
            cidr = 0;
        }
    }

    printf("\nThe subnet address is %d.%d.%d.%d\n", octet1 & mask[0], octet2 & mask[1], octet3 & mask[2], octet4 & mask[3]);
    printf("The broadcast address is %d.%d.%d.%d\n", octet1 | (255 - mask[0]), octet2 | (255 - mask[1]), octet3 | (255 - mask[2]), octet4 | (255 - mask[3]));

    int num_addresses = (1 << (32 - atoi(strtok(subnet, "/")))) - 2;
    printf("The number of addresses in the subnet is %d\n", num_addresses);

    return 0;
}
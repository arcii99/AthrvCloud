//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Function to calculate subnet mask
int subnetMask(int sub) {
    int mask = 0;
    int i = 0;
    int rem = sub % 8;
    while (sub > 0 && i < 4) {
        if (sub >= 8) {
            mask += 255;
            sub -= 8;
        } else {
            mask += pow(2, 8 - sub) - 1;
            sub = 0;
        }
        i++;
    }
    if (rem > 0) {
        mask += pow(2, 8 - rem) - 1;
    }
    return mask;
}

int main()
{
    int ip[4];
    int mask;
    printf("Enter the IP Address in dot notation: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter the Subnet Mask in CIDR notation: ");
    scanf("%d", &mask);

    int subnetmask = subnetMask(mask);

    printf("\nThe Subnet Mask is: %d.%d.%d.%d \n", (subnetmask >> 24) & 0xFF, (subnetmask >> 16) & 0xFF, (subnetmask >> 8) & 0xFF, subnetmask & 0xFF);

    printf("The Network Address is: %d.%d.%d.%d \n", ip[0] & (subnetmask >> 24), ip[1] & (subnetmask >> 16), ip[2] & (subnetmask >> 8), ip[3] & subnetmask);

    printf("The Broadcast Address is: %d.%d.%d.%d \n", (ip[0] & (subnetmask >> 24)) + (~subnetmask >> 24) & 0xFF, (ip[1] & (subnetmask >> 16)) + (~subnetmask >> 16) & 0xFF, (ip[2] & (subnetmask >> 8)) + (~subnetmask >> 8) & 0xFF, (ip[3] & subnetmask) + (~subnetmask & 0xFF));
    
    printf("The Total Number of Hosts is: %d", ~(subnetmask) & 0xFFFFFFFF);
    return 0;
}
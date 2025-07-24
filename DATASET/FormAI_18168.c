//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    char ipAddress[15]; // maximum length of IPv4 address is 15
    int subnets;

    printf("\nEnter IP Address: ");
    scanf("%s", ipAddress);
    printf("Enter number of subnets: ");
    scanf("%d", &subnets);

    // Split IP address into octets
    int octet1, octet2, octet3, octet4;
    sscanf(ipAddress, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    // Calculate the mask bits required for given number of subnets
    int maskBits = ceil(log2(subnets + 2));

    char mask[15];
    sprintf(mask, "255.255.%d.0", 256 - pow(2, (8 - maskBits)));

    printf("\nNetwork Address\t\t\tBroadcast Address\tSubnet Mask\n");

    // Loop through all subnets and calculate network and broadcast addresses
    for (int i = 1; i <= subnets; i++) {
        int network = i * pow(2, (8 - maskBits));
        int broadcast = ((i + 1) * pow(2, (8 - maskBits))) - 1;

        int subnet1 = octet1;
        int subnet2 = octet2 + (network / pow(2, 8));
        int subnet3 = octet3 + ((network % (int)pow(2, 8)) / pow(2, (8 - maskBits)));
        int subnet4 = octet4 + (network % (int)pow(2, (8 - maskBits)));

        int broadcast1 = octet1;
        int broadcast2 = octet2 + (broadcast / pow(2, 8));
        int broadcast3 = octet3 + ((broadcast % (int)pow(2, 8)) / pow(2, (8 - maskBits)));
        int broadcast4 = octet4 + (broadcast % (int)pow(2, (8 - maskBits)));

        printf("%d.%d.%d.%d\t\t\t%d.%d.%d.%d\t\t%s/%d\n", subnet1, subnet2, subnet3, subnet4, broadcast1, broadcast2, broadcast3, broadcast4, mask, 24 + maskBits);
    }

    return 0;
}
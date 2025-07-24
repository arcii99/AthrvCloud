//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int subnet_mask, address_byte1, address_byte2, address_byte3, address_byte4;
    int subnet_octet1, subnet_octet2, subnet_octet3, subnet_octet4;
    int wildcard_octet1, wildcard_octet2, wildcard_octet3, wildcard_octet4;

    printf("Enter the subnet mask in CIDR notation (e.g. /24): ");
    scanf("%d", &subnet_mask);

    //Calculate subnet octets
    subnet_octet1 = 255;
    subnet_octet2 = subnet_octet3 = subnet_octet4 = 0;

    if(subnet_mask > 8)
        subnet_octet2 = pow(2, (subnet_mask - 8)) - 1;

    if(subnet_mask > 16)
        subnet_octet3 = pow(2, (subnet_mask - 16)) - 1;

    if(subnet_mask > 24)
        subnet_octet4 = pow(2, (subnet_mask - 24)) - 1;

    //Calculate wildcard octets
    wildcard_octet1 = 0;
    wildcard_octet2 = 255 - subnet_octet2;
    wildcard_octet3 = 255 - subnet_octet3;
    wildcard_octet4 = 255 - subnet_octet4;

    printf("Enter the IP address in x.x.x.x format: ");
    scanf("%d.%d.%d.%d", &address_byte1, &address_byte2, &address_byte3, &address_byte4);

    printf("Subnet mask: %d.%d.%d.%d\n", subnet_octet1, subnet_octet2, subnet_octet3, subnet_octet4);
    printf("Wildcard mask: %d.%d.%d.%d\n", wildcard_octet1, wildcard_octet2, wildcard_octet3, wildcard_octet4);

    return 0;
}
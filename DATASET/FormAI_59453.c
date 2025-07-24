//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>

int main() {
    int subnet_mask, bits, networks, hosts, num, x;
    char address[16];

    printf("Enter IP address in format xxx.xxx.xxx.xxx: ");
    scanf("%s", address);

    printf("Enter subnet mask in decimal format: ");
    scanf("%d", &subnet_mask);

    bits = 32 - subnet_mask;
    networks = pow(2, subnet_mask);
    hosts = pow(2, bits) - 2;

    printf("\n\nSubnet Calculator Results");
    printf("\n------------------------");
    printf("\nIP address:\t%s", address);
    printf("\nSubnet mask:\t%d", subnet_mask);
    printf("\nCIDR notation:\t/%d", subnet_mask);
    printf("\nNumber of networks:\t%d", networks);
    printf("\nNumber of hosts per network:\t%d", hosts);

    printf("\n\nEnter a number of subnets to create: ");
    scanf("%d", &num);

    int subnets[num];
    int host_count[num];

    for(int i=0; i<num; i++) {
        printf("Enter number of hosts for subnet %d: ", i+1);
        scanf("%d", &x);

        subnets[i] = pow(2, ceil(log2(x+2))) - 1; //calculate subnet size with formula
        host_count[i] = pow(2, ceil(log2(x+2))) - 2; //calculate host count with formula
    }

    printf("\n\nSubnet Details");
    printf("\n--------------");

    for(int i=0; i<num; i++) {
        printf("\nSubnet %d:", i+1);
        printf("\nSubnet mask:\t/%d", subnet_mask + (int)log2(subnets[i]) - 24);
        printf("\nCIDR notation:\t/%d", subnet_mask + (int)log2(subnets[i]) - 24);
        printf("\nSubnet size:\t%d", subnets[i]);
        printf("\nNumber of hosts:\t%d", host_count[i]);
    }

    return 0;
}
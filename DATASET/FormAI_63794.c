//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include<stdio.h>

int main(){
    int ipOctets[4], subnetMask, subnetBits, hosts; 
    printf("\nEnter IP Address Octet 1: ");
    scanf("%d",&ipOctets[0]);

    printf("\nEnter IP Address Octet 2: ");
    scanf("%d",&ipOctets[1]);

    printf("\nEnter IP Address Octet 3: ");
    scanf("%d",&ipOctets[2]);

    printf("\nEnter IP Address Octet 4: ");
    scanf("%d",&ipOctets[3]);

    printf("\nEnter Subnet Mask (CIDR Notation): ");
    scanf("%d",&subnetBits);

    subnetMask = 0xffffffff << (32 - subnetBits);

    printf("\nSubnet Mask: %d.%d.%d.%d", (subnetMask >> 24) & 0xff, (subnetMask >> 16) & 0xff, (subnetMask >> 8) & 0xff, subnetMask & 0xff);

    printf("\nNetwork Address: %d.%d.%d.%d", ipOctets[0] & (subnetMask >> 24), ipOctets[1] & (subnetMask >> 16), ipOctets[2] & (subnetMask >> 8), ipOctets[3] & subnetMask);

    hosts = 0xffffffff - subnetMask - 1;

    printf("\nNumber of Hosts: %d", hosts);
    return 0;
}
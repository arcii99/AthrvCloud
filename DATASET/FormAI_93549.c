//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() 
{
    long int ipv4_addr, subnet_mask;
    int b1,b2,b3,b4;
    int s1,s2,s3,s4;

    printf("Enter the IP address in decimal format (x.x.x.x): ");
    scanf("%d.%d.%d.%d", &b1, &b2, &b3, &b4);
    printf("Enter the subnet mask in decimal format (x.x.x.x): ");
    scanf("%d.%d.%d.%d", &s1, &s2, &s3, &s4);

    ipv4_addr = b1*pow(256,3) + b2*pow(256,2) + b3*pow(256,1) + b4*pow(256,0);
    subnet_mask = s1*pow(256,3) + s2*pow(256,2) + s3*pow(256,1) + s4*pow(256,0);

    int i, mask_val;
    int cidr = 0;
    for(i=0;i<32;i++) {
        mask_val = (subnet_mask >> i) & 1;
        if(mask_val == 1) {
            cidr++;
        }
    }

    long int network_addr = ipv4_addr & subnet_mask;
    long int broadcast_addr = network_addr | ~(subnet_mask);

    printf("\nNETWORK ADDRESS: %ld.%ld.%ld.%ld\n", (network_addr & 0xFF000000) >> 24, (network_addr & 0x00FF0000) >> 16, (network_addr & 0x0000FF00) >> 8, (network_addr & 0x000000FF));
    printf("SUBNET MASK: %d.%d.%d.%d\n", s1, s2, s3, s4);
    printf("CIDR NOTATION: /%d\n", cidr);
    printf("BROADCAST ADDRESS: %ld.%ld.%ld.%ld\n", (broadcast_addr & 0xFF000000) >> 24, (broadcast_addr & 0x00FF0000) >> 16, (broadcast_addr & 0x0000FF00) >> 8, (broadcast_addr & 0x000000FF));
    printf("NUMBER OF HOSTS: %ld\n", pow(2, (32-cidr))-2);

    return 0;
}
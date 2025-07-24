//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include<stdio.h>
#include<math.h>

int main()
{
    int subnet_mask;
    unsigned int subnet_bits; 
    int valid_subnet_mask[4] = {255, 254, 252, 248, 240, 224, 192, 128, 0};
    int subnet_octet[4];
    int cidr_notation;
    int prefix_bits;
    unsigned int no_of_hosts;

    printf("Enter the subnet mask (in slash notation): ");
    scanf("%d", &subnet_mask);

    cidr_notation = subnet_mask;

    subnet_bits = pow(2, (8 - (cidr_notation % 8)));
    prefix_bits = cidr_notation % 8;

    subnet_octet[0] = valid_subnet_mask[cidr_notation / 8];

    if(subnet_mask % 8 != 0)
    {
        subnet_octet[cidr_notation / 8 + 1] = subnet_bits - 1;
    }

    for(int i = cidr_notation / 8 + 2; i < 4; i++)
    {
        subnet_octet[i] = 0;
    }

    printf("\nSubnet mask is: %d.%d.%d.%d", subnet_octet[0], subnet_octet[1], subnet_octet[2], subnet_octet[3]);

    no_of_hosts = pow(2, (32 - cidr_notation)) - 2;

    printf("\nNo of Hosts: %u", no_of_hosts);

    return 0;
}
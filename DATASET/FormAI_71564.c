//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IP_LENGTH 15
#define MAX_CIDR_LENGTH 2

int main()
{
    int octet1, octet2, octet3, octet4, cidr;
    int subnet_mask, sub_octet1, sub_octet2, sub_octet3, sub_octet4;
    char ip_address[MAX_IP_LENGTH+1];
    char cidr_str[MAX_CIDR_LENGTH+1];

    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    while(1)
    {
        printf("Enter CIDR notation: ");
        scanf("%s", cidr_str);

        cidr = atoi(cidr_str);

        if(cidr >=0 && cidr <= 32)
            break;

        printf("Invalid CIDR notation. Please enter a value between 0 and 32.\n");
    }

    sscanf(ip_address, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    //Calculating subnet mask
    subnet_mask = 0xFFFFFFFF << (32 - cidr);
    sub_octet1 = (subnet_mask >> 24) & 0xFF;
    sub_octet2 = (subnet_mask >> 16) & 0xFF;
    sub_octet3 = (subnet_mask >> 8) & 0xFF;
    sub_octet4 = subnet_mask & 0xFF;

    printf("\nIP Address\t: %s\n", ip_address);
    printf("CIDR notation\t: %d\n", cidr);
    printf("Subnet Mask\t: %d.%d.%d.%d\n", sub_octet1, sub_octet2, sub_octet3, sub_octet4);

    return 0;
}
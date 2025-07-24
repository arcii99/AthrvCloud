//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    printf("What's up?! Here's a C Subnet Calculator for all your subnetting needs!\n");
    printf("\n");

    char ip_addr[16];
    printf("Enter the IP address (format: xxx.xxx.xxx.xxx): ");
    scanf("%s", ip_addr);

    char *octet1, *octet2, *octet3, *octet4;
    octet1 = strtok(ip_addr, ".");
    octet2 = strtok(NULL, ".");
    octet3 = strtok(NULL, ".");
    octet4 = strtok(NULL, ".");

    int octet_1 = atoi(octet1);
    int octet_2 = atoi(octet2);
    int octet_3 = atoi(octet3);
    int octet_4 = atoi(octet4);

    if(octet_1 >= 0 && octet_1 <= 255 && octet_2 >= 0 && octet_2 <= 255 && octet_3 >= 0 && octet_3 <= 255 && octet_4 >= 0 && octet_4 <= 255)
    {
        printf("\n");
        printf("Got it! The IP address you entered is: %d.%d.%d.%d\n", octet_1, octet_2, octet_3, octet_4);

        int total_hosts, total_subnets;
        printf("Enter the number of hosts required: ");
        scanf("%d", &total_hosts);

        int bits_needed = ceil(log(total_hosts + 2) / log(2));
        int subnet_bits = 32 - bits_needed;

        if(subnet_bits <= 30)
        {
            total_subnets = pow(2, subnet_bits);
            printf("Subnet mask required is /%d\n", subnet_bits);

            int subnet_mask[4] = {0, 0, 0, 0};
            int i;
            for(i = 0; i < subnet_bits; i++)
            {
                subnet_mask[i/8] = subnet_mask[i/8] + (1 << (7 - i % 8));
            }

            printf("Subnet mask in decimal form: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

            int host_bits = 32 - subnet_bits;
            int max_hosts = pow(2, host_bits) - 2;

            printf("Maximum number of hosts per subnet: %d\n", max_hosts);
            printf("Total number of subnets: %d\n", total_subnets);

            int i1, i2, i3, i4;
            i1 = octet_1 & subnet_mask[0];
            i2 = octet_2 & subnet_mask[1];
            i3 = octet_3 & subnet_mask[2];
            i4 = octet_4 & subnet_mask[3];

            printf("Subnet ID: %d.%d.%d.%d\n", i1, i2, i3, i4);

            int b1, b2, b3, b4;
            b1 = octet_1 & ~subnet_mask[0];
            b2 = octet_2 & ~subnet_mask[1];
            b3 = octet_3 & ~subnet_mask[2];
            b4 = octet_4 & ~subnet_mask[3];

            printf("Broadcast Address: %d.%d.%d.%d\n", i1+b1, i2+b2, i3+b3, i4+b4);
        } 
        else 
        {
            printf("Cannot process subnet masks greater than /30\n");
        }
    }
    else 
    {
        printf("\n");
        printf("Whoa! Looks like you have entered an invalid IP address. Please try again!\n");
    }

    printf("\n");
    printf("Hope the C Subnet calculator was helpful! Have a great day ahead!\n");
    return 0;
}
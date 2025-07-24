//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char ip_addr[20], subnet_mask[20];
    int b1, b2, b3, b4, s1, s2, s3, s4, cidr, num_hosts, num_subnets;
    int subnet_octet, octet_val, hosts, subnets, i, j;

    printf("Enter IP Address (e.g., 192.168.1.1): ");
    scanf("%s", ip_addr);
    printf("Enter Subnet Mask (e.g., 255.255.255.0 or /24): ");
    scanf("%s", subnet_mask);

    if (subnet_mask[0] == '/')
    {
        cidr = atoi(&subnet_mask[1]);
        subnet_octet = cidr / 8;
        octet_val = pow(2, 8 - (cidr % 8));
    }
    else
    {
        sscanf(subnet_mask, "%d.%d.%d.%d", &s1, &s2, &s3, &s4);
        cidr = 0;
        subnet_octet = 0;
        octet_val = 0;

        if (s1 == 255)
        {
            cidr += 8;
            subnet_octet++;
        }
        else if (s1 != 0)
        {
            printf("Invalid Subnet Mask.");
            return 0;
        }

        if (s2 == 255)
        {
            cidr += 8;
            subnet_octet++;
        }
        else if (s2 != 0)
        {
            printf("Invalid Subnet Mask.");
            return 0;
        }

        if (s3 == 255)
        {
            cidr += 8;
            subnet_octet++;
        }
        else if (s3 != 0)
        {
            printf("Invalid Subnet Mask.");
            return 0;
        }

        if (s4 == 255)
        {
            cidr += 8;
            subnet_octet++;
        }
        else if (s4 != 0)
        {
            printf("Invalid Subnet Mask.");
            return 0;
        }

        octet_val = pow(2, 8 - (cidr % 8));
    }

    sscanf(ip_addr, "%d.%d.%d.%d", &b1, &b2, &b3, &b4);

    if (b1 > 255 || b2 > 255 || b3 > 255 || b4 > 255)
    {
        printf("Invalid IP Address.");
        return 0;
    }

    num_hosts = pow(2, (32 - cidr)) - 2;
    num_subnets = pow(2, (cidr - subnet_octet)) - 2;

    printf("\n\nIP Address: %s", ip_addr);
    printf("\nSubnet Mask: %s", subnet_mask);
    printf("\nCIDR Notation: /%d", cidr);
    printf("\nNumber of Subnets: %d", num_subnets);
    printf("\nNumber of Hosts: %d", num_hosts);
    printf("\n\nSubnet Details:\n");

    for(i = 0; i < num_subnets; i++)
    {
        printf("\nSubnet %d:\n", i+1);
        printf("Network Address: ");
        if (subnet_octet == 1)
        {
            printf("%d.%d.0.0", b1, i*octet_val);
        }
        else if (subnet_octet == 2)
        {
            printf("%d.%d.%d.0", b1, b2, i*octet_val);
        }
        else if (subnet_octet == 3)
        {
            printf("%d.%d.%d.%d", b1, b2, b3, i*octet_val);
        }

        printf("\nSubnet Mask: ");
        if (subnet_octet == 1)
        {
            printf("%d.0.0.0", octet_val);
        }
        else if (subnet_octet == 2)
        {
            printf("255.%d.0.0", octet_val);
        }
        else if (subnet_octet == 3)
        {
            printf("255.255.%d.0", octet_val);
        }

        printf("\nBroadcast Address: ");
        if (subnet_octet == 1)
        {
            printf("%d.%d.255.255", b1, (i*octet_val)+octet_val-1);
        }
        else if (subnet_octet == 2)
        {
            printf("%d.%d.%d.255", b1, b2, (i*octet_val)+octet_val-1);
        }
        else if (subnet_octet == 3)
        {
            printf("%d.%d.%d.%d", b1, b2, b3, (i*octet_val)+octet_val-1);
        }

        printf("\nHosts:\n");

        for(j = 1; j <= num_hosts; j++)
        {
            if (subnet_octet == 1)
            {
                printf("%d.%d.0.%d\n", b1, i*octet_val, j);
            }
            else if (subnet_octet == 2)
            {
                printf("%d.%d.%d.%d\n", b1, b2, i*octet_val, j);
            }
            else if (subnet_octet == 3)
            {
                printf("%d.%d.%d.%d\n", b1, b2, b3, i*octet_val+j);
            }
        }
    }
    
    return 0;
}
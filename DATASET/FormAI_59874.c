//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main()
{
    // Input IP and Subnet Mask as integers
    int ip[4];
    int subnet_mask[4];
    
    // Get user input for IP address
    printf("Enter the IP Address [e.g. 192.168.1.1]: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    
    // Get user input for Subnet Mask
    printf("Enter the Subnet Mask [e.g. 255.255.255.0]: ");
    scanf("%d.%d.%d.%d", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);
    
    // Calculate Network and Host Addresses
    int network[4];
    int host[4];
    
    int i;
    for (i = 0; i < 4; i++)
    {
        network[i] = ip[i] & subnet_mask[i];
        host[i] = ip[i] & ~(subnet_mask[i]);
    }
    
    // Calculate Number of Hosts
    int num_hosts = pow(2, (32 - (int)(log2(subnet_mask[3])))) - 2;
    
    // Output Results
    printf("IP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Host Address: %d.%d.%d.%d\n", host[0], host[1], host[2], host[3]);
    printf("Number of Hosts: %d\n", num_hosts);
    
    return 0;
}
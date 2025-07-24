//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char IP[20], subnet[20];
    int mask, octet1, octet2, octet3, octet4;

    printf("Enter IP address: ");
    scanf("%s", IP);
    printf("Enter subnet mask: ");
    scanf("%s", subnet);

    sscanf(IP,"%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    sscanf(subnet,"%d", &mask);

    int binary_mask = 0xFFFFFFFF << (32 - mask);
    int binary_subnet = (octet1 << 24) + (octet2 << 16) + (octet3 << 8) + octet4;
    int network_address = binary_subnet & binary_mask;
    int host_address = binary_subnet & ~binary_mask;
    int total_hosts = pow(2, (32 - mask)) - 2;

    printf("\nNetwork Address: %d.%d.%d.%d\n", (network_address >> 24), 
           (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, 
           network_address & 0xFF);
    printf("Host Address Range: %d.%d.%d.%d - %d.%d.%d.%d\n", 
           (network_address >> 24), (network_address >> 16) & 0xFF, 
           (network_address >> 8) & 0xFF, (network_address & 0xFF) + 1,
           (network_address >> 24) | (~binary_mask >> 24 & 0xFF), 
           (network_address >> 16) | (~binary_mask >> 16 & 0xFF), 
           (network_address >> 8) | (~binary_mask >> 8 & 0xFF), 
           (network_address | ~binary_mask & 0xFF) - 1);
    printf("Total Hosts: %d\n", total_hosts);

    return 0;
}
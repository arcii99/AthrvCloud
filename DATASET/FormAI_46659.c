//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

int main() {
    int octet1, octet2, octet3, octet4, prefix, subnet, hosts;
    int mask1, mask2, mask3, mask4;
    int numSubnets, numHosts;
    
    //Prompt the user for IP address and prefix length
    printf("Enter IP Address: ");
    scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    printf("Enter Prefix Length: ");
    scanf("%d", &prefix);
    
    //Calculate subnet and hosts per subnet
    subnet = pow(2, (32 - prefix));
    hosts = subnet - 2;
    
    //Calculate subnet mask
    numSubnets = 256 / subnet;
    numHosts = hosts + 2;
    mask1 = 256 - subnet;
    mask2 = hosts / 256;
    mask3 = hosts % 256;
    mask4 = subnet - 1;
    
    //Print results
    printf("\nNumber of subnets: %d\n", numSubnets);
    printf("Hosts per subnet: %d\n", numHosts);
    printf("Subnet mask: %d.%d.%d.%d\n", mask1, mask2, mask3, mask4);
    
    return 0;
}
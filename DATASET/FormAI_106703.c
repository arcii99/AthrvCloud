//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int networkAddress, subnetMask, numSubnets, numHosts, decimal1, decimal2, decimal3, decimal4, bitMask;
    printf("Welcome to the Medieval Subnet Calculator!\n");
    printf("Please enter the network address in decimal format (ex: 192.168.0.0): ");
    scanf("%d.%d.%d.%d", &decimal1, &decimal2, &decimal3, &decimal4);
    networkAddress = (decimal1 << 24) | (decimal2 << 16) | (decimal3 << 8) | decimal4;
    printf("Please enter the subnet mask in decimal format (ex: 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &decimal1, &decimal2, &decimal3, &decimal4);
    subnetMask = (decimal1 << 24) | (decimal2 << 16) | (decimal3 << 8) | decimal4;
    bitMask = 0;
    while((1u << bitMask) <= subnetMask)
    {
        bitMask++;
    }
    numSubnets = (1u << bitMask);
    numHosts = (1u << (32 - bitMask)) - 2;
    printf("\nYou have entered the following information:\n");
    printf("Network Address: %d.%d.%d.%d\n", (networkAddress >> 24) & 0xFF, (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, (subnetMask >> 8) & 0xFF, subnetMask & 0xFF);
    printf("Number of Subnets: %d\n", numSubnets);
    printf("Number of Hosts per Subnet: %d\n", numHosts);
    printf("\nCalculating result using complex medieval magic!\n");
    printf("Your network shall be divided into %d mighty subnets, each with up to %d valiant hosts!\n", numSubnets, numHosts);
    printf("With our magic, we have also determined that your broadcast address is %d.%d.%d.%d.\n", (networkAddress | (~subnetMask)) >> 24 & 0xFF, (networkAddress | (~subnetMask)) >> 16 & 0xFF, (networkAddress | (~subnetMask)) >> 8 & 0xFF, (networkAddress | (~subnetMask)) & 0xFF);
    printf("May your network prosper and thrive!\n");
    return 0;
}
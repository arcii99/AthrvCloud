//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t getNetworkAddress(uint32_t ipAddress, uint32_t subnetMask)
{
    return (ipAddress & subnetMask);
}

int getNumOfHosts(uint32_t subnetMask)
{
    uint32_t num = ntohl(~subnetMask) + 1;
    return num;
}

int getPrefixLength(uint32_t subnetMask)
{
    int count = 0;
    while(subnetMask)
    {
        count++;
        subnetMask >>= 1;
    }
    return count;
}

int main()
{
    printf("************ IPv4 Subnet Calculator ************\n\n");
    uint32_t ipAddress, subnetMask;
    printf("Enter IP address in decimal format: ");
    scanf("%u", &ipAddress);
    printf("Enter Subnet mask in decimal format: ");
    scanf("%u", &subnetMask);
    uint32_t networkAddress = getNetworkAddress(ipAddress, subnetMask);
    printf("\nNetwork Address: %u.%u.%u.%u\n", (networkAddress >> 24), (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);
    int numOfHosts = getNumOfHosts(subnetMask);
    printf("Number of Hosts: %d\n", numOfHosts);
    int prefixLength = getPrefixLength(subnetMask);
    printf("Prefix Length: /%d\n", prefixLength);
    return 0;
}
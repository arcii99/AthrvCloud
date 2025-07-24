//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include<stdio.h>

int main(){
    
    unsigned long ipAddress;
    unsigned int maskBits;
    unsigned long subnetMask, wildcardMask, networkAddress, broadcastAddress;
    
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address: ");
    scanf("%lu", &ipAddress);
    
    printf("Please enter the number of mask bits: ");
    scanf("%u", &maskBits);

    subnetMask = ~0 << (32 - maskBits);
    wildcardMask = ~subnetMask;
    networkAddress = ipAddress & subnetMask;
    broadcastAddress = networkAddress | wildcardMask;
    
    printf("\nSubnet mask: %lu.%lu.%lu.%lu\n", (subnetMask >> 24) & 0xff, (subnetMask >> 16) & 0xff, 
                                              (subnetMask >> 8) & 0xff, subnetMask & 0xff);
    printf("Wildcard mask: %lu.%lu.%lu.%lu\n", (wildcardMask >> 24) & 0xff, (wildcardMask >> 16) & 0xff, 
                                              (wildcardMask >> 8) & 0xff, wildcardMask & 0xff);
    printf("Network address: %lu.%lu.%lu.%lu\n", (networkAddress >> 24) & 0xff, (networkAddress >> 16) & 0xff, 
                                                 (networkAddress >> 8) & 0xff, networkAddress & 0xff);
    printf("Broadcast address: %lu.%lu.%lu.%lu\n", (broadcastAddress >> 24) & 0xff, (broadcastAddress >> 16) & 0xff, 
                                                   (broadcastAddress >> 8) & 0xff, broadcastAddress & 0xff);
    
    return 0;
}
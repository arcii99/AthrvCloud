//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <math.h>

// function to calculate network address
unsigned long calculateNetworkAddress(unsigned long ipAddress, unsigned long subnetMask) {
    return ipAddress & subnetMask;
}

// function to calculate broadcast address
unsigned long calculateBroadcastAddress(unsigned long ipAddress, unsigned long subnetMask) {
    return ipAddress | (~subnetMask);
}

// function to calculate number of hosts per subnet
unsigned int calculateHostsPerSubnet(unsigned long subnetMask) {
    return pow(2, (32 - log2(subnetMask)));
}

int main() {
    unsigned long ipAddress, subnetMask;
    
    printf("Enter IP Address in decimal format: ");
    scanf("%lu", &ipAddress);
    
    printf("Enter Subnet Mask in decimal format: ");
    scanf("%lu", &subnetMask);
    
    // calculate network and broadcast addresses
    unsigned long networkAddress = calculateNetworkAddress(ipAddress, subnetMask);
    unsigned long broadcastAddress = calculateBroadcastAddress(ipAddress, subnetMask);

    // calculate number of hosts per subnet
    unsigned int hostsPerSubnet = calculateHostsPerSubnet(subnetMask);
    
    // print results
    printf("\nNetwork Address = %lu\n", networkAddress);
    printf("Broadcast Address = %lu\n", broadcastAddress);
    printf("No. of Hosts per Subnet = %u\n", hostsPerSubnet);
    
    return 0;
}
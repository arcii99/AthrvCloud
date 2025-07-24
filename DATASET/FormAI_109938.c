//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: genious
/*
  The following program is a subnet calculator that takes an IP address and subnet mask as input 
  and calculates the network and broadcast addresses along with the range of available host addresses.
  It is written in C language and uses bitwise operators to perform the calculations.
*/

#include <stdio.h>

int main() {
  // Initialize variables
  unsigned int ipAddress, subnetMask, networkAddress, broadcastAddress, numAvailableHosts;
  
  // User input for IP address
  printf("Enter IP address in decimal format (e.g. 192.168.1.1): ");
  scanf("%u", &ipAddress);
  
  // User input for subnet mask
  printf("Enter subnet mask in decimal format (e.g. 255.255.255.0): ");
  scanf("%u", &subnetMask);
  
  // Calculate network address by performing bitwise AND operation between IP address and subnet mask
  networkAddress = ipAddress & subnetMask;
  
  // Calculate wildcard mask (inverse subnet mask) by performing bitwise NOT on subnet mask
  unsigned int wildcardMask = ~subnetMask;
  
  // Calculate broadcast address by performing bitwise OR between network address and wildcard mask
  broadcastAddress = networkAddress | wildcardMask;
  
  // Count the number of available host addresses by subtracting 2 from the total number of addresses (network and broadcast addresses)
  numAvailableHosts = ~wildcardMask - 1;
  
  // Produce output
  printf("\nNetwork Address: %u.%u.%u.%u\n", (networkAddress >> 24) & 0xFF, (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);
  printf("Broadcast Address: %u.%u.%u.%u\n", (broadcastAddress >> 24) & 0xFF, (broadcastAddress >> 16) & 0xFF, (broadcastAddress >> 8) & 0xFF, broadcastAddress & 0xFF);
  printf("Number of Available Hosts: %u\n", numAvailableHosts);
  
  return 0; // End program
}
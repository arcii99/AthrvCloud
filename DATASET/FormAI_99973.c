//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>

int main() {
  printf("\nWelcome to the C Subnet Calculator!\n");
  
  int subnetMask, numHosts, numSubnets;
  printf("\nEnter the subnet mask in CIDR notation (e.g. 24 for /24): ");
  scanf("%d", &subnetMask);
  
  numSubnets = 1 << (32 - subnetMask); // bitwise shift to calculate number of subnets
  numHosts = (1 << (32 - subnetMask)) - 2; // calculate number of hosts per subnet
  
  printf("\nNumber of subnets: %d", numSubnets);
  printf("\nNumber of hosts per subnet: %d\n", numHosts);

  return 0;
}
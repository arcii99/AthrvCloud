//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>

int main() {
  int networkIP, subnetMask, cidr, numSubnets, numHosts;
  printf("Welcome to the Happy Subnet Calculator!\n");
  printf("Enter the network IP address (in decimal format): ");
  scanf("%d", &networkIP);
  printf("Enter the subnet mask (in decimal format): ");
  scanf("%d", &subnetMask);
  cidr = 0;
  for (int i = 0; i < 32; i++) {
    if (subnetMask & (1 << i)) {
      cidr++;
    }
  }
  printf("CIDR notation: /%d\n", cidr);
  numSubnets = 1 << (32 - cidr);
  printf("Number of subnets: %d\n", numSubnets);
  numHosts = (1 << (32 - cidr)) - 2;
  printf("Number of hosts per subnet: %d\n", numHosts);
  printf("Maximum number of hosts: %d\n", (1 << (32 - cidr)) - 1);
  return 0;
}
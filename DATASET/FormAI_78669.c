//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <math.h>

int main() {
  int subnet_mask; // stores the subnet mask in CIDR notation
  int subnet_octets[4]; // stores the subnet mask in octets

  printf("Enter the subnet mask in CIDR notation: ");
  scanf("%d", &subnet_mask);
  printf("\n");

  // convert the subnet mask from CIDR notation to octets
  subnet_octets[0] = (int)pow(2, (double)(subnet_mask / 8)) - 1;
  subnet_octets[1] = (int)pow(2, (double)(subnet_mask / 8)) - 1;
  subnet_octets[2] = (int)pow(2, (double)(subnet_mask / 8)) - 1;
  subnet_octets[3] = (int)pow(2, (double)(subnet_mask % 8)) - 1;

  // calculate the number of subnets and hosts per subnet based on the subnet mask
  int num_subnets = (int)pow(2, (double)(32 - subnet_mask));
  int num_hosts = (int)pow(2, (double)(8 - (subnet_mask % 8))) - 2;

  // output the results
  printf("Subnet mask in CIDR notation: /%d\n", subnet_mask);
  printf("Subnet mask in octets: %d.%d.%d.%d\n", subnet_octets[0], subnet_octets[1], subnet_octets[2], subnet_octets[3]);
  printf("Number of subnets: %d\n", num_subnets);
  printf("Number of hosts per subnet: %d\n", num_hosts);

  return 0;
}
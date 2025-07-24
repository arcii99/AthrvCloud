//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Subnet Calculator!\n");
  
  unsigned int ip, subnet_mask, subnet_bits;
  
  printf("Please enter the IP address in decimal format (e.g. 192.168.0.1): ");
  scanf("%u", &ip);
  
  printf("Please enter the subnet mask in decimal format (e.g. 255.255.255.0): ");
  scanf("%u", &subnet_mask);
  
  int bitcount = 0;
  unsigned int bits = subnet_mask;
  while (bits) {
    bitcount++;
    bits &= bits - 1;
  }

  printf("The number of subnet bits is: ");
  scanf("%u", &subnet_bits);

  unsigned int total_hosts = (1 << (32 - bitcount)) - 2;
  unsigned int usable_hosts = (1 << subnet_bits) - 2;
  unsigned int subnets = 1 << subnet_bits;
  unsigned int host_per_subnet = total_hosts / subnets;

  printf("\nTotal Hosts: %u\n", total_hosts);
  printf("Usable Hosts Per Subnet: %u\n", usable_hosts);
  printf("Total Subnets: %u\n", subnets);
  printf("Hosts Per Subnet: %u\n", host_per_subnet);

  return 0;
}
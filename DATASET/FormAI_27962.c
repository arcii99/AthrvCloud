//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include<stdio.h>

int main()
{
  // Welcome message for the user
  printf("Welcome to the Brave Subnet Calculator\n");

  // Declare variables
  unsigned int subnet_mask, ip_address;
  int octet1, octet2, octet3, octet4, cidr;

  // Get user input for IP address and Subnet Mask
  printf("Enter IP address: ");
  scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
  ip_address = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;

  printf("Enter Subnet Mask (in CIDR notation): ");
  scanf("%u", &subnet_mask);

  // Calculate the number of hosts and number of subnets
  unsigned int num_hosts = (1 << (32 - subnet_mask)) - 2;
  unsigned int num_subnets = 1 << subnet_mask;

  // Print the results
  printf("\n\nIP Address: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
  printf("Subnet Mask: %u\n", subnet_mask);
  printf("Number of Hosts: %u\n", num_hosts);
  printf("Number of Subnets: %u\n", num_subnets);

  // Determine the Network and Broadcast addresses
  unsigned int network_address = ip_address & ((0xFFFFFFFF) << (32 - subnet_mask));
  unsigned int broadcast_address = network_address | ((1 << (32 - subnet_mask)) - 1);

  // Print the Network and Broadcast addresses
  printf("\n\nNetwork Address: %d.%d.%d.%d\n", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);
  printf("Broadcast Address: %d.%d.%d.%d\n", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);

  return 0;
}
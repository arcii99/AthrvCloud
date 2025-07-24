//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: calm
/* C Subnet Calculator Program */

#include <stdio.h>
#include <stdlib.h>

int main() {
  char ip_address[16], subnet_mask[16];
  int bits, valid = 1;

  printf("Enter IP Address: ");
  scanf("%s", ip_address);

  printf("Enter Subnet Mask: ");
  scanf("%s", subnet_mask);

  if (sscanf(subnet_mask, "/%d", &bits) != 1) {
    printf("Error: Invalid Subnet Mask format!\n");
    valid = 0;
  }

  if (valid) {
    // Calculate the Network Address
    unsigned long ip = ntohl(inet_addr(ip_address));
    unsigned long mask = (~0) << (32 - bits);
    unsigned long network = ip & mask;

    // Calculate the Broadcast Address
    unsigned long broadcast = network | ~mask;

    // Calculate the Total Number of Hosts
    int hosts = broadcast - network - 1;

    printf("Network Address: %d.%d.%d.%d\n", 
      (network >> 24) & 0xff, 
      (network >> 16) & 0xff, 
      (network >> 8) & 0xff, 
      network & 0xff);

    printf("Broadcast Address: %d.%d.%d.%d\n", 
      (broadcast >> 24) & 0xff, 
      (broadcast >> 16) & 0xff, 
      (broadcast >> 8) & 0xff, 
      broadcast & 0xff);

    printf("Total Number of Hosts: %d\n", hosts);
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Subnet Calculator!\n");
  printf("Enter IP address in the format xxx.xxx.xxx.xxx: ");
  
  int octet1, octet2, octet3, octet4;
  scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
  
  printf("Enter subnet mask in CIDR notation: ");
  int cidr;
  scanf("%d", &cidr);
  
  int subnetMask = 0;
  for(int i = 0; i < cidr; i++) subnetMask |= 1 << (31 - i);
  
  printf("\nSubnet mask: %d.%d.%d.%d\n", subnetMask >> 24 & 0xFF, subnetMask >> 16 & 0xFF, subnetMask >> 8 & 0xFF, subnetMask & 0xFF);
  
  int networkAddress = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;
  int broadcastAddress = networkAddress | (~subnetMask & 0xFFFFFFFF);
  
  printf("Network address: %d.%d.%d.%d\n", networkAddress >> 24 & 0xFF, networkAddress >> 16 & 0xFF, networkAddress >> 8 & 0xFF, networkAddress & 0xFF);
  
  printf("Broadcast address: %d.%d.%d.%d\n", broadcastAddress >> 24 & 0xFF, broadcastAddress >> 16 & 0xFF, broadcastAddress >> 8 & 0xFF, broadcastAddress & 0xFF);
  
  int numHosts = ~(subnetMask | 0xFFFFFFFF) + 1;
  printf("Number of hosts: %d\n", numHosts - 2);
  
  printf("Thank you for using the Happy Subnet Calculator!\n");
  
  return 0;
}
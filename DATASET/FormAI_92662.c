//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[20];
  printf("Enter an IP address and a subnet mask in the following format: x.x.x.x/xx\n");
  scanf("%s", input);
  
  char* ipAddress = strtok(input, "/");
  char* subnetMask = strtok(NULL, "/");
  
  if(!(ipAddress && subnetMask)) {
    printf("Invalid input.\n");
    return 1;
  }
  
  int ip[4];
  if (sscanf(ipAddress, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]) != 4) {
    printf("Invalid IP address format.\n");
    return 1;
  }
  
  int mask;
  if (sscanf(subnetMask, "%d", &mask) != 1 || mask < 0 || mask > 32) {
    printf("Invalid subnet mask format.\n");
    return 1;
  }
  
  int subnetSize = 1 << (32 - mask);
  int subnetMaskInt = 0xffffffff << (32 - mask);
  int networkAddress = (ip[0] << 24) | (ip[1] << 16) | (ip[2] << 8) | ip[3];
  int networkAddressInt = networkAddress & subnetMaskInt;
  int broadcastAddress = networkAddressInt | (subnetSize - 1);
  
  printf("IP address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
  printf("Subnet mask: %d\n", mask);
  printf("Subnet size: %d\n", subnetSize);
  printf("Network address: %d.%d.%d.%d\n", (networkAddressInt >> 24) & 0xff, (networkAddressInt >> 16) & 0xff, (networkAddressInt >> 8) & 0xff, networkAddressInt & 0xff);
  printf("Broadcast address: %d.%d.%d.%d\n", (broadcastAddress >> 24) & 0xff, (broadcastAddress >> 16) & 0xff, (broadcastAddress >> 8) & 0xff, broadcastAddress & 0xff);

  return 0;
}
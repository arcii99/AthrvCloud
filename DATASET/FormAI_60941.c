//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <math.h>

int main() {
  unsigned int maskBits;
  unsigned int mask = 0xFFFFFFFF;
  unsigned int networkAddress;
  unsigned int broadcastAddress;
  unsigned int firstHost;
  unsigned int lastHost;

  printf("Enter Subnet Mask Bits: ");
  scanf("%d", &maskBits);

  mask = mask << (32 - maskBits);
  networkAddress = 0x0A000000 & mask;
  broadcastAddress = networkAddress | (~mask & 0x00FFFFFF);

  firstHost = networkAddress + 1;
  lastHost = broadcastAddress - 1;

  printf("\nSubnet Information:\n");
  printf("Mask: %d.%d.%d.%d\n", (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);
  printf("Network Address: %d.%d.%d.%d\n", (networkAddress >> 24) & 0xFF, (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);
  printf("Broadcast Address: %d.%d.%d.%d\n", (broadcastAddress >> 24) & 0xFF, (broadcastAddress >> 16) & 0xFF, (broadcastAddress >> 8) & 0xFF, broadcastAddress & 0xFF);
  printf("First Host: %d.%d.%d.%d\n", (firstHost >> 24) & 0xFF, (firstHost >> 16) & 0xFF, (firstHost >> 8) & 0xFF, firstHost & 0xFF);
  printf("Last Host: %d.%d.%d.%d\n", (lastHost >> 24) & 0xFF, (lastHost >> 16) & 0xFF, (lastHost >> 8) & 0xFF, lastHost & 0xFF);

  return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>

int main() {
  int ip[4], subnetBits;

  // Take IP address as user input
  printf("Enter IP address in the format x.x.x.x: ");
  scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

  // Take subnet bits as user input
  printf("Enter subnet bits: ");
  scanf("%d", &subnetBits);

  // Calculate subnet mask
  int subnetMask[4], i, j;
  for (i = 0; i < 4; i++) {
    subnetMask[i] = 0;
    for (j = 7; j >= 0 && subnetBits > 0; j--, subnetBits--) {
      subnetMask[i] += 1 << j;
    }
  }

  // Print subnet mask and network address
  printf("Subnet mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
  printf("Network address: %d.%d.%d.%d\n", ip[0] & subnetMask[0], ip[1] & subnetMask[1], ip[2] & subnetMask[2], ip[3] & subnetMask[3]);

  return 0;
}
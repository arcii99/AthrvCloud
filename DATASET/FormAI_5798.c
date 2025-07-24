//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>

int main() {
  int prefix;
  int subnetMask[4];
  int networkAddress[4];
  int broadcastAddress[4];

  printf("Enter the prefix length to calculate the subnet mask: ");
  scanf("%d", &prefix);

  int i;
  for (i = 0; i < 4; i++) {
    if (prefix >= 8) {
      subnetMask[i] = 255;
      prefix -= 8;
    } else {
      subnetMask[i] = 256 - (1 << (8 - prefix));
      prefix = 0;
    }
  }

  printf("\nSubnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);

  int ipAddress[4];
  printf("\nEnter an IP address: ");
  scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);

  for (i = 0; i < 4; i++) {
    networkAddress[i] = ipAddress[i] & subnetMask[i];
    broadcastAddress[i] = networkAddress[i] | ~subnetMask[i];
  }

  printf("\nNetwork Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
  printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);

  return 0;
}
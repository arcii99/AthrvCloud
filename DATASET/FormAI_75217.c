//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
  unsigned int subnetMask, hostBits, i, j;
  unsigned int subnetOctet[4], ipAddressOctet[4], networkOctet[4], broadcastOctet[4];

  printf("Enter the IP Address in the format x.x.x.x: ");
  scanf("%d.%d.%d.%d",&ipAddressOctet[0], &ipAddressOctet[1], &ipAddressOctet[2], &ipAddressOctet[3]);

  printf("\nEnter the subnet mask in the format x.x.x.x: ");
  scanf("%d.%d.%d.%d", &subnetOctet[0], &subnetOctet[1], &subnetOctet[2], &subnetOctet[3]);

  subnetMask = (subnetOctet[0] << 24) + (subnetOctet[1] << 16) + (subnetOctet[2] << 8) + subnetOctet[3];

  printf("\nSubnet Mask: %d.%d.%d.%d\n",subnetOctet[0], subnetOctet[1], subnetOctet[2], subnetOctet[3]);

  hostBits = 32;
  for (i = 0; i < 4; i++) {
    for (j = 0; j <= 7; j++) {
      if ((subnetMask & (1 << j)) == 0) {
        hostBits--;
      }
    subnetMask <<=1;
    }
  }
  printf("\nNumber of Host bits: %d", hostBits);
  printf("\nNumber of Available Hosts per Subnet: %u", (1 << hostBits) - 2);

  for (i = 0; i < 4; i++) {
    networkOctet[i] = ipAddressOctet[i] & subnetOctet[i];
    broadcastOctet[i] = networkOctet[i] | (~subnetOctet[i] & 0xff);
  }

  printf("\nNetwork Address: %d.%d.%d.%d\n",networkOctet[0], networkOctet[1], networkOctet[2], networkOctet[3]);
  printf("\nBroadcast Address: %d.%d.%d.%d\n",broadcastOctet[0], broadcastOctet[1], broadcastOctet[2], broadcastOctet[3]);

  return 0;
}
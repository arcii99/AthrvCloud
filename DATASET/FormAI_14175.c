//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
  char ipAddr[15];
  char subnetMask[15];
  int subnetBits;
  int subnetId[4];

  printf("Enter IP address: ");
  scanf("%s", &ipAddr);

  printf("Enter subnet mask in dotted decimal notation: ");
  scanf("%s", &subnetMask);

  // Calculate subnet bits
  subnetBits = 0;
  char* token = strtok(subnetMask, ".");
  while (token != NULL) {
    int octet = atoi(token);
    while (octet > 0) {
      subnetBits++;
      octet <<= 1;
    }
    token = strtok(NULL, ".");
  }

  // Calculate subnet ID
  token = strtok(ipAddr, ".");
  int i = 0;
  while (token != NULL) {
    int octet = atoi(token);
    subnetId[i] = octet & (0xFF << (8 - subnetBits % 8));
    i++;
    subnetBits -= 8;
    token = strtok(NULL, ".");
  }

  printf("Subnet ID: %d.%d.%d.%d\n", subnetId[0], subnetId[1], subnetId[2], subnetId[3]);
  
  return 0;
}
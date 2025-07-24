//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>

int main() {
  int subnets, hosts, mask_bits, addresses;
  
  printf("Enter the number of subnets : ");
  scanf("%d", &subnets);
  
  printf("Enter the number of hosts per subnet : ");
  scanf("%d", &hosts);
  
  mask_bits = 0;
  while ((subnets * hosts) > (1 << mask_bits))
    mask_bits++;
  
  printf("\nSummary:\n");
  printf("Subnets required : %d\n", subnets);
  printf("Hosts per subnet : %d\n", hosts);
  printf("Mask bits : %d\n", mask_bits);
  
  addresses = (1 << mask_bits);
  printf("Address block : %d.%d.%d.%d/%d\n", 192, 168, 0, 0, 24 + mask_bits);
  printf("Network address : %d.%d.%d.%d\n", 192, 168, 0, 0);
  printf("Broadcast address : %d.%d.%d.%d\n", 192, 168, (addresses >> 8) - 1, (addresses & 0xFF) - 1);
  
  return 0;
}
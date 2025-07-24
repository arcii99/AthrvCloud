//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>

int main(){
   int subnet_mask, subnet_bits, mask_octet[4] = {0, 0, 0, 0};
   printf("Enter the subnet mask in CIDR notation: ");
   scanf("%d", &subnet_bits);
   subnet_mask = 0xFFFFFFFF << (32 - subnet_bits);
   mask_octet[0] = (subnet_mask & 0xFF000000) >> 24;
   mask_octet[1] = (subnet_mask & 0x00FF0000) >> 16;
   mask_octet[2] = (subnet_mask & 0x0000FF00) >> 8;
   mask_octet[3] = subnet_mask & 0x000000FF;
   printf("\nThe subnet mask is: %d.%d.%d.%d\n",mask_octet[0], mask_octet[1], mask_octet[2], mask_octet[3]);
   return 0;
}
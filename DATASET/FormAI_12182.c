//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

int main() {
   int IP[4], BITS, SUBNET;
   int SUBNET_MASK[4];
   
   printf("Enter the IP address (in decimal): ");
   scanf("%d.%d.%d.%d", &IP[0], &IP[1], &IP[2], &IP[3]);
   
   printf("Enter the number of bits in the Subnet Mask: ");
   scanf("%d", &BITS);
   
   SUBNET = pow(2, (32 - BITS));
   SUBNET_MASK[0] = 255 & ((~0) << (8 - BITS));
   SUBNET_MASK[1] = BITS > 8 ? 255 : 0;
   SUBNET_MASK[2] = BITS > 16 ? 255 : 0;
   SUBNET_MASK[3] = BITS > 24 ? 255 : 0;
   
   printf("Subnet Mask is: %d.%d.%d.%d\n", SUBNET_MASK[0], SUBNET_MASK[1], SUBNET_MASK[2], SUBNET_MASK[3]);
   
   printf("Network Address is: %d.%d.%d.%d\n", IP[0] & SUBNET_MASK[0], IP[1] & SUBNET_MASK[1], IP[2] & SUBNET_MASK[2], IP[3] & SUBNET_MASK[3]);
   
   printf("Broadcast Address is: %d.%d.%d.%d\n", (IP[0] & SUBNET_MASK[0]) | (~SUBNET_MASK[0]), (IP[1] & SUBNET_MASK[1]) | (~SUBNET_MASK[1]), (IP[2] & SUBNET_MASK[2]) | (~SUBNET_MASK[2]), (IP[3] & SUBNET_MASK[3]) | (~SUBNET_MASK[3]));
   
   printf("Number of Valid Hosts per Subnet: %d\n", SUBNET - 2);
   
   return 0;
}
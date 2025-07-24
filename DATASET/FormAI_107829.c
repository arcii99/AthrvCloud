//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>

int main() {
   int mask, cidr, i;
   char ip[15];
   printf("Enter the IP address: ");
   scanf("%s",ip);
   printf("Enter CIDR notation: ");
   scanf("%d",&cidr);
   mask = 0xffffffff << (32 - cidr); 
   printf("\nIP address: %s\n", ip); 
   printf("Subnet mask: ");
   for (i = 0; i < 4; i++) {
      printf("%d", (mask >> (24 - 8 * i)) & 0xff);
      if (i != 3) {
         printf(".");
      }
   }
   printf("\nSubnet ID: ");
   for (i = 0; i < 4; i++) {
      printf("%d", ((mask & ip[i]) >> (24 - i*8)));
      if (i != 3) {
         printf(".");
      }
   }
   printf("\nNumber of hosts: %d\n", 1<<(32-cidr)-2);
   return 0;
}
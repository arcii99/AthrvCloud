//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

void printSubnetMask(int net_bits) {
   int octet[4], i;
   memset(octet, 0, 4);
   for (i = 0; i < net_bits; i++) {
      octet[i / 8] += 1 << (7 - i % 8);
   }
   printf("%d.%d.%d.%d\n", octet[0], octet[1], octet[2], octet[3]);
}

int main(int argc, char *argv[]) {
   if (argc != 3) {
      printf("Usage: %s <ip_address> <net_mask_bits>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   char *ip = argv[1]; 
   int net_bits = atoi(argv[2]);
   struct in_addr address;
   
   if (!inet_aton(ip, &address)) {
      printf("Invalid IP address entered.\n");
      exit(EXIT_FAILURE);
   }

   int cidr = net_bits;
   printf("CIDR notation: /%d\n", cidr);
   
   printSubnetMask(net_bits);

   return 0;
}
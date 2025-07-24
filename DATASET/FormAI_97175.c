//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
   int network_address = 0;
   int subnet_mask = 0;
   int subnet_size = 0;

   printf("Enter network address in decimal format:\n");
   scanf("%d", &network_address);
   
   printf("Enter subnet mask in decimal format:\n");
   scanf("%d", &subnet_mask);
   
   subnet_size = 32 - subnet_mask;
   
   printf("Subnet size: %d\n", subnet_size);
   
   int num_addresses = 1 << subnet_size;
   printf("Number of addresses per subnet: %d\n", num_addresses);
   
   int first_address = network_address >> subnet_size << subnet_size;
   printf("First address in subnet: %d\n", first_address);
   
   int last_address = first_address | (num_addresses - 1);
   printf("Last address in subnet: %d\n", last_address);

   printf("All addresses in subnet:\n");
   for (int i = 0; i < num_addresses; i++) {
      printf("%d\n", first_address + i);
   }

   return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>

int main() {
   unsigned int address;
   unsigned int prefix;

   printf("Welcome to the surprising subnet calculator!\n\n");

   printf("Please enter the IP address (a 32-bit decimal number): ");
   scanf("%u", &address);

   printf("Please enter the subnet mask (a prefix length): ");
   scanf("%u", &prefix);

   /* Calculate the subnet mask */
   unsigned int mask = 0xffffffff << (32 - prefix);

   /* Calculate the network address */
   unsigned int network = address & mask;

   /* Calculate the broadcast address */
   unsigned int broadcast = network | ~mask;

   /* Calculate the number of hosts */
   unsigned int hosts = (1 << (32 - prefix)) - 2;

   printf("\nWow! Here's your subnet info:\n\n");
   printf("Network address: %u.%u.%u.%u\n", (network >> 24) & 0xff, (network >> 16) & 0xff, (network >> 8) & 0xff, network & 0xff);
   printf("Broadcast address: %u.%u.%u.%u\n", (broadcast >> 24) & 0xff, (broadcast >> 16) & 0xff, (broadcast >> 8) & 0xff, broadcast & 0xff);
   printf("Number of hosts: %u\n\n", hosts);
   
   printf("Whoa! That was a pretty fun ride, wasn't it? Keep subnetting like a pro!\n");

   return 0;
}
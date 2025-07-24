//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
   unsigned long ip_add, subnet_mask, network_add, host_add, broadcast_add;
   int num_subnet_bits=0, num_host_bits=0;
   char c;

   printf("Welcome to the C Subnet Calculator!\n");
   printf("Please enter your IP address in dot-decimal notation followed by '/': ");
   scanf("%lu", &ip_add);
   scanf("%c", &c);

   printf("Please enter the subnet mask in dot-decimal notation followed by '/': ");
   scanf("%lu", &subnet_mask);
   scanf("%c", &c);

   // Count the number of subnet bits
   unsigned long temp_mask = subnet_mask;
   while(temp_mask != 0)
   {
       num_subnet_bits++;
       temp_mask = temp_mask >> 1;
   }

   // Calculate the number of host bits
   num_host_bits = 32 - num_subnet_bits;

   // Calculate the network address
   network_add = ip_add & subnet_mask;

   // Calculate the host address
   host_add = ip_add & (~subnet_mask);

   // Calculate the broadcast address
   broadcast_add = network_add | (~subnet_mask);

   // Output the results
   printf("Your IP address is: %lu.%lu.%lu.%lu\n", (ip_add >> 24) & 0xFF, (ip_add >> 16) & 0xFF, (ip_add >> 8) & 0xFF, ip_add & 0xFF);
   printf("Your subnet mask is: %lu.%lu.%lu.%lu\n", (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);
   printf("Your network address is: %lu.%lu.%lu.%lu\n", (network_add >> 24) & 0xFF, (network_add >> 16) & 0xFF, (network_add >> 8) & 0xFF, network_add & 0xFF);
   printf("Your host address is: %lu.%lu.%lu.%lu\n", (host_add >> 24) & 0xFF, (host_add >> 16) & 0xFF, (host_add >> 8) & 0xFF, host_add & 0xFF);
   printf("Your broadcast address is: %lu.%lu.%lu.%lu\n", (broadcast_add >> 24) & 0xFF, (broadcast_add >> 16) & 0xFF, (broadcast_add >> 8) & 0xFF, broadcast_add & 0xFF);
   printf("Your subnet contains %ld host addresses\n", (1 << num_host_bits) - 2);

   return 0;
}
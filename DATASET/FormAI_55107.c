//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>

int main() {
   char network_address[15];
   int subnet_bits;

   printf("Enter network address (e.g. 192.168.0.0): ");
   scanf("%s", network_address);

   printf("Enter number of subnet bits (e.g. 24): ");
   scanf("%d", &subnet_bits);

   // split IP address into octets
   int octet1, octet2, octet3, octet4;
   sscanf(network_address, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

   // calculate subnet mask
   int subnet_mask = 0xffffffff << (32 - subnet_bits);

   // calculate network address
   int network = (octet1 << 24) + (octet2 << 16) + (octet3 << 8) + octet4;
   int network_address_int = network & subnet_mask;

   // calculate broadcast address
   int broadcast_address_int = network_address_int + ~subnet_mask;

   // calculate host range
   int host_min = network_address_int + 1;
   int host_max = broadcast_address_int - 1;

   // convert integers back to IP address format
   sprintf(network_address, "%d.%d.%d.%d", (network_address_int >> 24) & 0xff, (network_address_int >> 16) & 0xff, (network_address_int >> 8) & 0xff, network_address_int & 0xff);
   sprintf(network_address, "%d.%d.%d.%d", (broadcast_address_int >> 24) & 0xff, (broadcast_address_int >> 16) & 0xff, (broadcast_address_int >> 8) & 0xff, broadcast_address_int & 0xff);
   sprintf(network_address, "%d.%d.%d.%d", (host_min >> 24) & 0xff, (host_min >> 16) & 0xff, (host_min >> 8) & 0xff, host_min & 0xff);
   sprintf(network_address, "%d.%d.%d.%d", (host_max >> 24) & 0xff, (host_max >> 16) & 0xff, (host_max >> 8) & 0xff, host_max & 0xff);

   // print results
   printf("\nNetwork Address: %s\n", network_address);
   printf("Broadcast Address: %s\n", network_address);
   printf("Host Range: %s - %s\n", network_address, network_address);

   return 0;
}
//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main() {
   long int decimal, binaryNumber = 0, j = 1, remainder;
   int subnets, prefix, subnetBits, addressBits, hosts, networkAddress, i;

   printf("Enter the Decimal IP Address: ");
   scanf("%ld", &decimal);

   char binary[32];
   sprintf(binary, "%ld", decimal);

   while (decimal != 0) {
      remainder = decimal % 2;
      decimal = decimal / 2;
      binaryNumber = binaryNumber + (remainder * j);
      j = j * 10;
   }
   printf("\nThe Binary representation of the IP Address is: %ld\n", binaryNumber);

   printf("\nEnter the Number of Subnets: ");
   scanf("%d", &subnets);

   //Calculate the Required Prefix for the Given Number of Subnets
   subnetBits = ceil(log2(subnets));
   prefix = 32 - subnetBits;
   printf("\nPrefix/Netmask: /%d", prefix);

   //Calculate the Number of Hosts Per Subnet
   addressBits = 32 - prefix;
   hosts = (int)(pow(2, addressBits)) - 2;
   printf("\nNumber of Hosts per Subnet: %d\n", hosts);

   //Calculating the Network Address and Broadcast Address for Each Subnet
   for (i = 1; i <= subnets; i++) {
      printf("\n\nSubnet %d:\n", i);

      //Calculating Network Address
      networkAddress = (i - 1) * hosts;
      printf("Network Address: %ld.%ld.%ld.%d\n",
             networkAddress / (256 * 256 * 256),
             (networkAddress / (256 * 256)) % 256,
             (networkAddress / 256) % 256,
             networkAddress % 256);

      //Calculating Broadcast Address
      printf("Broadcast Address: %ld.%ld.%ld.%d\n",
             (networkAddress + hosts) / (256 * 256 * 256),
             ((networkAddress + hosts) / (256 * 256)) % 256,
             ((networkAddress + hosts) / 256) % 256,
             (networkAddress + hosts) % 256);
   }

   return 0;
}
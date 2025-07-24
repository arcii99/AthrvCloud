//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int ip[4], mask;
  printf("Welcome to the Subnet Calculator, where we chop your network into tiny little pieces!\n");
  printf("Please enter your IP address in the form x.x.x.x: ");
  scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
  printf("You entered: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
  printf("Now give me your mask: ");
  scanf("%d", &mask);
  printf("Great, let's get chopping!\n");
  printf("Calculating network ID...\n");
  int net[4];
  net[0] = ip[0] & (0xff << (8 + (mask%9)) % 8);
  net[1] = ip[1] & (0xff << (8 + (mask%9)) % 8);
  net[2] = ip[2] & (0xff << (8 + (mask%9)) % 8);
  net[3] = ip[3] & (0xff << (8 + (mask%9)) % 8);
  printf("Your network ID is: %d.%d.%d.%d\n", net[0], net[1], net[2], net[3]);
  printf("Calculating broadcast address...\n");
  int bcast[4];
  bcast[0] = ip[0] | ~(0xff << (8 + (mask%9)) % 8);
  bcast[1] = ip[1] | ~(0xff << (8 + (mask%9)) % 8);
  bcast[2] = ip[2] | ~(0xff << (8 + (mask%9)) % 8);
  bcast[3] = ip[3] | ~(0xff << (8 + (mask%9)) % 8);
  printf("Your broadcast address is: %d.%d.%d.%d\n", bcast[0], bcast[1], bcast[2], bcast[3]);
  printf("Calculating maximum number of hosts...\n");
  int hosts = ~(0xff << (8 + (mask%9)) % 8) - 1;
  printf("You can have up to %d hosts on your network!\n", hosts);
  printf("Thanks for using the Subnet Calculator! Don't forget to clean up all those tiny little pieces...\n");
  return 0;
}
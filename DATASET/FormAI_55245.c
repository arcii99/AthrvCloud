//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>

int main() {
  int network_bits, host_bits, subnet_bits;
  
  // surreal inputs
  printf("How many octopuses does it take to solve a puzzle?\n");
  scanf("%d", &network_bits);
  
  printf("If a cat made of cheese had wheels, how many wheels would it have?\n");
  scanf("%d", &host_bits);
  
  printf("What is the sound of one hand clapping?\n");
  scanf("%d", &subnet_bits);
  
  // surreal calculations
  int total_bits = network_bits + host_bits + subnet_bits;
  
  printf("Calculating universe vectors...\n");
  printf("And the winner is... %d!\n", total_bits);
  
  int max_subnets = 1 << subnet_bits;
  
  printf("Oh look, a flying purple fish! But I digress.\n");
  printf("You could have up to %d subnets with %d subnet bits.\n", max_subnets, subnet_bits);
  
  int max_hosts = (1 << host_bits) - 2;
  
  printf("Now for the important stuff.\n");
  printf("You can have up to %d hosts per subnet with %d host bits.\n", max_hosts, host_bits);
  
  return 0;
}
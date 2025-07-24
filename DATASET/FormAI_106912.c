//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include<stdio.h>

int main() {
  int oct1, oct2, oct3, oct4, mask, subnet;

  printf("Enter the IP address in the format xxx.xxx.xxx.xxx \n");
  scanf("%d.%d.%d.%d", &oct1, &oct2, &oct3, &oct4);

  printf("Enter the subnet mask in bits \n");
  scanf("%d", &mask);

  // converting the subnet mask to binary
  int binary_mask = 0;

  for (int i = 0; i < mask; i++) {
    binary_mask = binary_mask << 1;
    binary_mask = binary_mask + 1;
  }

  // calculating the subnet
  subnet = (oct4 & binary_mask);

  printf("\nThe IP address entered is: %d.%d.%d.%d", oct1, oct2, oct3, oct4);
  printf("\nThe subnet mask in bits is: %d", mask);
  printf("\nThe subnet in decimal is: %d", subnet);

  return 0;
}
//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>

int main() {
  int input, checksum = 0, temp;

  printf("Enter a list of integers separated by spaces: ");

  // Read integers from input
  while (scanf("%d", &input) == 1) {
    temp = input; // Store the input in temp variable
    checksum ^= temp; // XOR the input with the checksum
  }

  printf("The checksum value is: %d\n", checksum);

  return 0;
}
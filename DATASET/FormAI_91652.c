//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shocked
#include <stdio.h>

int main() {
  int num, sum = 0;
  printf("Enter the numbers separated by spaces: ");

  // Scanning the numbers from the user
  while (scanf("%d", &num) == 1) {
    sum += num;
  }

  // Calculating the Checksum
  int checksum = sum % 256;

  // Printing the checksum
  printf("The checksum value is %d\n", checksum);

  return 0;
}
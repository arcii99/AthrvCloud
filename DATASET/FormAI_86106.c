//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables
  int num = 0;
  int sum = 0;

  // Get input from user
  printf("Enter a number: ");
  scanf("%d", &num);

  // Calculate checksum
  while (num > 0) {
    sum += num % 10;
    num /= 10;

    if (num == 0 && sum > 9) {
      num = sum;
      sum = 0;
    }
  }

  // Output checksum
  printf("Checksum: %d\n", sum);

  return 0;
}
//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>

int main() {
  int num, sum = 0, i, flag = 1;
  printf("Enter a number: ");
  scanf("%d", &num);

  while(num != 0) {
    int digit = num % 10;
    sum += digit * flag;
    flag *= -1;
    num /= 10;
  }

  printf("The checksum for the given number is: %d\n", sum);
  return 0;
}
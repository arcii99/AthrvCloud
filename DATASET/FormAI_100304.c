//FormAI DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>

int main() {
  int num;
  printf("Enter an integer: ");
  scanf("%d", &num);

  if(num < 0) {
    printf("Error: Integer must be positive.\n");
    return 0;
  }

  int sum = 0;
  for(int i = 1; i <= num; i++) {
    sum += i;
  }

  printf("The sum of all integers from 1 to %d is %d.\n", num, sum);

  return 0;
}